#pragma once

#include "core/gameState/gameState.h"
#include "raylib.h"
#include <string>

class Font;

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
  virtual void loadTexturePack(std::string path) = 0;
  virtual Font *getFont() = 0;
  virtual Texture2D *getTexturePack() = 0;

  static GameInterface *getGameInstance();
};
