#include "gameState.h"
#include "raylib.h"
#include "./game.h"
#include "menus/mainMenu.h"
#include "menus/settingsMenu.h"
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
        game.setClose_();
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
    if (!menu)
    {
        init();
    }
    menu->draw();
}

void SettingsState::init()
{
    menu = new SettingsMenu();
}

SettingsState::~SettingsState()
{
    delete menu;
}

void SettingsState::handleInput(Vector2 coord, Game &game)
{
    unsigned char pressedButton = menu->onTouch(coord);
    switch (pressedButton)
    {
    case SettingsMenu::SAVE_BUTTON:
        game.saveSettings(); // Not implemented yet
        break;
    case SettingsMenu::EXIT_BUTTON:
        game.state_ = &Game::menu;
        break;
    default:
        // ?
        break;
    }
}

void SettingsState::update(Game &game)
{
}

void SettingsState::draw()
{
    if (!menu)
    {
        init();
    }
    menu->draw();
}
