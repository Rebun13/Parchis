#include "menuState.h"
#include "core/game.h"
#include "core/gameState/playingState.h"
#include "core/gameState/settingsState.h"
#include "hud/menuHud.h"
#include <memory>
#include <iostream>

MenuState::MenuState() { hud = std::make_unique<MenuHud>(); }

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
}

void MenuState::draw() { hud->draw(); }