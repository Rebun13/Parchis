#include "raylib.h"

#define RAYGUI_IMPLEMENTATION

#include "settingsMenu.h"
#include "raygui.h"
#include "settingsMenu.h"
#include "core/settings.h"

SettingsMenu::SettingsMenu()
{
    font = LoadFont("fonts/VT323.ttf");
    generalVolume = (float)Settings::getSetting(GENERAL_VOLUME) / 100.f;
    musicVolume = (float)Settings::getSetting(MUSIC_VOLUME) / 100.f;
    fxVolume = (float)Settings::getSetting(FX_VOLUME) / 100.f;
}

SettingsMenu::~SettingsMenu()
{
    UnloadFont(font);
}

void SettingsMenu::draw()
{
    if(GuiButton(exitButton, BackButtonText)) {
        exitButtonClicked = true;
    }

    GuiGroupBox(volumeContainer, volumeContainerText);

    DrawTextEx(font, generalVolumeLabelText, generalVolumeLabelCoord, 20, 5, WHITE);
    GuiSliderBar(generalVolumeSlider, "", "", &generalVolume, 0.f, 1.f);

    DrawTextEx(font, musicVolumeLabelText, musicVolumeLabelCoord, 20, 5, WHITE);
    GuiSliderBar(musicVolumeSlider, "", "", &musicVolume, 0.f, 1.f);

    DrawTextEx(font, fxVolumeLabelText, fxVolumeLabelCoord, 20, 5, WHITE);
    GuiSliderBar(fxVolumeSlider, "", "", &fxVolume, 0.f, 1.f);

    if (GuiButton(saveButton, saveButtonText)) {
        saveButtonClicked = true;
    }
}

unsigned char SettingsMenu::onTouch(Vector2 coord)
{
    if (saveButtonClicked /*|| CheckCollisionPointRec(coord, saveButton)*/)
    {
        // TODO: play sound
        return SAVE_BUTTON;
    }
    else if (exitButtonClicked /* || CheckCollisionPointRec(coord, exitButton)*/)
    {
        // TODO: play sound
        return EXIT_BUTTON;
    }
    return -1;
}
