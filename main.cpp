// main.cpp
#include "Grid.h"
#include "Game.h"

int main() {
    Grid* grid = new Grid(6, 7);
    Game* game = new Game(grid, 4, 10);
    game->play();
    delete game;
    delete grid;
    return 0;
}