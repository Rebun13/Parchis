#pragma once

#include "gameobjects/GameObject.h"
#include <vector>

using namespace std;

class InputDispatcher;
class Texture2D;

class Factory
{
private:
    const int MENU_BTN_TEX_LEFT = 0;
    const int MENU_BTN_TEX_TOP = 0;
    const int MENU_BTN_TEX_WIDTH = 80;
    const int MENU_BTN_TEX_HEIGHT = 96;

    Texture2D *m_Texture;

public:
    Factory();

    void loadLevel(
        vector<GameObject> &gameObjects,
        // VertexArray &canvas,
        InputDispatcher &inputDispatcher);
};