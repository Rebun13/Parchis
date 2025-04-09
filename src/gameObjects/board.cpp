#include "board.h"

Board::~Board()
{
    UnloadTexture(texture);
}

void Board::init()
{
    texture = LoadTexture("textures/board_hr.png");
    // TODO: get players and set first
}

void Board::draw()
{
    DrawTextureEx(texture, position, 0, 1, WHITE);
}