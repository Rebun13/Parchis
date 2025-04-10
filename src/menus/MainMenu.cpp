#include "mainMenu.h"

MainMenu::~MainMenu()
{
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

    if (GuiButton({(480 - titleSize.x) / 2, buttonPlay_y, titleSize.x, buttonHeight}, playButtonText))
    {
        playButtonClicked = true;
    }
    if (GuiButton({(480 - titleSize.x) / 2, buttonSettings_y, titleSize.x, buttonHeight}, settingsButtonText))
    {
        settingsButtonClicked = true;
    }
    if (GuiButton({(480 - titleSize.x) / 2, buttonExit_y, titleSize.x, buttonHeight}, exitButtonText))
    {
        exitButtonClicked = true;
    }
}

unsigned char MainMenu::onTouch()
{
    if (playButtonClicked)
    {
        // TODO: play sound
        reset();
        return PLAY_BUTTON;
    }
    else if (settingsButtonClicked)
    {
        // TODO: play sound
        reset();
        return SETTINGS_BUTTON;
    }
    else if (exitButtonClicked)
    {
        // TODO: play sound
        reset();
        return EXIT_BUTTON;
    }
    return -1;
}

void MainMenu::reset()
{
    playButtonClicked = false;
    settingsButtonClicked = false;
    exitButtonClicked = false;
}
