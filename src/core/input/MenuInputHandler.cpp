#include "MenuInputHandler.h"
#include "MenuInput.h"
#include "raylib.h"

Input* MenuInputHandler::handleInput()
{
    if(GetTouchPointId(?) == ?) return touch_play;
    if(GetTouchPointId(?) == ?) return touch_settings;
    if(GetTouchPointId(?) == ?) return touch_exit;
    return nullptr;
}