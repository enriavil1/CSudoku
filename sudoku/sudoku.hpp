#include <vector>

class Sudoku
{
public:
    Sudoku(std::vector<std::vector<int> >& board): board_(board) {}
    ~Sudoku() {};
    void print_board();
    void solve();

    bool is_valid();
    bool is_row_valid();
    bool is_column_valid();
    bool is_block_valid();

    

private:
    std::vector<std::vector<int> >& board_;

};

