#include "gameState/GameState.h"

class Game
{
public:
  Game();

  GameState* state_ = &GameState::loading;
  void handleInput(Input input);
};
