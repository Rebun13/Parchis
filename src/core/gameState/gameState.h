#pragma once
#include "raylib.h"
#include <vector>
#include <memory>

class Game;
class Hud;

class GameState
{
public:
    virtual void handleInput(Vector2 coord, Game &game) = 0;
    virtual void update(Game &game) = 0;
    virtual void draw() = 0;
    virtual void init() = 0;
};
