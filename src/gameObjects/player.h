#pragma once

#include <vector>
#include "token.h"

class Player
{
public:
    Player();
    ~Player();

private:
    std::vector<Token> tokens;
    int tokensAtHome;
    int tokensAtGoal;
    // std::vector<class PowerUp> powerUps;
};
