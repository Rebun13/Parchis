#include "raylib.h"
#include <vector>

namespace ThemeColor {

const std::vector<Color> themeColors = {
    {37, 53, 92, 255},  {33, 89, 219, 255},

    {163, 224, 66, 50}, {142, 179, 79, 255}, {78, 92, 53, 255},

    {160, 94, 66, 255}, {163, 78, 41, 255},  {160, 94, 66, 255},

    {0, 0, 0, 255}};

enum ColorIndex {
  BG_COLOR,
  BG_COLOR_ALT,
  PRIMARY_COLOR,
  PRIMARY_COLOR_HOVER,
  PRIMARY_COLOR_PRESS,
  SECONDARY_COLOR,
  SECONDARY_COLOR_HOVER,
  SECONDARY_COLOR_PRESS,
  FONT_COLOR
};

inline const Color GetThemeColor(ColorIndex index) {
  return themeColors[index];
}

}