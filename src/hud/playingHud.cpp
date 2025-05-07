#include "playingHud.h"
#include "hud/buttons.h"
#include "raylib.h"
#include "style/colors.h"

#if defined(PLATFORM_DESKTOP)
#define GLSL_VERSION 330
#else // PLATFORM_ANDROID, PLATFORM_WEB
#define GLSL_VERSION 100
#endif

PlayingHud::PlayingHud() {
  font = LoadFont("fonts/JetSet-8j1J.ttf");
  exitWindowTextSize = MeasureTextEx(font, exitWindowText, 16, 1);
  exitWindowTextPosition.x = (480.f - exitWindowTextSize.x) / 2.f;
}

PlayingHud::~PlayingHud() { UnloadFont(font); }

void PlayingHud::draw() {
  if (drawButton(buttonExit, exitButtonText, GetThemeColor(PRIMARY_COLOR),
                 GetThemeColor(PRIMARY_COLOR_HOVER),
                 GetThemeColor(PRIMARY_COLOR_PRESS))) {
    exitButtonClicked = true;
  }

  if (drawButton(buttonSettings, settingsButtonText,
                 GetThemeColor(PRIMARY_COLOR),
                 GetThemeColor(PRIMARY_COLOR_HOVER),
                 GetThemeColor(PRIMARY_COLOR_PRESS))) {
    settingsButtonClicked = true;
  }

  if (exitButtonClicked) {
    DrawRectangleRec(exitWindow, GetThemeColor(BG_COLOR_ALT));
    DrawTextEx(font, exitWindowText, exitWindowTextPosition, 16, 1,
               GetThemeColor(FONT_COLOR));
    if (drawButton(buttonSurrender, surrenderButtonText,
                   GetThemeColor(PRIMARY_COLOR),
                   GetThemeColor(PRIMARY_COLOR_HOVER),
                   GetThemeColor(PRIMARY_COLOR_PRESS))) {
      surrenderButtonClicked = true;
    };
    if (drawButton(buttonCancel, cancelButtonText, GetThemeColor(PRIMARY_COLOR),
                   GetThemeColor(PRIMARY_COLOR_HOVER),
                   GetThemeColor(PRIMARY_COLOR_PRESS))) {
      cancelButtonClicked = true;
    };
  }
  if (settingsButtonClicked) {
    DrawRectangleRec(settingsContainer, GetThemeColor(BG_COLOR_ALT));
    if (drawButton(settingsContainer.x + 2, settingsContainer.y + 2, 20, 20,
                   "Exit", GetThemeColor(SECONDARY_COLOR),
                   GetThemeColor(SECONDARY_COLOR_HOVER),
                   GetThemeColor(SECONDARY_COLOR_PRESS))) {
      settingsButtonClicked = false;
      // TODO: save applied settings
      saveButtonClicked = true;
    }

    drawSlider(generalVolumeSlider, generalVolumeLabelText, generalVolume,
               GetThemeColor(PRIMARY_COLOR), GetThemeColor(PRIMARY_COLOR_HOVER),
               GetThemeColor(PRIMARY_COLOR_PRESS));

    drawSlider(musicVolumeSlider, musicVolumeLabelText, musicVolume,
               GetThemeColor(PRIMARY_COLOR), GetThemeColor(PRIMARY_COLOR_HOVER),
               GetThemeColor(PRIMARY_COLOR_PRESS));

    drawSlider(fxVolumeSlider, fxVolumeLabelText, fxVolume,
               GetThemeColor(PRIMARY_COLOR), GetThemeColor(PRIMARY_COLOR_HOVER),
               GetThemeColor(PRIMARY_COLOR_PRESS));
  }
}

unsigned char PlayingHud::onTouch() {
  if (surrenderButtonClicked) {
    reset();
    return EXIT_BUTTON;
  }
  if (saveButtonClicked) {
    return SAVE_SETTIGNS_BUTTON;
  }
  if (cancelButtonClicked) {
    reset();
  }
  return -1;
}

void PlayingHud::reset() {
  surrenderButtonClicked = false;
  settingsButtonClicked = false;
  cancelButtonClicked = false;
  exitButtonClicked = false;
  saveButtonClicked = false;
}
