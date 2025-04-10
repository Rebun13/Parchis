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
    const char *settingsButtonText = GuiIconText(ICON_SETTINGS, "");
    const char *exitButtonText = "EXIT";
    const char *exitWindowText = "Are you sure you want to surrender?";
    const char *surrenderButtonText = "SURRENDER";
    const char *cancelButtonText = "CANCEL";

    const Rectangle buttonSettings = {400, 20, 60, 40};
    const Rectangle buttonExit = {20, 20, 60, 40};
    const Vector2 surrenderAnchor = {20, 200};
    const Rectangle exitWindow = {surrenderAnchor.x, surrenderAnchor.y, 440, 160};
    Vector2 exitWindowTextPosition = {surrenderAnchor.x + 20, surrenderAnchor.y + 50};
    const Rectangle buttonSurrender = {surrenderAnchor.x + 20, surrenderAnchor.y + 100, 190, 40};
    const Rectangle buttonCancel = {surrenderAnchor.x + 230, surrenderAnchor.y + 100, 190, 40};

    bool settingsButtonClicked = false;
    bool exitButtonClicked = false;
    bool surrenderButtonClicked = false;
    bool cancelButtonClicked = false;

    Font font;
    Vector2 exitWindowTextSize;
};