#include "Sudoku.h"

Sudoku::Sudoku(const std::string& input) {
    grid.resize(GRID_SIZE, std::vector<int>(GRID_SIZE, 0));
    for (int i = 0; i < input.length(); i++) {
        int num = input[i] - '0';
        grid[i / GRID_SIZE][i % GRID_SIZE] = num;
    }
}

std::vector<std::vector<int>>& Sudoku::getGrid() {
    return grid;
}

std::vector<int> Sudoku::getRow(int row) {
    return grid[row];
}

std::vector<int> Sudoku::getColumn(int col) {
    std::vector<int> column(GRID_SIZE, 0);
    for (int i = 0; i < GRID_SIZE; i++) {
        column[i] = grid[i][col];
    }
    return column;
}

std::vector<int> Sudoku::getBox(int row, int col) {
    std::vector<int> box(BOX_SIZE * BOX_SIZE, 0);
    int index = 0;
    for (int i = 0; i < BOX_SIZE; i++) {
        for (int j = 0; j < BOX_SIZE; j++) {
            box[index++] = grid[row - row % BOX_SIZE + i][col - col % BOX_SIZE + j];
        }
    }
    return box;
}


bool Sudoku::isSafe(int row, int col, int num) {
    // Check row
    for (int j = 0; j < GRID_SIZE; j++) {
        if (grid[row][j] == num) return false;
    }
    // Check column
    for (int i = 0; i < GRID_SIZE; i++) {
        if (grid[i][col] == num) return false;
    }
    // Check box
    int startRow = row - row % BOX_SIZE, startCol = col - col % BOX_SIZE;
    for (int i = 0; i < BOX_SIZE; i++) {
        for (int j = 0; j < BOX_SIZE; j++) {
            if (grid[i + startRow][j + startCol] == num) return false;
        }
    }
    return true;
}

bool Sudoku::solve() {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            if (grid[i][j] == 0) {
                for (int num = 1; num <= 9; num++) {
                    if (isSafe(i, j, num)) {
                        grid[i][j] = num;
                        if (solve()) return true;
                        grid[i][j] = 0; // Backtrack
                    }
                }
                return false;
            }
        }
    }
    return true;
}

void Sudoku::fillCandidates() {
    // This is a placeholder for the actual candidate filling logic
    // For now, we'll just solve the Sudoku
    solve();
}