#include <vector>
#include <iostream>
#include <map>
#include "sudoku.hpp"


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

bool Sudoku::find_empty_spot() {
    for(int i = 0; i < Sudoku::board_.size(); ++i) {
        for(int j = 0; j < Sudoku::board_.size(); ++j) {
            if(Sudoku::board_[i][j] == 0 ){
                return true;
            }
        }
    }
    return false;
}

bool Sudoku::is_row_valid(int& num) {
    for(Sudoku::col = 0; Sudoku::col < 9; ++Sudoku::col){
        if(Sudoku::board_[Sudoku::row][Sudoku::col] == num){
            return false;
        }
    }
    return true;
}


bool Sudoku::solve() {
    Sudoku::print_board();

    if(!Sudoku::find_empty_spot()){
        Sudoku::print_board();
        std::cout << "\nBOARD HAS BEEN COMPLETES\n";
        return true;
    }

    for(int num = 1; num < 9; ++num) {
        if(Sudoku::is_valid_place(num)){
            Sudoku::board_[Sudoku::row][Sudoku::col] = num;

            if(Sudoku::solve()){
                return true;
            }

            Sudoku::board_[Sudoku::row][Sudoku::col] = 0;
        }
    }
    return false;
}

