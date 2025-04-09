#pragma once

#include "menu.h"
#include "raylib.h"

class MainMenu : public Menu
{
public:
    static const unsigned char PLAY_BUTTON = 0;
    static const unsigned char SETTINGS_BUTTON = 1;
    static const unsigned char EXIT_BUTTON = 2;

    MainMenu();
    ~MainMenu();
    void draw();
    unsigned char onTouch(Vector2 coord);

private:
    Vector2 titleSize;
    const char* title = "PARCHIS";

    const Rectangle button_play = {100, 200, 200, 50};
    const Rectangle button_settings = {100, 300, 200, 50};
    const Rectangle button_exit = {100, 400, 200, 50};

    Font font;
};