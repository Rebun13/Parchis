#include "menuHud.h"
#include "hud/buttons.h"
#include "style/colors.h"
#include "core/game.h"

MenuHud::~MenuHud() { UnloadFont(font); }

MenuHud::MenuHud() {
  font = Game::getGameInstance()->getFont();
  titleSize = MeasureTextEx(font, title, 90, 5);
}

void MenuHud::draw() {
  DrawTextEx(font, title, {(480 - titleSize.x) / 2, 100}, 90, 5,
             {255, 255, 255, 255});

  if (drawButton((480 - titleSize.x) / 2, buttonPlay_y, titleSize.x,
                 buttonHeight, playButtonText, 40, GetThemeColor(PRIMARY_COLOR),
                 GetThemeColor(PRIMARY_COLOR_HOVER),
                 GetThemeColor(PRIMARY_COLOR_PRESS))) {
    playButtonClicked = true;
  }
  if (drawButton((480 - titleSize.x) / 2, buttonSettings_y, titleSize.x,
                 buttonHeight, settingsButtonText, 40, GetThemeColor(PRIMARY_COLOR),
                 GetThemeColor(PRIMARY_COLOR_HOVER),
                 GetThemeColor(PRIMARY_COLOR_PRESS))) {
    settingsButtonClicked = true;
  }
  if (drawButton((480 - titleSize.x) / 2, buttonExit_y, titleSize.x,
                 buttonHeight, exitButtonText, 40, GetThemeColor(PRIMARY_COLOR),
                 GetThemeColor(PRIMARY_COLOR_HOVER),
                 GetThemeColor(PRIMARY_COLOR_PRESS))) {
    exitButtonClicked = true;
  }
}

unsigned char MenuHud::handleInput() {
  if (playButtonClicked) {
    // TODO: play sound
    reset();
    return PLAY_BUTTON;
  } else if (settingsButtonClicked) {
    // TODO: play sound
    reset();
    return SETTINGS_BUTTON;
  } else if (exitButtonClicked) {
    // TODO: play sound
    reset();
    return EXIT_BUTTON;
  }
  return -1;
}

void MenuHud::reset() {
  playButtonClicked = false;
  settingsButtonClicked = false;
  exitButtonClicked = false;
}
