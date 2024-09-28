#ifndef SUDOKU_H
#define SUDOKU_H

#include <vector>
#include <string>
#include <iostream>

class Sudoku {
private:
    std::vector<std::vector<int>> grid;
    const int BOX_SIZE = 3;
    const int GRID_SIZE = 9;

public:
    Sudoku(const std::string& input);
    std::vector<std::vector<int>>& getGrid();
    std::vector<int> getRow(int row);
    std::vector<int> getColumn(int col);
    std::vector<int> getBox(int row, int col);
    bool isSafe(int row, int col, int num);
    bool solve();
    void fillCandidates();
};

#endif // SUDOKU_H