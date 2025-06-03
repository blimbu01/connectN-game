// Game.h
#pragma once

#include <vector>
#include <unordered_map>
#include <string>
#include "Player.h"
#include "Grid.h"

class Game {
private:
    Grid* grid;
    int connectN;
    std::vector<Player*> players;
    std::unordered_map<std::string, int> score;
    int targetScore;

    void printBoard();
    std::vector<int> playMove(Player* player);
    Player* playRound();

public:
    Game(Grid* grid, int connectN, int targetScore);
    void play();
};
