#pragma once

#include "gameState.h"

class PlayingState : public GameState
{
public:
    PlayingState();
    ~PlayingState();
    void init() override;
    void handleInput(Vector2 coord, Game &game) override;
    // void handleNetwork();
    void update(Game &game) override;
    void draw() override;

private:
    class Hud *hud;
    class GameMode *gamemode;
    std::vector<std::unique_ptr<class Player>> players;
    // double tick_dt;
    // class Client *gameClient;
};