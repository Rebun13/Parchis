#pragma once

#include "gameState.h"
#include "hud/hud.h"
#include "core/gameMode/gameMode.h"
#include <memory>

class PlayingState : public GameState {
public:
  PlayingState();
  GameState* handleInput() final;
  void update() final;
  void draw() final;

private:
  std::unique_ptr<Hud> hud;
  std::unique_ptr<GameMode> gamemode;
};