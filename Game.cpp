// Game.cpp
#include "Game.h"
#include "Grid.h"
#include <iostream>
#include <algorithm>

Game::Game(Grid* grid, int connectN, int targetScore)
    : grid(grid), connectN(connectN), targetScore(targetScore) {
    players = {
        new Player("Player 1", YELLOW),
        new Player("Player 2", RED)
    };
    for (Player* player : players) {
        score[player->getName()] = 0;
    }
}

void Game::printBoard() {
    std::cout << "Board:" << std::endl;
    std::vector<std::vector<int>> g = grid->getGrid();
    for (const auto& row : g) {
        for (int piece : row) {
            char c = (piece == EMPTY) ? '0' : (piece == YELLOW) ? 'Y' : 'R';
            std::cout << c << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

std::vector<int> Game::playMove(Player* player) {
    printBoard();
    std::cout << player->getName() << "'s turn\nEnter column: ";
    int moveColumn;
    std::cin >> moveColumn;
    int moveRow = grid->placePiece(moveColumn, player->getPieceColor());
    return { moveRow, moveColumn };
}

Player* Game::playRound() {
    while (true) {
        for (Player* player : players) {
            std::vector<int> pos = playMove(player);
            int row = pos[0];
            int col = pos[1];
            if (grid->checkWin(connectN, row, col, player->getPieceColor())) {
                score[player->getName()]++;
                return player;
            }
        }
    }
}

void Game::play() {
    int maxScore = 0;
    Player* winner = nullptr;
    while (maxScore < targetScore) {
        winner = playRound();
        std::cout << winner->getName() << " won the round" << std::endl;
        maxScore = std::max(score[winner->getName()], maxScore);
        grid->initGrid();  // reset board
    }
    std::cout << winner->getName() << " won the game" << std::endl;
}
