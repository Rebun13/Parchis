#define RAYGUI_IMPLEMENTATION

#include "raygui.h"
#include "mainMenu.h"

#include <iostream>

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

    if (GuiButton({(480 - titleSize.x) / 2, buttonPlay_y, titleSize.x, titleSize.y}, playButtonText))
    {
        playButtonClicked = true;
        std::cout << "PLAY" << std::endl;
    }
    if (GuiButton({(480 - titleSize.x) / 2, buttonSettings_y, titleSize.x, titleSize.y}, settingsButtonText))
    {
        settingsButtonClicked = true;
        std::cout << "SETTINGS" << std::endl;
    }
    if (GuiButton({(480 - titleSize.x) / 2, buttonExit_y, titleSize.x, titleSize.y}, exitButtonText))
    {
        exitButtonClicked = true;
        std::cout << "EXIT" << std::endl;
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
    std::cout << "RESET" << std::endl;
    playButtonClicked = false;
    settingsButtonClicked = false;
    exitButtonClicked = false;
}
