#pragma once

#include "raylib.h"


class Token
{
public:
    Token(unsigned char playerIndex, Color color);
    ~Token() {}
    void move(Vector2 newPos);
    void update();
    void draw();
    const unsigned char playerIndex;
private:
    Color color_;
    Vector2 pos_;
    Vector2 newPos_;
    float tokenSpeed = 5.0f;
};
