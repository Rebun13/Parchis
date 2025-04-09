#pragma once

#include <vector>

class Board
{
public:
    void init();

private:
    Vector<Box> *boxes;
}