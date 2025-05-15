#pragma once

#include <vector>
#include <memory>
#include "gameObjects/board.h"
#include "gameObjects/player.h"
#include "core/gameState/gameState.h"

class GameMode
{
public:
    GameMode() {}
    ~GameMode() {
        board.reset();
        for (std::unique_ptr<Player> &player : players)
        {
            player.reset();
        }
        players.clear();
    }

    virtual void init() = 0;
    virtual void update() = 0;
    virtual void draw() = 0;
    virtual std::shared_ptr<GameState> handleInput() = 0;
    bool gameStarted;
protected:
    std::unique_ptr<Board> board;
    std::vector<std::unique_ptr<Player>> players;
};