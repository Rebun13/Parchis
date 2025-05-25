#pragma once

class Hud {
public:
  virtual ~Hud() {}
  virtual void draw() = 0;
  virtual unsigned char handleInput() = 0;
  virtual void reset() = 0;
  virtual void update() = 0;
};