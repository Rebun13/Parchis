#pragma once

#include "gameState.h"

class PlayingState : public GameState
{
public:
    PlayingState();
    ~PlayingState();
    void init() final;
    void handleInput() final;
    // void handleNetwork();
    void update() final;
    void draw() final;

private:
    class Hud *hud;
    class GameMode *gamemode;
};