#pragma once

#include "gameState.h"

class SettingsState : public GameState
{
public:
    SettingsState() {}
    ~SettingsState();
    void init() override;
    void handleInput(Vector2 coord, Game &game) override;
    void update(Game &game) override;
    void draw() override;

private:
    Hud *hud;
};