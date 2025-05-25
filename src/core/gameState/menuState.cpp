#include "menuState.h"
#include "core/game.h"
#include "core/gameState/playingState.h"
#include "core/gameState/settingsState.h"
#include "hud/menuHud.h"
#include "raylib.h"
#include <memory>
#include <iostream>
#include <random>

MenuState::MenuState() {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> distr(0, 3); 
  colorIndex = distr(gen);
  bg = LoadTexture(bgOptions[colorIndex].c_str());
  hud = std::make_unique<MenuHud>(colorIndex);
}

GameState *MenuState::handleInput() {
  unsigned char pressedButton = hud->handleInput();
  switch (pressedButton) {
  case MenuHud::PLAY_BUTTON:
    return new PlayingState();
  case MenuHud::SETTINGS_BUTTON:
    return new SettingsState();
  case MenuHud::EXIT_BUTTON:
    std::cout << "STATE: EXIT GAME CLICKED" << std::endl;
    Game::getGameInstance()->setClose_();
    return nullptr;
  default:
    // call other entity's handleInput for some animation?
    return nullptr;
  }
}

void MenuState::update() {
  // animations for making the menu more interesting
  hud->update();
}

void MenuState::draw() {
  DrawTexture(bg, 0, 0, WHITE);
  hud->draw();
}