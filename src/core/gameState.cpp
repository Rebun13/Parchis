#include "gameState.h"
#include "raylib.h"
#include "./game.h"
#include "menus/MainMenu.h"

MenuState::~MenuState()
{
    delete menu;
}

void MenuState::init()
{
    menu = new MainMenu();
}

void MenuState::handleInput(Vector2 coord, Game &game)
{
    unsigned char pressedButton = menu->onTouch(coord);
    switch (pressedButton)
    {
    case MainMenu::PLAY_BUTTON:
        game.state_ = &Game::playing;
        break;
    case MainMenu::SETTINGS_BUTTON:
        game.state_ = &Game::settings;
        break;
    case MainMenu::EXIT_BUTTON:
        // TODO: close game
        break;
    default:
        // ?
        break;
    }
}

void MenuState::update(Game &game)
{
    // TODO
}

void MenuState::draw()
{
    if(!menu) {
        init();
    }
    menu->draw();
}
