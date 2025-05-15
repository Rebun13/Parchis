#pragma once

#include "gameState.h"

class PlayingState : public GameState {
public:
  PlayingState();
  ~PlayingState();
  GameState* handleInput() final;
  void update() final;
  void draw() final;

private:
  std::unique_ptr<class Hud> hud;
  std::unique_ptr<class GameMode> gamemode;
};