#include "raylib.h"

#define RAYGUI_IMPLEMENTATION

#include "settingsMenu.h"
#include "raygui.h"
#include "settingsMenu.h"
#include "core/settings.h"

SettingsMenu::SettingsMenu()
{
    font = LoadFont("fonts/VT323.ttf");    
    generalVolume = (float) Settings::getSetting(GENERAL_VOLUME) / 100.f;
    musicVolume = (float) Settings::getSetting(MUSIC_VOLUME) / 100.f;
    fxVolume = (float) Settings::getSetting(FX_VOLUME) / 100.f;
}

SettingsMenu::~SettingsMenu()
{
    UnloadFont(font);
}

void SettingsMenu::draw()
{
    GuiButton(exitButton, "Exit");

    GuiGroupBox(volumeContainer, "Volume");
    
    DrawTextEx(font, "General Volume", generalVolumeLabelCoord, 20, 5, WHITE);
    GuiSliderBar(generalVolumeSlider, "", "", &generalVolume, 0, 1);

    DrawTextEx(font, "Music Volume", musicVolumeLabelCoord, 20, 5, WHITE);
    GuiSliderBar(musicVolumeSlider, "", "", &musicVolume, 0, 1);

    DrawTextEx(font, "FX Volume", fxVolumeLabelCoord, 20, 5, WHITE);
    GuiSliderBar(fxVolumeSlider, "", "", &fxVolume, 0, 1);

    GuiButton(saveButton, "Save");
}

unsigned char SettingsMenu::onTouch(Vector2 coord)
{
    if (save || CheckCollisionPointRec(coord, saveButton))
    {
        // TODO: play sound
        return SAVE_BUTTON;
    }
    else if (exit || CheckCollisionPointRec(coord, exitButton))
    {
        // TODO: play sound
        return EXIT_BUTTON;
    }
    return -1;
}
