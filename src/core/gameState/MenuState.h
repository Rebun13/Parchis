#include "GameState.h"

class MenuState : public GameState
{
public:
    MenuState();

    virtual void handleInput(Game &game, Input input);

    virtual void update(Game &game);

private:
    
};
