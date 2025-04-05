#pragma once

class Menu
{
public:
  virtual void draw() = 0;
  virtual unsigned char onTouch(class Vector2 coord) = 0;
};