#pragma once

class Menu
{
public:
  virtual void draw() = 0;
  virtual void onTouch(class Vector2 coord) = 0;
  bool menuMustClose() { return mustClose; }
private:
  bool mustClose;
};