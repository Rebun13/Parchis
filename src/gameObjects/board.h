#pragma once

#include <vector>
#include <memory>
#include "raylib.h"
#include "gameObjects/box.h"
#include "token.h"

class Player;
class Game;
class Box;

class Board
{
public:
    Board();
    ~Board();
    void init();
    void draw();
    void handleInput(Vector2 coord, Game &game) {}
    void update(Game &game) {}
    void onTouch(Vector2 coord);

private:
    std::vector<std::unique_ptr<Box>> boxes;
    void buildBoxes();
    void clearBoxes();
    Texture2D texture;
    Vector2 position = {9.0f, 150.0f};
    std::vector<std::shared_ptr<Token>> tokens;
    // std::vector<Player> players;
};
