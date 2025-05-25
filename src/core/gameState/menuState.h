#pragma once

#include "gameState.h"
#include "hud/hud.h"
#include "raylib.h"
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
  Texture2D bg;
  std::array<std::string, 4> bgOptions{
      "textures/menu_bg_blue.png", "textures/menu_bg_green.png",
      "textures/menu_bg_red.png", "textures/menu_bg_yellow.png"};
  std::unique_ptr<Hud> hud;
};