#pragma once

#include <vector>
#include "raylib.h"

class Player;
class Game;

class Board
{
public:
    ~Board();
    void init(); 
    void draw();
    void handleInput(Vector2 coord, Game &game) {}
    void update(Game &game) {}
private:
    Texture2D texture;
    Vector2 position = { 9.0f, 150.0f };
    std::vector<Player> *players;
};
