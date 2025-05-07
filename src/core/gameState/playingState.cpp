// #include "config.h"

#include "playingState.h"
#include "core/game.h"
#include "core/gameMode/gameMode.h"
#include "core/gameMode/regularGamemode.h"
#include "hud/playingHud.h"
#include "gameObjects/board.h"

void PlayingState::init()
{
    hud = new PlayingHud;
    gamemode = new RegularGameMode();
}

PlayingState::PlayingState()
{
}

PlayingState::~PlayingState()
{
    delete hud;
}

void PlayingState::handleInput()
{
    // board->handleInput(coord, game);
}

void PlayingState::update()
{
    std::unique_ptr<GameInterface> game = Game::getGameInstance();
    unsigned char pressedButton;
    if (gamemode->gameStarted)
    {
        pressedButton = hud->onTouch();
    }
    else
    {
        pressedButton = -1;
    }
    switch (pressedButton)
    {
    case PlayingHud::SAVE_SETTIGNS_BUTTON:
        // TODO: get volume variables (make them public) and save them to settings file
        break;
    case PlayingHud::EXIT_BUTTON:
        // gameClient->handleDisconnection();
        game->setState(Game::menu);
    default:
        gamemode->update();
        break;
    }
}

// void PlayingState::handleNetwork()
// {
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
// }

void PlayingState::draw()
{
    gamemode->draw();
    if (gamemode->gameStarted)
    {
        hud->draw();
    }
}
