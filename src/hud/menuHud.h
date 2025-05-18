#pragma once

#include "hud.h"
#include "raylib.h"

class MenuHud : public Hud
{
public:
    static const unsigned char PLAY_BUTTON = 0;
    static const unsigned char SETTINGS_BUTTON = 1;
    static const unsigned char EXIT_BUTTON = 2;

    MenuHud();
    ~MenuHud();
    void draw() override;
    unsigned char handleInput() override;
    void reset() override;

private:
    Vector2 titleSize;
    const char* title = "PARCHIS";
    const char* playButtonText = "PLAY";
    const char* settingsButtonText = "SETTINGS";
    const char* exitButtonText = "EXIT";

    const float buttonPlay_y = 300.f;
    const float buttonSettings_y = 400.f;
    const float buttonExit_y = 500.f;
    const float buttonHeight = 80.f;

    bool playButtonClicked = false;
    bool settingsButtonClicked = false;
    bool exitButtonClicked = false;

    Font *font;
};