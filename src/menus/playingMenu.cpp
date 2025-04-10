#include "playingMenu.h"

PlayingMenu::PlayingMenu()
{
    font = LoadFont("fonts/JetSet-8j1J.ttf");
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
}

unsigned char PlayingMenu::onTouch()
{
    if (settingsButtonClicked)
    {
        reset();
        return SETTINGS_BUTTON;
    }
    if (settingsButtonClicked)
    {
        reset();
        return EXIT_BUTTON;
    }
    return -1;
}

void PlayingMenu::reset()
{
    settingsButtonClicked = false;
    settingsButtonClicked = false;
}
