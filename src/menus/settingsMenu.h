#pragma once

#include "menu.h"
#include "raylib.h"

class SettingsMenu : public Menu
{
public:
    static const unsigned char SAVE_BUTTON = 0;
    static const unsigned char EXIT_BUTTON = 1;

    SettingsMenu();
    ~SettingsMenu();
    void draw();
    unsigned char onTouch(Vector2 coord);

private:
    // Volume
    Rectangle volumeContainer = {70, 90, 390, 370};
    float generalVolume = 1.0f;
    const Vector2 generalVolumeLabelCoord = {80, 100};
    const Rectangle generalVolumeSlider = {80, 140, 300, 20};
    float musicVolume = 1.0f;
    const Vector2 musicVolumeLabelCoord = {80, 200};
    const Rectangle musicVolumeSlider = {80, 240, 300, 20};
    float fxVolume = 1.0f;
    const Vector2 fxVolumeLabelCoord = {80, 300};
    const Rectangle fxVolumeSlider = {80, 340, 300, 20};
    // Buttons
    const Rectangle saveButton = {300, 400, 80, 50};
    int save = 0;
    const Rectangle exitButton = {10, 10, 50, 50};
    int exit = 0;

    Font font;
};