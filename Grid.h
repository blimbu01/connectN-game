//Grid.h
#pragma once
#include <vector>

enum GridPosition {
    EMPTY, YELLOW, RED
};

class Grid {
    private:
        int rows;
        int columns;
        std::vector<std::vector<int>> grid;

    public:
        Grid(int rows, int columns);
        void initGrid();
        std::vector<std::vector<int>> getGrid();
        int getColummnCount();
        int placePiece(int column, GridPosition piece);
        bool checkWin(int connectN, int row, int col, GridPosition piece);
};