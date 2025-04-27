#pragma once

#include "core/gameState/gameState.h"
#include "core/gameState/menuState.h"
#include "core/gameState/playingState.h"
#include "core/gameState/settingsState.h"

class Game
{
public:
  inline static MenuState menu;
  inline static SettingsState settings;
  inline static PlayingState playing;

  Game();
  ~Game();

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
  static Game *instance_;
  static bool instantiated_;
  // vector<Player> players;
  bool close = false;
  Font font_;

public:
  static Game& instance();
  Font getFont();
};
