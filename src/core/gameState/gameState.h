#pragma once

#include <memory>

class GameState {
public:
  virtual ~GameState() {}
  virtual GameState* handleInput() = 0;
  virtual void update() = 0;
  virtual void draw() = 0;
};
