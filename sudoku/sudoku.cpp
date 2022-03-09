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
            for(int k = 0; k < Sudoku::board_[i].size()*3; ++k){
                std::cout << "-";
            }
            std::cout << "\n";
        }

        
    }

}

bool Sudoku::is_valid() {
    return Sudoku::is_row_valid() && Sudoku::is_column_valid() && Sudoku::is_block_valid();
}

bool Sudoku::is_row_valid() {
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

bool Sudoku::is_column_valid() {
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

bool Sudoku::is_block_valid() {
    return true;
}

void Sudoku::solve() {
    return ;
}

