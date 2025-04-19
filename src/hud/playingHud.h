#pragma once

#include "hud.h"
#include "raylib.h"

class PlayingHud : public Hud
{
public:
    static const unsigned char SAVE_SETTIGNS_BUTTON = 1;
    static const unsigned char EXIT_BUTTON = 2;

    PlayingHud();
    ~PlayingHud();
    void draw() override;
    unsigned char onTouch() override;
    void reset() override;

private:
    const char *settingsButtonText = GuiIconText(ICON_SETTINGS, "");
    const char *exitButtonText = "EXIT";
    const char *exitWindowText = "Are you sure you want to surrender?";
    const char *surrenderButtonText = "SURRENDER";
    const char *cancelButtonText = "CANCEL";

    const Rectangle buttonSettings = {400, 20, 60, 40};
    const Rectangle buttonExit = {20, 20, 60, 40};
    const Vector2 surrenderAnchor = {20, 200};
    const Rectangle exitWindow = {surrenderAnchor.x, surrenderAnchor.y, 440, 160};
    Vector2 exitWindowTextPosition = {surrenderAnchor.x + 20, surrenderAnchor.y + 50};
    const Rectangle buttonSurrender = {surrenderAnchor.x + 20, surrenderAnchor.y + 100, 190, 40};
    const Rectangle buttonCancel = {surrenderAnchor.x + 230, surrenderAnchor.y + 100, 190, 40};

    bool settingsButtonClicked = false;
    bool exitButtonClicked = false;
    bool surrenderButtonClicked = false;
    bool cancelButtonClicked = false;

    Font font;
    Vector2 exitWindowTextSize;

    // Settings
    Vector2 settingsContainerAnchor = {48, 120};
    // Volume
    Rectangle settingsContainer = {settingsContainerAnchor.x, settingsContainerAnchor.y, 384, 240};
    float generalVolume = 1.0f;
    const Vector2 generalVolumeLabelCoord = {settingsContainerAnchor.x + 24, settingsContainerAnchor.y + 24};
    const Rectangle generalVolumeSlider = {settingsContainerAnchor.x + 24, settingsContainerAnchor.y + 48, 336, 24};
    float musicVolume = 1.0f;
    const Vector2 musicVolumeLabelCoord = {settingsContainerAnchor.x + 24, settingsContainerAnchor.y + 96};
    const Rectangle musicVolumeSlider = {settingsContainerAnchor.x + 24, settingsContainerAnchor.y + 120, 336, 24};
    float fxVolume = 1.0f;
    const Vector2 fxVolumeLabelCoord = {settingsContainerAnchor.x + 24, settingsContainerAnchor.y + 168};
    const Rectangle fxVolumeSlider = {settingsContainerAnchor.x + 24, settingsContainerAnchor.y + 192, 336, 24};
    // Buttons
    const Rectangle saveButton = {48, 384, 384, 48};
    bool saveButtonClicked = false;
    // Labels
    const char *settingsContainerText = "SETTINGS";
    const char *saveButtonText = "SAVE";
    const char *musicVolumeLabelText = "Music Volume";
    const char *fxVolumeLabelText = "FX Volume";
    const char *generalVolumeLabelText = "General Volume";
};