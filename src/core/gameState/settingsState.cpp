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

void SettingsState::handleInput(Vector2 coord, Game &game)
{
}

void SettingsState::update(Game &game)
{
    unsigned char pressedButton = hud->onTouch();
    switch (pressedButton)
    {
    case SettingsHud::SAVE_BUTTON:
        game.saveSettings(); // Not implemented yet
        break;
    case SettingsHud::EXIT_BUTTON:
        game.state_ = game.prevState;
        game.state_->init();
        game.prevState = this;
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
