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
    Board(int numPlayers);
    ~Board();
    void draw();
    void handleInput();
    void update() {}

private:
    std::vector<std::unique_ptr<Box>> boxes;
    void buildBoxes();
    void clearBoxes();
    Texture2D texture;
    Vector2 position = {9.0f, 150.0f};
    std::vector<std::shared_ptr<Token>> tokens;
    // std::vector<Player> players;
};
