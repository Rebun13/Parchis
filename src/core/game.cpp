#include "game.h"
#include "raylib.h"
#include <cassert>
#include <exception>
#include <iostream>
#include <string>

Game *Game::instance{nullptr};

Game::Game() {
  std::string workingDir(GetWorkingDirectory());
  workingDir.append("/fonts/JetSet-8j1J.ttf");
  font_ = LoadFontEx(workingDir.c_str(), 96, nullptr, 0);
  state_ = nullptr;
  texture = nullptr;
}

Game::~Game() { UnloadFont(font_); }

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

void Game::loadTexturePack(std::string path) {
  try {
    Image img = LoadImage(path.c_str());
    Texture2D tx = LoadTextureFromImage(img);
    texture = &tx;
  } catch (std::exception e) {
    std::cerr << "Could not load texture pack. " << e.what() << std::endl;
  }
}

Texture2D *Game::getTexturePack() { return texture; }

Font *Game::getFont() { return &font_; }

GameInterface *GameInterface::getGameInstance() {
  return Game::gameInstance();
};