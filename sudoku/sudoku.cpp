#include <vector>
#include <iostream>
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

bool Sudoku::isValid() {
    return false;
}

void Sudoku::solve() {
    return ;
}

