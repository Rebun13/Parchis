#pragma once

#include <memory>

#include "core/gameState/gameState.h"
#include "core/gameState/menuState.h"
#include "core/gameState/playingState.h"
#include "core/gameState/settingsState.h"

class GameInterface {
public:
  inline static MenuState menu;
  inline static SettingsState settings;
  inline static PlayingState playing;

  virtual ~GameInterface() = default;
  virtual void handleInput() = 0;
  virtual void draw() = 0;
  virtual void update() = 0;
  virtual void beginGame() = 0;
  virtual bool gameShouldClose() = 0;
  virtual void setClose_() = 0;
  virtual void saveSettings() = 0;
  virtual GameState &getState() = 0;
  virtual void setState(GameState &state) = 0;
  virtual class Font getFont() = 0;

  static std::unique_ptr<GameInterface> getGameInstance();
};
