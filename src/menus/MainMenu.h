#pragma once

#include "Menu.h"
#include "raylib.h"

class MainMenu : public Menu
{
public:
    MainMenu() {}

    virtual void draw();
    virtual void onTouch(Vector2 coord);
    virtual void onClickButton(int button, bool is_down);

private:
    const Rectangle button_play = {100, 200, 200, 50};
    const Rectangle button_settings = {100, 300, 200, 50};
    const Rectangle button_exit = {100, 400, 200, 50};
};