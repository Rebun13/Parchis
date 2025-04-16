#include "gameState.h"
#include "raylib.h"
#include "./game.h"
#include "menus/mainMenu.h"
#include "menus/settingsMenu.h"
#include "menus/playingMenu.h"
#include "gameObjects/board.h"
#include "../config.h"
// #include "client.h"

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
    tick_dt = 1.0 / TARGET_FPS;
    board->init();
}

PlayingState::~PlayingState()
{
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
    case PlayingMenu::SAVE_SETTIGNS_BUTTON:
        // TODO: get volume variables (make them public) and save them to settings file
        break;
    case PlayingMenu::EXIT_BUTTON:
        // gameClient->handleDisconnection();
        game.state_ = &Game::menu;
        game.state_->init();
        game.prevState = this;
    default:
        // ?
        break;
    }
    board->update(game);
}

void PlayingState::handleNetwork()
{
    // double acc = GetFrameTime(); // Accumulates time

    // // Simulates as many ticks as we can
    // while (acc >= tick_dt)
    // {
    //     int ev;

    //     while ((ev = NBN_GameClient_Poll()) != NBN_NO_EVENT)
    //     {
    //         if (ev < 0)
    //         {
    //             TraceLog(LOG_WARNING, "An occured while polling network events. Exit");

    //             break;
    //         }

    //         gameClient->handleGameClientEvent(ev);
    //     }

    //     if (gameClient->connected && !gameClient->disconnected)
    //     {
    //         if (gameClient->update() < 0)
    //         {
    //             break;
    //         }
    //     }

    //     if (!gameClient->disconnected)
    //     {
    //         if (NBN_GameClient_SendPackets() < 0)
    //         {
    //             TraceLog(LOG_ERROR, "An occured while flushing the send queue. Exit");
    //             break;
    //         }
    //     }
    //     acc -= tick_dt; // Consumes time
    // }
}

void PlayingState::draw()
{
    board->draw();
    menu->draw();
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
