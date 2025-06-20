#pragma once

#include "gameState.h"
#include "hud/hud.h"
#include "raylib.h"
#include "style/mapping.h"
#include <array>
#include <memory>
#include <string>

class MenuState : public GameState {
public:
  MenuState();
  virtual GameState *handleInput() final;
  virtual void update() final;
  virtual void draw() final;

private:
  int colorIndex;
  Texture2D *bg;
  Rectangle bgCoords;
  std::array<TextureMapping::TextureIndex, 4> bgOptions{
      TextureMapping::MENU_BG_BLUE, TextureMapping::MENU_BG_GREEN,
      TextureMapping::MENU_BG_RED, TextureMapping::MENU_BG_YELLOW};
  std::unique_ptr<Hud> hud;
};