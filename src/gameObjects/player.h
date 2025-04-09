#pragma once

#include <vector>

class Player
{
public:
    Player() {}
    ~Player() {}

private:
    std::vector<class Token> tokens;
    std::vector<class PowerUp> powerUps;
}
