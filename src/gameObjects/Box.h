#pragma once

#include "raylib.h"

class Box
{
public:
    virtual Vector2 getPos();
    virtual Box *getNextBox();

private:
    int numTokens = 0;
    Vector2 pos;
    Vector2 posA;
    Vector2 posB;
    Box *nextBox;
    int speed;
}