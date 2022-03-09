#include <iostream>
#include "./sudoku/sudoku.hpp"



int main() {
    std::vector< std::vector<int> > board;
    for(int i = 0; i < 9; ++i) {
        std::vector<int> row;
        for(int j = 1; j <= 9; ++j) {
            row.push_back(j);
        }
        board.push_back(row);
    }

    Sudoku game(board);
    game.print_board();


    return 0;


}