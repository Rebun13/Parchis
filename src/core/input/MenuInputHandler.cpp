#include "MenuInputHandler.h"
#include "MenuInput.h"
#include "raylib.h"

MenuInputHandler::MenuInputHandler(
    Rectangle playButton,
    Rectangle settingsButton,
    Rectangle exitButton)
{
    playButton_ = playButton;
    settingsButton_ = settingsButton;
    exitButton_ = exitButton;
}

Input *MenuInputHandler::handleInput()
{
    Vector2 touchPosition = GetTouchPosition(0);
    if(CheckCollisionPointRec(touchPosition, playButton_))
        return touch_play;
    if(CheckCollisionPointRec(touchPosition, settingsButton_))
        return touch_settings;
    if(CheckCollisionPointRec(touchPosition, exitButton_))
        return touch_exit;
    return nullptr;
}