#pragma once

class Menu
{
public:
  virtual void draw() = 0;
  virtual unsigned char onTouch() = 0;
  virtual void reset() = 0;
};