#include <vector>

class Sudoku
{
public:

    Sudoku(int board[9][9]);
    ~Sudoku() {};
    void print_board();
    bool solve();

    bool is_board_valid();
    bool are_rows_valid();
    bool are_columns_valid();
    bool are_blocks_valid();

    bool find_empty_spot(int& row, int& col);
    bool is_valid_place(const int& row, const int& col, const int& num);
    bool is_row_valid(const int&row, const int& num);
    bool is_column_valid(const int& col, const int& num);
    bool is_block_valid(const int& row, const int& col, const int& num);

    

private:
    std::vector< std::vector<int> > board_;
};

