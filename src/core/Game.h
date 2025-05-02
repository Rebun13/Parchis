#pragma once

#include "core/gameState/gameState.h"
#include "core/gameState/menuState.h"
#include "core/gameState/playingState.h"
#include "core/gameState/settingsState.h"
#include "core/gameInterface.h"

class Game : public GameInterface
{
public:
  inline static MenuState menu;
  inline static SettingsState settings;
  inline static PlayingState playing;

  Game();
  ~Game();
  /* INTERFACE */
  virtual void handleInput() final;
  virtual void draw() final;
  virtual void update() final;
  virtual void beginGame() final;
  virtual bool gameShouldClose() final;
  virtual void setClose_() final;
  virtual void saveSettings() final; // TODO: add arguments and save using settings::saveSettings()
  /* END INTERFACE */
  GameState *state_;
  GameState *prevState = nullptr;
  
private:
  bool close = false;
  Font font_;

public:
  Font getFont();
};
