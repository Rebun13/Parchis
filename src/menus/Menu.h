#pragma once

class Menu
{
public:
  virtual void draw() = 0;
  virtual void onTouch(class Vector2 coord) = 0;
  virtual void onClickButton(int button, bool is_down) = 0;
};