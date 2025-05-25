#pragma once

#include "hud.h"
#include "raylib.h"
#include <array>
#include <string>

struct MenuButton {
  Rectangle rect;
  std::string text;
  Vector2 textPositionIddle;
  Vector2 textPositionSelected;
  float tokenPosition;
};

class MenuHud : public Hud {
public:
  static const unsigned char PLAY_BUTTON{0};
  static const unsigned char SETTINGS_BUTTON{1};
  static const unsigned char EXIT_BUTTON{2};

  MenuHud(int color = 0);
  ~MenuHud();
  void draw() final;
  unsigned char handleInput() final;
  void reset() final;
  void update() final;

private:
  void moveToken(float position);

  // Vector2 titleSize;
  const float buttonWidth{266.f};
  const float buttonHeight{85.f};
  const float buttonLeftMargin{110.f};

  const std::string title{"PARCHIS"};

  MenuButton playButton{{buttonLeftMargin, 266.f, buttonWidth, buttonHeight},
                        "PLAY",
                        {0, 0},
                        {0, 0},
                        0};
  MenuButton settingsButton{
      {buttonLeftMargin, 356.f, buttonWidth, buttonHeight},
      "SETTINGS",
      {0,0},
      {0,0},
      0};
  MenuButton exitButton{{buttonLeftMargin, 446.f, buttonWidth, buttonHeight},
                        "EXIT",
                        {0,0},
                        {0,0},
                        0};

  Font *font;
  float tokenPositionX;
  float tokenCurrentPosition;
  float tokenNextPosition;
  float tokenRadius{30.f};
  float tokenSpeed{400.f};
  int colorIndex;
  std::array<Color, 4> tokenColors{BLUE, GREEN, RED, YELLOW};
};