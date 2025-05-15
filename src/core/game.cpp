#include "game.h"
#include "raylib.h"
#include <cassert>
#include <memory>
#include <string>

std::shared_ptr<Game> Game::instance {nullptr};

Game::Game() {
  std::string workingDir(GetWorkingDirectory());
  workingDir.append("/fonts/JetSet-8j1J.ttf");
  font_ = LoadFontEx(workingDir.c_str(), 96, nullptr, 0);
}

Game::~Game() {
  UnloadFont(font_);
}

void Game::draw() { state_->draw(); }

void Game::handleInput() {
  state_->handleInput();
}

void Game::update() { state_->update(); }

void Game::beginGame() {}

bool Game::gameShouldClose() { return close; }

void Game::setClose_() { close = true; }

void Game::saveSettings() {}

Font Game::getFont() { return font_; }

void Game::setState(GameState &state) {
  state_ = std::shared_ptr<GameState>(&state);
}

GameState &Game::getState() { return *state_; }

std::shared_ptr<GameInterface> GameInterface::getGameInstance() {
  return Game::gameInstance();
};