#pragma once

// #include "gameState/PlayingState.h"
// #include "gameState/MenuState.h"
// #include "gameState/LoadingState.h"

class Game
{
public:
  // static PlayingState playing;
  // static MenuState menu;
  // static LoadingState loading;

  Game();

private:
public:
  void handleInput(class Input *input);
  // class GameState *state_;
};
