#pragma once

#include <string>

using namespace std;

class PlayerEvent
{
public:
    PlayerEvent(string playerId, string action, int timestamp)
        : playerId_(playerId), action_(action), timestamp_(timestamp) {}

    const string getPlayerId() const { return playerId_; }
    const string getAction() const { return action_; }
    const int getTimestamp() const { return timestamp_; }

private:
    const string playerId_;
    const string action_;
    const int timestamp_;
};