#pragma once

#include <vector>
#include <memory>
#include "token.h"
#include "client.h"

class Player
{
public:
    Player(std::vector<std::shared_ptr<Token>> tokens);
    ~Player();

private:
    Client playerClient_;
    std::vector<std::shared_ptr<Token>> tokens_;
    int tokensAtHome;
    int tokensAtGoal;
    // std::vector<class PowerUp> powerUps;
};
