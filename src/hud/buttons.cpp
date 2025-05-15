#include "buttons.h"
#include "core/game.h"
#include "raylib.h"
#include "style/colors.h"

int drawButton(Rectangle size, const char *text, int fontSize, Color color,
               Color hoverColor, Color pressedColor, bool disabled) {
  Font font = Game::getGameInstance()->getFont();
  Vector2 textSize = MeasureTextEx(font, text, fontSize, 1);
  int val = 0;
  if (disabled) {
    DrawRectangleRounded(size, 0.1, 6, color);
    DrawRectangleRoundedLinesEx(size, 0.1, 6, 3, pressedColor);
  } else if (CheckCollisionPointRec(GetMousePosition(), size)) {
    if (IsMouseButtonDown(MOUSE_LEFT_BUTTON)) {
      DrawRectangleRounded(size, 0.1, 6, pressedColor);
      val = 1;
    } else {
      DrawRectangleRounded(size, 0.1, 6, hoverColor);
    }
  } else {
    DrawRectangleRounded(size, 0.1, 6, color);
  }
  DrawRectangleRoundedLinesEx(size, 0.1, 6, 3, pressedColor);
  DrawTextEx(font, text,
             {size.x + (size.width - textSize.x) / 2,
              size.y + (size.height - textSize.y) / 2},
             fontSize, 1, BLACK);
  return val;
}

int drawButton(int x, int y, int width, int height, const char *text,
               int fontSize, Color color, Color hoverColor,
               Color pressedColor, bool disabled) {
  Rectangle buttonRect = {(float)x, (float)y, (float)width, (float)height};
  return drawButton(buttonRect, text, fontSize, color, hoverColor,
                    pressedColor, disabled);
}

int drawSlider(Rectangle size, const char *text, float &value, Color color,
               Color hoverColor, Color pressedColor) {
  Font font = Game::getGameInstance()->getFont();
  Vector2 textSize = MeasureTextEx(font, text, 48, 1);
  Vector2 minusSize = MeasureTextEx(font, "-", 48, 1);
  Vector2 plusSize = MeasureTextEx(font, "+", 48, 1);
  float width = (size.width - minusSize.x - plusSize.x) * 100 / value;
  // Label
  DrawTextEx(font, text, {size.x, size.y}, 48, 1, GetThemeColor(FONT_COLOR));
  // Minus symbol
  DrawTextEx(font, text, {size.x, size.y + textSize.y + 2}, 48, 1,
             GetThemeColor(FONT_COLOR));
  // Plus symbol
  DrawTextEx(font, text,
             {size.x + size.width - plusSize.x, size.y + textSize.y + 2}, 48, 1,
             GetThemeColor(FONT_COLOR));
  // Slider
  DrawRectangleRec({size.x + minusSize.x + 2, size.y + textSize.y + 2, width,
                    size.y - textSize.y},
                   color);
  if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) &&
      CheckCollisionPointRec(GetMousePosition(),
                             {size.x + minusSize.x, size.y + textSize.y,
                              size.width - minusSize.x - plusSize.x,
                              size.height - textSize.y})) {
    value = 100.f * (GetMousePosition().x - size.x - minusSize.x) /
            (size.width - minusSize.x - plusSize.x);
    return 1;
  }
  return 0;
}