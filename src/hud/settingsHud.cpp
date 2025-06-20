#include "settingsHud.h"
#include "core/settings.h"
#include "hud/buttons.h"
#include "style/colors.h"
#include "core/gameInterface.h"

SettingsHud::SettingsHud() {
  font = GameInterface::getGameInstance()->getFont();
  generalVolume = (float)Settings::getSetting(GENERAL_VOLUME) / 100.f;
  musicVolume = (float)Settings::getSetting(MUSIC_VOLUME) / 100.f;
  fxVolume = (float)Settings::getSetting(FX_VOLUME) / 100.f;
}

SettingsHud::~SettingsHud() { }

void SettingsHud::draw() {
  if (drawButton(exitButton, BackButtonText, 20, GetThemeColor(ThemeColor::PRIMARY_COLOR),
                 GetThemeColor(ThemeColor::PRIMARY_COLOR_HOVER),
                 GetThemeColor(ThemeColor::PRIMARY_COLOR_PRESS))) {
    exitButtonClicked = true;
  }

  drawSlider(generalVolumeSlider, generalVolumeLabelText, generalVolume,
             GetThemeColor(ThemeColor::PRIMARY_COLOR), GetThemeColor(ThemeColor::PRIMARY_COLOR_HOVER),
             GetThemeColor(ThemeColor::PRIMARY_COLOR_PRESS));

  drawSlider(musicVolumeSlider, musicVolumeLabelText, musicVolume,
             GetThemeColor(ThemeColor::PRIMARY_COLOR), GetThemeColor(ThemeColor::PRIMARY_COLOR_HOVER),
             GetThemeColor(ThemeColor::PRIMARY_COLOR_PRESS));

  drawSlider(fxVolumeSlider, fxVolumeLabelText, fxVolume,
             GetThemeColor(ThemeColor::PRIMARY_COLOR), GetThemeColor(ThemeColor::PRIMARY_COLOR_HOVER),
             GetThemeColor(ThemeColor::PRIMARY_COLOR_PRESS));

  if (drawButton(saveButton, saveButtonText, 20, GetThemeColor(ThemeColor::PRIMARY_COLOR),
                 GetThemeColor(ThemeColor::PRIMARY_COLOR_HOVER),
                 GetThemeColor(ThemeColor::PRIMARY_COLOR_PRESS))) {
    saveButtonClicked = true;
  }
}

unsigned char SettingsHud::handleInput() {
  if (saveButtonClicked /*|| CheckCollisionPointRec(coord, saveButton)*/) {
    // TODO: play sound
    reset();
    return SAVE_BUTTON;
  } else if (
      exitButtonClicked /* || CheckCollisionPointRec(coord, exitButton)*/) {
    // TODO: play sound
    reset();
    return EXIT_BUTTON;
  }
  return -1;
}

void SettingsHud::reset() {
  saveButtonClicked = false;
  exitButtonClicked = false;
}

void SettingsHud::update() {
}