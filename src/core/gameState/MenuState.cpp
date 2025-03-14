#include "MenuState.h"
#include "GameState.h"
#include "../Game.h"
#include "raylib.h"

MenuState::MenuState()
{
}

void MenuState::handleInput(Game &game, Input input)
{
    if (input == TOUCH_PLAY)
    {
        game.state_ = GameState::in_game;
    } else if (input == TOUCH_EXIT) {
        closeWindow();
    } else if (input == TOUCH_SETTINGS) {
        // Open settings
    }
}

