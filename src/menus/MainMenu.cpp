#include "MainMenu.h"
#include "raylib.h"
#include <iostream>

void MainMenu::draw()
{
    // Draw buttons
    DrawRectangleRec(MainMenu::button_play, RED);
    DrawRectangleRec(MainMenu::button_settings, GREEN);
    DrawRectangleRec(MainMenu::button_exit, YELLOW);

    // Draw button text
    DrawText("Play", MainMenu::button_play.x + 10, MainMenu::button_play.y + 10, 20, WHITE);
    DrawText("Settings", MainMenu::button_settings.x + 10, MainMenu::button_settings.y + 10, 20, WHITE);
    DrawText("Exit", MainMenu::button_exit.x + 10, MainMenu::button_exit.y + 10, 20, WHITE);
}

void MainMenu::onTouch(Vector2 coord)
{
    // Example: Check if a button is pressed based on coordinates
    if (CheckCollisionPointRec(coord, MainMenu::button_play)) // Example button area
    {
        DrawText("Play pressed!", 0, 0, 20, RED);
        onClickButton(0, true);
    }
    else if (CheckCollisionPointRec(coord, MainMenu::button_settings))
    {
        DrawText("Settings pressed!", 0, 0, 20, RED);
        onClickButton(1, true);
    }
    else if (CheckCollisionPointRec(coord, MainMenu::button_exit))
    {
        DrawText("Exit pressed!", 0, 0, 20, RED);
        onClickButton(2, true);
    } 
    else
    {
        DrawText("No button pressed!", 0, 0, 20, RED);
    }
}

void MainMenu::onClickButton(int button, bool is_down)
{
    std::cout << "Button " << button << (is_down ? " pressed" : " released") << std::endl;
}
