#pragma once

#include "gameState.h"

class SettingsState : public GameState
{
public:
    SettingsState() {}
    ~SettingsState();
    virtual void init() final;
    virtual void handleInput() final;
    virtual void update() final;
    virtual void draw() final;

private:
    class Hud *hud;
};