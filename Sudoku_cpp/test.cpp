#include "Sudoku.h"
#include <cassert>

int main() {
    std::string input = "017903600000080000900000507072010430000402070064370250701000065000030000005601720";
    Sudoku sudoku(input);

    std::vector<std::vector<int>> grid = sudoku.getGrid();
    assert(grid[0][0] == 0);
    assert(grid[8][8] == 0);

    std::vector<int> row = sudoku.getRow(0);
    std::vector<int> expectedRow = {0, 1, 7, 9, 0, 3, 6, 0, 0};
    assert(row == expectedRow);
    
    std::vector<int> expectedCol = {0, 0, 9, 0, 0, 0, 7, 0, 0};
    std::vector<int> col = sudoku.getColumn(0);
    assert(col == expectedCol);
    
    std::vector<int> expectedBox = {0, 1, 7, 0, 0, 0, 9, 0, 0};
    std::vector<int> box = sudoku.getBox(0, 0);
    assert(box == expectedBox);
    



    assert(sudoku.solve()==true);

    std::cout << "All tests passed!" << std::endl;
    return 0;
}