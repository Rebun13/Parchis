#include "gameState/GameState.h"

class Game
{
public:
  Game();

private:
  GameState* state_;

public:
  void handleInput(Input *input);
  void setState(GameState *state);
};
