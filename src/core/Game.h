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
  void update();
  void beginGame() {};
  bool gameShouldClose();
  void setClose_();
  void saveSettings() {} // TODO: add arguments and save using settings::saveSettings()
  GameState *state_;
  GameState *prevState = nullptr;

private:
  // vector<Player> players;
  //
  bool close = false;
};
