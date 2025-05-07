#pragma once

#include "gameState.h"

class MenuState : public GameState
{
public:
    MenuState() {}
    ~MenuState();
    virtual void init() final;
    virtual void handleInput() final;
    virtual void update() final;
    virtual void draw() final;

private:
    class Hud *hud;
};