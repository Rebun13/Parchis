#pragma once

#include "./gameState.h"


class Game
{
public:
  inline static MenuState menu;
  inline static SettingsState settings;
  inline static PlayingState playing;

  Game();
  void handleInput(Vector2 coord);
  void draw();
  void beginGame() {};
  GameState *state_;

private:
  // vector<Player> players;
  //
};
