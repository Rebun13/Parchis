#pragma once

#include "raylib.h"
#include "core/game.h"
#include <iostream>

int drawButton(Rectangle size, const char *text, Color color, Color hoverColor, Color pressedColor)
{
    Font font = Game::instance().getFont();
    Vector2 textSize = MeasureTextEx(font, text, 12, 1);
    int val = 0;
    if (CheckCollisionPointRec(GetMousePosition(), size))
    {
        if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
        {
            std::cout << "Font " << (Game::instance().isInitialized() ? "loaded" : "not loaded") << std::endl;
            DrawRectangleRounded(size, 0.1, 6, pressedColor);
            val = 1;
        }
        else
        {
            DrawRectangleRounded(size, 0.1, 6, hoverColor);
        }
    }
    else
    {
        DrawRectangleRounded(size, 0.1, 6, color);
    }
    DrawTextEx(font, text, {size.x + (size.width - textSize.x) / 2, size.y + (size.height - textSize.y) / 2}, 12, 1, BLACK);
    return val;
}

int drawButton(int x, int y, int width, int height, const char *text, Color color, Color hoverColor, Color pressedColor)
{
    Rectangle buttonRect = {(float)x, (float)y, (float)width, (float)height};
    return drawButton(buttonRect, text, color, hoverColor, pressedColor);
}