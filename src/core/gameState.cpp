#include "gameState.h"
#include "raylib.h"
#include "./game.h"
#include "menus/mainMenu.h"
#include "menus/settingsMenu.h"
#include "gameObjects/board.h"

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
    
}

void MenuState::update(Game &game)
{
    unsigned char pressedButton = menu->onTouch();
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

void MenuState::draw()
{
    if (!menu)
    {
        init();
    }
    menu->draw();
}

void PlayingState::init() {
    board = new Board();
    board->init(); 
}

/* PLAYING */
void PlayingState::handleInput(Vector2 coord, Game &game) {
    board->handleInput(coord, game);
}

void PlayingState::update(Game &game) {
    board->update(game);
}

void PlayingState::draw() {
    board->draw();
}


/* SETTINGS */

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
    
}

void SettingsState::update(Game &game)
{
    unsigned char pressedButton = menu->onTouch();
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

void SettingsState::draw()
{
    if (!menu)
    {
        init();
    }
    menu->draw();
}
