#include <vector>

class Sudoku
{
public:
    Sudoku(std::vector<std::vector<int> >& board): board_(board) {}
    ~Sudoku() {};
    void print_board();
    void solve();
    bool isValid();
    

private:
    std::vector<std::vector<int> >& board_;

};

