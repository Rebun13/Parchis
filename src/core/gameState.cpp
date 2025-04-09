#include "gameState.h"
#include "raylib.h"
#include "./game.h"
#include "menus/mainMenu.h"
#include "menus/settingsMenu.h"
#include "menus/playingMenu.h"
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
        game.state_->init();
        game.prevState = this;
        break;
    case MainMenu::SETTINGS_BUTTON:
        game.state_ = &Game::settings;
        game.state_->init();
        game.prevState = this;
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

/* PLAYING */
void PlayingState::init()
{
    board = new Board();
    menu = new PlayingMenu;
    board->init();
}

PlayingState::~PlayingState() {
    delete menu;
}

void PlayingState::handleInput(Vector2 coord, Game &game)
{
    board->handleInput(coord, game);
}

void PlayingState::update(Game &game)
{
    unsigned char pressedButton = menu->onTouch();
    switch (pressedButton)
    {
    case PlayingMenu::SETTINGS_BUTTON:
        game.state_ = &Game::settings;
        game.state_->init();
        game.prevState = this;
        break;
    default:
        // ?
        break;
    }
    board->update(game);
}

void PlayingState::draw()
{
    menu->draw();
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
    if (!menu)
    {
        init();
    }
    menu->draw();
}
