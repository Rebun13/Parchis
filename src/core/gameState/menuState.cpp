#include "menuState.h"
#include "core/game.h"
#include "core/gameState/playingState.h"
#include "core/gameState/settingsState.h"
#include "hud/hud.h"
#include "hud/menuHud.h"
#include <memory>

MenuState::MenuState() { hud = std::make_unique<MenuHud>(); }

MenuState::~MenuState() { hud->reset(); }

GameState* MenuState::handleInput() {
  unsigned char pressedButton = hud->handleInput();
  switch (pressedButton) {
  case MenuHud::PLAY_BUTTON:
    return new PlayingState();
  case MenuHud::SETTINGS_BUTTON:
    return new SettingsState();
  case MenuHud::EXIT_BUTTON:
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