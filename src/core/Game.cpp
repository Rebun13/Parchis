#include "game.h"
#include "raylib.h"
#include <cassert>

Game *Game::instance_;
bool instantiated_ = false;

Game::Game()
{
    assert(!instantiated_);
    font_ = LoadFont("resources/fonts/JetSet-8j1J.ttf");
    instantiated_ = true;
    Game::instance_ = this;
}

Game::~Game()
{
    UnloadFont(font_);
    instantiated_ = false;
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

Game &Game::instance()
{
    if (!instantiated_)
    {
        instance_ = new Game();
    }
    return *instance_;
}

Font Game::getFont()
{
    return font_;
}