// Grid.cpp
#include "Grid.h"
#include <stdexcept>

Grid::Grid(int rows, int columns) : rows(rows), columns(columns) {
    initGrid();
}

void Grid::initGrid() {
    grid = std::vector<std::vector<int>>(rows, std::vector<int>(columns, GridPosition::EMPTY));
}

std::vector<std::vector<int>> Grid::getGrid() {
    return grid;
}

int Grid::getColummnCount() {
    return columns;
}

int Grid::placePiece(int column, GridPosition piece) {
    if (column < 0 || column >= columns) throw "Invalid column";
    if (piece == GridPosition::EMPTY) throw "Invalid piece";

    for (int row = rows-1; row >= 0; row--) {
        if (grid[row][column] == GridPosition::EMPTY) {
            grid[row][column] = piece;
            return row;
        }
    }
    return -1;
}

bool Grid::checkWin(int connectN, int row, int col, GridPosition piece) {
    int count = 0;
    for (int c = 0; c < columns; c++) {
        count = (grid[row][c] == piece) ? count + 1 : 0;
        if (count == connectN) return true;
    }

    count = 0;
    for (int r = 0; r < rows; r++) {
        count = (grid[r][col] == piece) ? count + 1 : 0;
        if (count == connectN) return true;
    }

    count = 0;
    for (int r = 0; r < rows; r++) {
        int c = row + col - r;
        if (c >= 0 && c < columns && grid[r][c] == piece) count++;
        else count = 0;
        if (count == connectN) return true;
    }

    count = 0;
    for (int r = 0; r < rows; r++) {
        int c = col - row + r;
        if (c >= 0 && c < columns && grid[r][c] == piece) count++;
        else count = 0;
        if (count == connectN) return true;
    }
    return false;
}