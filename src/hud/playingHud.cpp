#include "playingHud.h"
#include "hud/buttons.h"
#include "raylib.h"
#include "style/colors.h"
#include "core/gameInterface.h"

#if defined(PLATFORM_DESKTOP)
#define GLSL_VERSION 330
#else // PLATFORM_ANDROID, PLATFORM_WEB
#define GLSL_VERSION 100
#endif

PlayingHud::PlayingHud() {
  font = GameInterface::getGameInstance()->getFont();
  exitWindowTextSize = MeasureTextEx(*font, exitWindowText, 16, 1);
  exitWindowTextPosition.x = (480.f - exitWindowTextSize.x) / 2.f;
}

PlayingHud::~PlayingHud() { }

void PlayingHud::draw() {
  if (drawButton(buttonExit, exitButtonText, 20, GetThemeColor(PRIMARY_COLOR),
                 GetThemeColor(PRIMARY_COLOR_HOVER),
                 GetThemeColor(PRIMARY_COLOR_PRESS))) {
    exitButtonClicked = true;
  }

  if (drawButton(buttonSettings, settingsButtonText, 15 ,
                 GetThemeColor(PRIMARY_COLOR),
                 GetThemeColor(PRIMARY_COLOR_HOVER),
                 GetThemeColor(PRIMARY_COLOR_PRESS))) {
    settingsButtonClicked = true;
  }

  if (exitButtonClicked) {
    DrawRectangleRec(exitWindow, GetThemeColor(BG_COLOR_ALT));
    DrawTextEx(*font, exitWindowText, exitWindowTextPosition, 16, 1,
               GetThemeColor(FONT_COLOR));
    if (drawButton(buttonSurrender, surrenderButtonText, 20,
                   GetThemeColor(PRIMARY_COLOR),
                   GetThemeColor(PRIMARY_COLOR_HOVER),
                   GetThemeColor(PRIMARY_COLOR_PRESS))) {
      surrenderButtonClicked = true;
    };
    if (drawButton(buttonCancel, cancelButtonText, 20,
                   GetThemeColor(PRIMARY_COLOR),
                   GetThemeColor(PRIMARY_COLOR_HOVER),
                   GetThemeColor(PRIMARY_COLOR_PRESS))) {
      cancelButtonClicked = true;
    };
  }
  if (settingsButtonClicked) {
    DrawRectangleRec(settingsContainer, GetThemeColor(BG_COLOR_ALT));
    if (drawButton(settingsContainer.x + 20, 2, settingsContainer.y + 2, 20,
                   "Exit", 20, GetThemeColor(SECONDARY_COLOR),
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

unsigned char PlayingHud::handleInput() {
  if (surrenderButtonClicked) {
    reset();
    return EXIT_BUTTON;
  }
  if (saveButtonClicked) {
    return SAVE_SETTINGS_BUTTON;
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

void PlayingHud::update() {}