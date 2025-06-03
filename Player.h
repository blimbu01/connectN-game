// Player.h
#pragma once
#include <string>
#include "Grid.h"

class Player {
private:
    std::string name;
    GridPosition piece;

public:
    Player(std::string name, GridPosition piece);
    std::string getName();
    GridPosition getPieceColor();
};