#pragma once

#include "core/gameState/gameState.h"

class GameInterface {
public:
  virtual ~GameInterface() = default;
  virtual void handleInput() = 0;
  virtual void draw() = 0;
  virtual void update() = 0;
  virtual void beginGame() = 0;
  virtual bool gameShouldClose() = 0;
  virtual void setClose_() = 0;
  virtual void saveSettings() = 0;
  virtual void setState(GameState *state) = 0;
  virtual class Font *getFont() = 0;

  static GameInterface *getGameInstance();
};
