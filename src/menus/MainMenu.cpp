#include "MainMenu.h"
#include "raylib.h"
#include <iostream>

void MainMenu::draw()
{
    // Draw buttons
    DrawRectangleRec(button_play, RED);
    DrawRectangleRec(button_settings, GREEN);
    DrawRectangleRec(button_exit, YELLOW);

    // Draw button text
    DrawText("Play", button_play.x + 10, button_play.y + 10, 20, WHITE);
    DrawText("Settings", button_settings.x + 10, button_settings.y + 10, 20, WHITE);
    DrawText("Exit", button_exit.x + 10, button_exit.y + 10, 20, WHITE);
}

void MainMenu::onTouch(Vector2 coord)
{
    if (CheckCollisionPointRec(coord, button_play))
    {
        mustClose = true;
        std::cout << "Closed menu!" << std::endl;
    }
    else if (CheckCollisionPointRec(coord, button_settings))
    {
        std::cout << "SETTINGS" << std::endl;
    }
    else if (CheckCollisionPointRec(coord, button_exit))
    {
        std::cout << "EXIT" << std::endl;
    } 
    else
    {
        std::cout << "CLICKED OUTSIDE" << std::endl;
    }
}
