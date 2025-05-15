#pragma once

#include "gameState.h"
#include <memory>

class MenuState : public GameState
{
public:
    MenuState();
    ~MenuState();
    virtual GameState* handleInput() final;
    virtual void update() final;
    virtual void draw() final;

private:
    std::unique_ptr<class Hud> hud;
};