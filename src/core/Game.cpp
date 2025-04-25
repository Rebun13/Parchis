#include "game.h"
#include "raylib.h"

Game Game::instance_;

Game::Game()
{
    font_ = LoadFont("resources/fonts/JetSet-8j1J.ttf");
    initialized = true;
}

Game::~Game()
{
    UnloadFont(font_);
}

void Game::draw()
{
    state_->draw();
}

void Game::handleInput(Vector2 coord)
{
    // state_->handleInput(coord, *this);
}

void Game::update()
{
    state_->update(*this);
}

bool Game::gameShouldClose()
{
    return close;
}

void Game::setClose_()
{
    close = true;
}