#include "Game.h"
#include "gameState/GameState.h"
#include "gameState/LoadingState.h"
#include "./input/Input.h"
#include "raylib.h"

Game::Game()
{
    state_ = &GameState::loading;
}

void Game::handleInput(Input *input)
{
    state_->handleInput(*this, *input);
}

void Game::setState(GameState *state)
{
    state_ = state;
}
