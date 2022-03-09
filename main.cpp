#include <iostream>
#include "./sudoku/sudoku.hpp"



int main() {
    int board[9][9] = {
        {3,0,6,5,0,8,4,0,0},
        {5,2,0,0,0,0,0,0,0},
        {0,8,7,0,0,0,0,3,1},
        {0,0,3,0,1,0,0,8,0},
        {9,0,0,8,6,3,0,0,5},
        {0,5,0,0,9,0,6,0,0},
        {1,3,0,0,0,0,2,5,0},
        {0,0,0,0,0,0,0,7,4},
        {0,0,5,2,0,6,3,0,0}
    };

    Sudoku game(board);
    std::cout << "\n!!!!STARTING BOARD!!!!\n";
    game.print_board();


    bool solve = game.solve();
    if(solve) {
        std::cout << "\n!!!!BOARD HAS BEEN SOLVED!!!!\n";
    }
    else {
        std::cout << "\n<<<<BOARD CANNOT BE SOLVED>>>>\n";
    }

    game.print_board();

    return 0;
}