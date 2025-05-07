#include "game.h"
#include "raylib.h"
#include <cassert>
#include <iostream>

Game* Game::instance = nullptr;

Game::Game() {
  std::string workingDir(GetWorkingDirectory());
  workingDir.append("/fonts/JetSet-8j1J.ttf");
  font_ = LoadFont(workingDir.c_str());
  std::cout << "LOADED FONT: " << font_.glyphCount << std::endl;
}

Game::~Game() {
  UnloadFont(font_);
}

void Game::draw() { state_->draw(); }

void Game::handleInput() {
  // state_->handleInput(coord, *this);
}

void Game::update() { state_->update(); }

void Game::beginGame() {}

bool Game::gameShouldClose() { return close; }

void Game::setClose_() { close = true; }

void Game::saveSettings() {}

Font Game::getFont() { return font_; }

GameState &Game::getState() { return *state_; }

void Game::setState(GameState &state) {
  state_ = &state;
  state_->init();
}

std::unique_ptr<GameInterface> GameInterface::getGameInstance() {
  return Game::gameInstance();
};