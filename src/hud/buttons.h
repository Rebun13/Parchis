#pragma once

#include "raylib.h"

int drawButton(Rectangle size, const char *text, Color color, Color hoverColor, Color pressedColor);
int drawButton(int x, int y, int width, int height, const char *text, Color color, Color hoverColor, Color pressedColor);

int drawSlider(Rectangle size, const char *text, float &value, Color color, Color hoverColor, Color pressedColor);