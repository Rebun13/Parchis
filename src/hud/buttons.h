#pragma once

#include "raylib.h"

int drawButton(Rectangle size, const char *text, int fontSize, Color color,
               Color hoverColor, Color pressedColor, bool disabled = false);
int drawButton(int x, int y, int width, int height, const char *text,
               int fontSize, Color color, Color hoverColor, Color pressedColor, bool disabled = false);

int drawSlider(Rectangle size, const char *text, float &value, Color color,
               Color hoverColor, Color pressedColor);