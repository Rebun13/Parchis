#include "game.h"
#include "raylib.h"
#include <cassert>

Game::Game()
{
    font_ = LoadFont("resources/fonts/JetSet-8j1J.ttf");
}

Game::~Game()
{
    UnloadFont(font_);
}

void Game::draw()
{
    state_->draw();
}

void Game::handleInput()
{
    // state_->handleInput(coord, *this);
}

void Game::update()
{
    state_->update(*this);
}

void Game::beginGame()
{
}

bool Game::gameShouldClose()
{
    return close;
}

void Game::setClose_()
{
    close = true;
}

void Game::saveSettings()
{
}

Font Game::getFont()
{
    return font_;
}

std::unique_ptr<GameInterface> GameInterface::createGameInstance() {
    return std::make_unique<Game>();
};