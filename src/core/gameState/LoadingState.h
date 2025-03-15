#include "GameState.h"

#define LOADING_DURATION 3000

class LoadingState : public GameState
{
public:
    LoadingState()
        : loadingTime_(0){}

    void handleInput(Game *game, Input *input);

    void update(Game *game);

private:
    int loadingTime_;
};
