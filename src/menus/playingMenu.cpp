#include "playingMenu.h"
#include <iostream>

PlayingMenu::PlayingMenu()
{
    font = LoadFont("fonts/JetSet-8j1J.ttf");
    exitWindowTextSize = MeasureTextEx(font, exitWindowText, 16, 1);
    std::cout << "TEXT SIZE: " << exitWindowTextSize.x << std::endl;
    exitWindowTextPosition.x = (480.f - exitWindowTextSize.x) / 2.f;
}

PlayingMenu::~PlayingMenu()
{
    UnloadFont(font);
}

void PlayingMenu::draw()
{
    if (GuiButton(buttonExit, exitButtonText))
    {
        exitButtonClicked = true;
    }

    if (GuiButton(buttonSettings, settingsButtonText))
    {
        settingsButtonClicked = true;
    }

    if (exitButtonClicked)
    {
        GuiPanel(exitWindow, "");
        DrawTextEx(font, exitWindowText, exitWindowTextPosition, 16, 1, GetColor(GuiGetStyle(DEFAULT, TEXT_COLOR_NORMAL)));
        if (GuiButton(buttonSurrender, surrenderButtonText))
        {
            surrenderButtonClicked = true;
        };
        if (GuiButton(buttonCancel, cancelButtonText))
        {
            cancelButtonClicked = true;
        };
    }
}

unsigned char PlayingMenu::onTouch()
{
    if (surrenderButtonClicked)
    {
        reset();
        return EXIT_BUTTON;
    }
    if (settingsButtonClicked)
    {
        reset();
        return SETTINGS_BUTTON;
    }
    if (cancelButtonClicked)
    {
        reset();
    }
    return -1;
}

void PlayingMenu::reset()
{
    surrenderButtonClicked = false;
    settingsButtonClicked = false;
    cancelButtonClicked = false;
    exitButtonClicked = false;
}
