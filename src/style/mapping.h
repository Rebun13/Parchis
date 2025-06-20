#pragma once

#include "raylib.h"
#include <vector>

namespace TextureMapping {
const std::vector<Rectangle> coords{
    {0, 0, 578, 180},    // logo
    {0, 180, 460, 460},  // board
    {578, 0, 480, 720},  // menu_bg_blue
    {1058, 0, 480, 720}, // menu_bg_yellow
    {1538, 0, 480, 720}, // menu_bg_red
    {2018, 0, 480, 720}  // menu_bg_green
};

enum TextureIndex {
  LOGO,
  BOARD,
  MENU_BG_BLUE,
  MENU_BG_YELLOW,
  MENU_BG_RED,
  MENU_BG_GREEN
};

inline const Rectangle getTextureMapping(TextureIndex index) {
  return coords[index];
}
} // namespace TextureMapping