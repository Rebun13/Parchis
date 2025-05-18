#include "game.h"
#include "raylib.h"
#include <cassert>
#include <string>
#include <iostream>

Game *Game::instance{nullptr};

Game::Game() {
  std::string workingDir(GetWorkingDirectory());
  workingDir.append("/fonts/JetSet-8j1J.ttf");
  font_ = LoadFontEx(workingDir.c_str(), 96, nullptr, 0);
  state_ = nullptr;
}

Game::~Game() {
  UnloadFont(font_);
  std::cerr << "################ FONT UNLIADED ################" << std::endl;
}

void Game::draw() {
  if (state_)
    state_->draw();
}

void Game::handleInput() {
  if (!state_)
    return;
  if (GameState *newState = state_->handleInput()) {
    delete state_;
    state_ = newState;
  }
}

void Game::update() { state_->update(); }

void Game::beginGame() {}

bool Game::gameShouldClose() { return close; }

void Game::setClose_() { close = true; }

void Game::saveSettings() {}

void Game::setState(GameState *state) {
  assert(state);
  if (state_)
    delete state_;
  state_ = state;
}

Font *Game::getFont() { return &font_; }

GameInterface *GameInterface::getGameInstance() {
  return Game::gameInstance();
};