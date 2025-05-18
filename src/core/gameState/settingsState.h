#pragma once

#include "gameState.h"
#include "hud/hud.h"
#include <memory>

class SettingsState : public GameState
{
public:
    SettingsState();
    virtual GameState* handleInput() final;
    virtual void update() final;
    virtual void draw() final;
private:
    std::unique_ptr<Hud> hud;
};