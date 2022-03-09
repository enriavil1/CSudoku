#include <vector>

class Sudoku
{
public:
    Sudoku(std::vector< std::vector<int> >& board): board_(board), row(0), col(0) {}
    ~Sudoku() {};
    void print_board();
    bool solve();

    bool is_board_valid();
    bool are_rows_valid();
    bool are_columns_valid();
    bool are_blocks_valid();

    bool find_empty_spot();
    bool is_valid_place(int row, int col, int& num);
    bool is_row_valid(int col, int& num);
    bool is_column_valid(int row, int& num);
    bool is_block_valid(int row, int col, int& num);

    

private:
    std::vector< std::vector<int> >& board_;
    int row;
    int col;
};

