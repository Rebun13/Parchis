#include "menuState.h"
#include "hud/hud.h"
#include "hud/menuHud.h"
#include "core/game.h"
#include <memory>

MenuState::~MenuState()
{
    delete hud;
}

void MenuState::init()
{
    hud = new MenuHud();
}

void MenuState::handleInput()
{
}

void MenuState::update()
{
    std::shared_ptr<GameInterface> game = Game::getGameInstance();
    unsigned char pressedButton = hud->onTouch();
    switch (pressedButton)
    {
    case MenuHud::PLAY_BUTTON:
        game->setState(Game::playing);
        break;
    case MenuHud::SETTINGS_BUTTON:
        game->setState(Game::settings);
        break;
    case MenuHud::EXIT_BUTTON:
        game->setClose_();
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