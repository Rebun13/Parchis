#include "Game.h"
#include "raylib.h"
#include "./gameState.h"

Game::Game()
{
    
}

void Game::draw()
{
    state_->draw();
    // draw board

    // draw players
        // draw home boxes
        // draw tokens

    // draw UI
}

void Game::handleInput(Vector2 coord) {
    state_->handleInput(coord, *this);
}
