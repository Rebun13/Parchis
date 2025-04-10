#include "playingMenu.h"

PlayingMenu::PlayingMenu()
{
    font = LoadFont("fonts/JetSet-8j1J.ttf");
    exitWindowTextSize = MeasureTextEx(font, exitWindowText, 14, 1);
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

    if(exitButtonClicked) {
        GuiPanel(exitWindow, "");
        GuiLabel({(480 - exitWindowTextSize.x) / 2, exitWindowTextPosition.y}, exitWindowText);
        if(GuiButton(buttonSurrender, surrenderButtonText)) {
            surrenderButtonClicked = true;
        };
        if(GuiButton(buttonCancel, cancelButtonText)) {
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
    if(cancelButtonClicked) {
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
