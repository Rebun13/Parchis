#pragma once

#include <vector>
#include <memory>
#include "gameObjects/board.h"
#include "gameObjects/player.h"

class GameMode
{
public:
    ~GameMode() {
        delete board;
        for (std::unique_ptr<Player> &player : players)
        {
            player.reset();
        }
        players.clear();
    }

    virtual void init() = 0;
    virtual void update() = 0;
    virtual void draw() = 0;
    virtual void handleInput() = 0;
    bool gameStarted;
protected:
    Board *board;
    std::vector<std::unique_ptr<Player>> players;
};