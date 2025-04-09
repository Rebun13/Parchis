#include "mainMenu.h"
#include "raylib.h"
#include <iostream>

MainMenu::~MainMenu() {
    UnloadFont(font);
}

MainMenu::MainMenu()
{
    font = LoadFont("fonts/JetSet-8j1J.ttf");
	titleSize = MeasureTextEx(font, title, 90, 5);
}

void MainMenu::draw()
{
    DrawTextEx(font, title, {(480 - titleSize.x) / 2, 100}, 90, 5, {255, 255, 255, 255});
    // Draw buttons
    DrawRectangleRounded(button_play, 0.3, 8, RED);
    DrawRectangleRounded(button_settings, 0.3, 8, GREEN);
    DrawRectangleRounded(button_exit, 0.3, 8, YELLOW);

    // Draw button text
    DrawTextEx(font, "Play", {button_play.x + 10, button_play.y + 10}, 20, 5, WHITE);
    DrawTextEx(font, "Settings", {button_settings.x + 10, button_settings.y + 10}, 20, 5, WHITE);
    DrawTextEx(font, "Exit", {button_exit.x + 10, button_exit.y + 10}, 20, 5, WHITE);
}

unsigned char MainMenu::onTouch(Vector2 coord)
{
    if (CheckCollisionPointRec(coord, button_play))
    {
        // TODO: play sound
        return PLAY_BUTTON;
    }
    else if (CheckCollisionPointRec(coord, button_settings))
    {
        // TODO: play sound
        return SETTINGS_BUTTON;
    }
    else if (CheckCollisionPointRec(coord, button_exit))
    {
        // TODO: play sound
        return EXIT_BUTTON;
    }
    return -1;
}
