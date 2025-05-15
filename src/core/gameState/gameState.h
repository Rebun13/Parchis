#pragma once

#include <memory>

class GameState {
public:
  virtual ~GameState() {}
  virtual std::shared_ptr<GameState> handleInput() = 0;
  virtual void update() = 0;
  virtual void draw() = 0;
};
