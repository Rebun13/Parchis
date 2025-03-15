#include "LoadingState.h"
#include "../Game.h"
#include <ctime>

LoadingState::LoadingState()
{
    time_t timestamp;
    time(&timestamp);
    loadingTime_ = (int) timestamp;
}

void LoadingState::handleInput(Game *game, Input *input)
{
    return;
}

void LoadingState::update(Game *game)
{
    time_t timestamp;
    time(&timestamp);
    if ((int) timestamp - loadingTime_ > LOADING_DURATION)
    {
        game->setState(&GameState::menu);
    }
}

