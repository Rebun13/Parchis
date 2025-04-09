#pragma once

#include "menu.h"
#include "raylib.h"

class PlayingMenu : public Menu
{
public:
    static const unsigned char SETTINGS_BUTTON = 1;
    static const unsigned char EXIT_BUTTON = 2;

    PlayingMenu();
    ~PlayingMenu();
    void draw() override;
    unsigned char onTouch() override;
    void reset() override;

private:
    const char* settingsButtonText = "SETTINGS";
    const char* exitButtonText = "EXIT";

    const Rectangle buttonSettings = {400, 20, 60, 60};
    const Rectangle buttonExit = {20, 20, 60, 60};

    bool settingsButtonClicked = false;
    bool exitButtonClicked = false;

    Font font;
};