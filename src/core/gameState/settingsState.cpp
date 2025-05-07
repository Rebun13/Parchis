#include "settingsState.h"
#include "core/game.h"
#include "hud/settingsHud.h"


void SettingsState::init()
{
    hud = new SettingsHud();
}

SettingsState::~SettingsState()
{
    delete hud;
}

void SettingsState::handleInput()
{
}

void SettingsState::update()
{
    std::unique_ptr<GameInterface> game = Game::getGameInstance();
    unsigned char pressedButton = hud->onTouch();
    switch (pressedButton)
    {
    case SettingsHud::SAVE_BUTTON:
        game->saveSettings(); // Not implemented yet
        break;
    case SettingsHud::EXIT_BUTTON:
        game->setState(Game::menu);
        break;
    default:
        // ?
        break;
    }
}

void SettingsState::draw()
{
    if (!hud)
    {
        init();
    }
    hud->draw();
}
