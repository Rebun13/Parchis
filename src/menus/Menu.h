#pragma once

#if !defined(RAYGUI_CUSTOM_ICONS)
#define RAYGUI_CUSTOM_ICONS
#endif

#include "ricons.h"
#include "raygui.h"

class Menu
{
public:
  virtual void draw() = 0;
  virtual unsigned char onTouch() = 0;
  virtual void reset() = 0;
};