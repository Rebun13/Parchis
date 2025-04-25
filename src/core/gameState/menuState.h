#pragma once

#include "gameState.h"

class MenuState : public GameState
{
public:
    MenuState() {}
    ~MenuState();
    void init();
    void handleInput(Vector2 coord, Game &game) override;
    void update(Game &game) override;
    void draw() override;

private:
    Hud *hud;
};