#include "player.h"

Player::Player() {
    tokensAtHome = 4;
    tokensAtGoal = 0;
    tokens = std::vector<Token>(4, Token());
}

Player::~Player()
{
    for(auto &&token : tokens)
    {
        token.~Token();
    }
    tokens.clear();
}
