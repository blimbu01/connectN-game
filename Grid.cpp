#include <vector>
#include "GridPosition.h"

using namespace std;

class Grid {
private:
    int rows;
    int columns;
    vector<vector<GridPosition>> grid;

public:
    Grid(int rows, int columns) : rows(rows), columns(columns) {
        initGrid();
    }

    void initGrid() {
        grid = vector<vector<GridPosition>>(rows, vector<GridPosition>(columns, GridPosition::EMPTY));
    }

    const vector<vector<GridPosition>>& getGrid() const {
        return grid;
    }

    int getColumnCount() const {
        return columns;
    }

    int placePiece(int column, GridPosition piece) {
        if (column < 0 || column >= columns) {
            throw std::runtime_error("Invalid column");
        }q
        if (piece == GridPosition::EMPTY) {
            throw std::runtime_error("Invalid piece");
        }
        for (int row = rows - 1; row >= 0; row--) {
            if (grid[row][column] == GridPosition::EMPTY) {
                grid[row][column] = piece;
                return row;
            }
        }
        return -1;
    }

    bool checkWin(int connectN, int row, int col, GridPosition piece) {
        // Check horizontal
        int count = 0;
        for (int c = 0; c < this->columns; c++) {
            if (this->grid[row][c] == piece) {
                count++;
            } else {
                count = 0;
            }
            if (count == connectN) {
                return true;
            }
        }

        // Check vertical
        count = 0;
        for (int r = 0; r < this->rows; r++) {
            if (this->grid[r][col] == piece) {
                count++;
            } else {
                count = 0;
            }
            if (count == connectN) {
                return true;
            }
        }

        // Check diagonal
        count = 0;
        for (int r = 0; r < this->rows; r++) {
            int c = row + col - r; // row + col = r + c, for a diagonal
            if (c >= 0 && c < this->columns && this->grid[r][c] == piece) {
                count++;
            } else {
                count = 0;
            }
            if (count == connectN) {
                return true;
            }
        }

        // Check anti-diagonal
        count = 0;
        for (int r = 0; r < this->rows; r++) {
            int c = col - row + r; // row - col = r - c, for an anti-diagonal
            if (c >= 0 && c < this->columns && this->grid[r][c] == piece) {
                count++;
            } else {
                count = 0;
            }
            if (count == connectN) {
                return true;
            }
        }
        return false;
    }
};
