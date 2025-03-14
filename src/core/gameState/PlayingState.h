#include "GameState.h"

class PlayingState : public GameState
{
public:
    PlayingState();

    virtual void handleInput(Game &game, Input input);

    virtual void update(Game &game);

private:
    
};
