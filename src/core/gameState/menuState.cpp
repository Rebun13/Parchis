#include "menuState.h"
#include "hud/menuHud.h"
#include "core/game.h"

MenuState::~MenuState()
{
    delete hud;
}

void MenuState::init()
{
    hud = new MenuHud();
}

void MenuState::handleInput(Vector2 coord, Game &game)
{
}

void MenuState::update(Game &game)
{
    unsigned char pressedButton = hud->onTouch();
    switch (pressedButton)
    {
    case MenuHud::PLAY_BUTTON:
        game.state_ = &Game::playing;
        game.state_->init();
        game.prevState = this;
        break;
    case MenuHud::SETTINGS_BUTTON:
        game.state_ = &Game::settings;
        game.state_->init();
        game.prevState = this;
        break;
    case MenuHud::EXIT_BUTTON:
        game.setClose_();
        break;
    default:
        break;
    }
}

void MenuState::draw()
{
    if (!hud)
    {
        init();
    }
    hud->draw();
}