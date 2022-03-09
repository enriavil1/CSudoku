#include <vector>
#include <iostream>
#include <map>
#include "sudoku.hpp"


Sudoku::Sudoku(int board[9][9]) {
    for(int i = 0; i < 9; ++i)  {
        std::vector<int> row;
        for(int j = 0; j < 9; ++j)   {
            row.push_back(board[i][j]);
        }
        board_.push_back(row);
    }
}

// prints out sudoku board
void Sudoku::print_board() {
    for(int k = 0; k < Sudoku::board_[0].size()*3; ++k){
        std::cout << "-";
    }
    std::cout << "\n";

    for(int i = 0; i < Sudoku::board_.size(); ++i) {
        for(int j = 0; j < Sudoku::board_[i].size(); ++j) {

            // every three columns it will add a bar between the number boards
            if(j%3 == 0){
                std::cout << "| ";
            }
            std::cout << Sudoku::board_[i][j] << " ";

        }

        std::cout << "|\n";
        // every three rows it will add a line beetwen the rows
        if((i+1)%3==0){
            for(int k = 0; k < Sudoku::board_[i].size(); ++k){
                std::cout << "---";
            }
            std::cout << "\n";
        }
    }
}

bool Sudoku::is_board_valid() {
    bool is_valid = Sudoku::are_rows_valid() && Sudoku::are_columns_valid() && Sudoku::are_blocks_valid();

    if(!is_valid) {
        std::cout << "BOARD IS NOT VALID\n";
        Sudoku::~Sudoku();
    }

    return Sudoku::are_rows_valid() && Sudoku::are_columns_valid() && Sudoku::are_blocks_valid();
}

bool Sudoku::are_rows_valid() {
    for(int i = 0; i < Sudoku::board_.size(); ++i){
        std::map<int, bool> row;
        for(int j = 0; j < Sudoku::board_[i].size(); ++j){
            if(row[Sudoku::board_[i][j]]){
                return false;
            }
            row[Sudoku::board_[i][j]] = true;
        }
    }
    return true;
}

bool Sudoku::are_columns_valid() {
    for(int i = 0; i < Sudoku::board_.size(); ++i) {
        std::map<int, bool> column;
        for(int j = 0; j < Sudoku::board_.size(); ++j) {
            if(column[Sudoku::board_[j][i]]){
                return false;
            }

            column[Sudoku::board_[j][i]] = true;
        }
    }
    return true;
}

bool Sudoku::are_blocks_valid() {
    return true;
}

// finds empty spot to add number into
bool Sudoku::find_empty_spot(int& row, int& col) {
    for(row = 0; row < Sudoku::board_.size(); ++row) {
        for(col = 0; col < Sudoku::board_.size(); ++col) {
            if(Sudoku::board_[row][col] == 0 ){
                return true;
            }
        }
    }
    return false;
}

bool Sudoku::is_valid_place(const int& row, const int& col, const int& num) {
    return Sudoku::is_row_valid(row, num) && Sudoku::is_column_valid(col, num) && Sudoku::is_block_valid(row-row%3, col-col%3, num);
}

bool Sudoku::is_row_valid(const int& row, const int& num) {
    for(int col = 0; col < 9; ++col) {
        if(Sudoku::board_[row][col] == num) {
            return false;
        }
    }
    return true;
}

bool Sudoku::is_column_valid(const int& col, const int& num) {
    for(int row = 0; row < 9; ++row) {
        if(Sudoku::board_[row][col] == num) {
            return false;
        }
    }
    return true;
}

// check if block is valid
bool Sudoku::is_block_valid(const int& row, const int& col, const int& num) {
    for(int i = 0; i < 3; ++i) {
        for(int j = 0; j < 3; ++j) {
            if(Sudoku::board_[i+row][j+col] == num) {
                return false;
            }
        } 
    }
    return true;
}

// solves the board using DFS 
bool Sudoku::solve() {
    int row, col;
    if(!Sudoku::find_empty_spot(row, col)){
        Sudoku::print_board();
        return true;
    }
    // checks all possible numbers
    for(int num = 1; num <= 9; ++num) {
        if(Sudoku::is_valid_place(row, col, num)) {
            Sudoku::board_[row][col] = num;

            // if recursive stack is true then we are done    
            if(Sudoku::solve()){
                return true;
            }
            
            // set it back to zero while moving back up or trying another num
            Sudoku::board_[row][col] = 0;
        }
    }

    return false;
}

