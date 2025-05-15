#include "settingsState.h"
#include "core/game.h"
#include "core/gameState/menuState.h"
#include "hud/settingsHud.h"


SettingsState::SettingsState()
{
    hud = std::make_unique<SettingsHud>();
}

SettingsState::~SettingsState()
{
    hud.reset();
}

GameState* SettingsState::handleInput()
{
    unsigned char pressedButton = hud->handleInput();
    switch (pressedButton)
    {
    case SettingsHud::SAVE_BUTTON:
        // save settings
        return nullptr;
    case SettingsHud::EXIT_BUTTON:
        return new MenuState();
    default:
        // ?
        return nullptr;
    }
}

void SettingsState::update()
{
}   

void SettingsState::draw()
{
    hud->draw();
}
