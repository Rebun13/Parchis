// #include "config.h"

#include "playingState.h"
#include "core/gameMode/gameMode.h"
#include "core/gameMode/regularGamemode.h"
#include "core/gameState/menuState.h"
#include "hud/playingHud.h"
#include <memory>

PlayingState::PlayingState()
{
    hud = std::make_unique<PlayingHud>();
    gamemode = std::make_unique<RegularGameMode>();
}

PlayingState::~PlayingState()
{
    hud.reset();
    gamemode.reset();
}

GameState* PlayingState::handleInput()
{
    unsigned char pressedButton = hud->handleInput();
    switch(pressedButton) {
    case PlayingHud::SAVE_SETTINGS_BUTTON:
        // TODO: get volume variables (make them public) and save them to settings file
        return nullptr;
    case PlayingHud::EXIT_BUTTON:
        return new MenuState();
    default:
        return gamemode->handleInput();
    }
}

void PlayingState::update()
{
    
}

void PlayingState::draw()
{
    gamemode->draw();
    if (gamemode->gameStarted)
    {
        hud->draw();
    }
}
