#include "GameState.h"

#define LOADING_DURATION 3000

class LoadingState : public GameState
{
public:
    LoadingState()
        : loadingTime_(0){}

    virtual void handleInput(Game &game, Input input);

    virtual void update(Game &game);

private:
    int loadingTime_;
};
