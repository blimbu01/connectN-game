// Player.cpp
#include "Player.h"
#include "Grid.h"

Player::Player(std::string name, GridPosition piece) : name(name), piece(piece) {}

std::string Player::getName() {
    return name;
}

GridPosition Player::getPieceColor() {
    return piece;
}