#include "Game.h"
#include "raylib.h"

void Game::handleInput(Input input)
{
    state_->handleInput(*this, input);
}