#pragma once

#include "raylib.h"
#include "hud.h"

class SettingsHud : public Hud
{
public:
    static const unsigned char SAVE_BUTTON = 0;
    static const unsigned char EXIT_BUTTON = 1;

    SettingsHud();
    ~SettingsHud();
    void draw() final;
    unsigned char handleInput() final;
    void reset() final;
    void update() final;

private:
    Vector2 volumeContainerAnchor = {48, 120};
    // Volume
    Rectangle volumeContainer = {volumeContainerAnchor.x, volumeContainerAnchor.y, 384, 240};

    float generalVolume = 1.0f;
    const Rectangle generalVolumeSlider = {volumeContainerAnchor.x + 24, volumeContainerAnchor.y + 48, 336, 48};

    float musicVolume = 1.0f;
    const Rectangle musicVolumeSlider = {volumeContainerAnchor.x + 24, volumeContainerAnchor.y + 120, 336, 48};

    float fxVolume = 1.0f;
    const Rectangle fxVolumeSlider = {volumeContainerAnchor.x + 24, volumeContainerAnchor.y + 192, 336, 48};
    // Buttons
    const Rectangle saveButton = {48, 384, 384, 48};
    bool saveButtonClicked = false;
    const Rectangle exitButton = {360, 48, 72, 48};
    bool exitButtonClicked = false;
    // Labels
    const char *volumeContainerText = "VOLUME";
    const char *BackButtonText = "BACK";
    const char *saveButtonText = "SAVE";
    const char *musicVolumeLabelText = "Music Volume";
    const char *fxVolumeLabelText = "FX Volume";
    const char *generalVolumeLabelText = "General Volume";

    Font *font;
};