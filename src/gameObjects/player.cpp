#include "player.h"

Player::Player(std::vector<std::shared_ptr<Token>> tokens) : tokens_(tokens) {
    tokensAtHome = tokens.size();
    tokensAtGoal = 0;
}

Player::~Player()
{
    for(auto &&token : tokens_)
    {
        token.reset(); // Must alsobe called by the other objects that share this pointer
    }
    tokens_.clear();
}
