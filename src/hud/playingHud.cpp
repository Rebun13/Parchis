#include "playingHud.h"

#if defined(PLATFORM_DESKTOP)
    #define GLSL_VERSION            330
#else   // PLATFORM_ANDROID, PLATFORM_WEB
    #define GLSL_VERSION            100
#endif

PlayingHud::PlayingHud()
{
    font = LoadFont("fonts/JetSet-8j1J.ttf");
    exitWindowTextSize = MeasureTextEx(font, exitWindowText, 16, 1);
    exitWindowTextPosition.x = (480.f - exitWindowTextSize.x) / 2.f;
}

PlayingHud::~PlayingHud()
{
    UnloadFont(font);
}

void PlayingHud::draw()
{
    if (GuiButton(buttonExit, exitButtonText))
    {
        exitButtonClicked = true;
    }

    if (GuiButton(buttonSettings, settingsButtonText))
    {
        settingsButtonClicked = true;
    }

    if (exitButtonClicked)
    {
        GuiPanel(exitWindow, "");
        DrawTextEx(font, exitWindowText, exitWindowTextPosition, 16, 1, GetColor(GuiGetStyle(DEFAULT, TEXT_COLOR_NORMAL)));
        if (GuiButton(buttonSurrender, surrenderButtonText))
        {
            surrenderButtonClicked = true;
        };
        if (GuiButton(buttonCancel, cancelButtonText))
        {
            cancelButtonClicked = true;
        };
    }
    if(settingsButtonClicked) {    
        if(GuiWindowBox(settingsContainer, settingsContainerText)) {
            settingsButtonClicked = false;
            // TODO: save applied settings
            saveButtonClicked = true;
        }
    
        DrawTextEx(font, generalVolumeLabelText, generalVolumeLabelCoord, 20, 5, WHITE);
        GuiSliderBar(generalVolumeSlider, "", "", &generalVolume, 0.f, 1.f);
    
        DrawTextEx(font, musicVolumeLabelText, musicVolumeLabelCoord, 20, 5, WHITE);
        GuiSliderBar(musicVolumeSlider, "", "", &musicVolume, 0.f, 1.f);
    
        DrawTextEx(font, fxVolumeLabelText, fxVolumeLabelCoord, 20, 5, WHITE);
        GuiSliderBar(fxVolumeSlider, "", "", &fxVolume, 0.f, 1.f);
    }
}

unsigned char PlayingHud::onTouch()
{
    if (surrenderButtonClicked)
    {
        reset();
        return EXIT_BUTTON;
    }
    if (saveButtonClicked)
    {
        return SAVE_SETTIGNS_BUTTON;
    }
    if (cancelButtonClicked)
    {
        reset();
    }
    return -1;
}

void PlayingHud::reset()
{
    surrenderButtonClicked = false;
    settingsButtonClicked = false;
    cancelButtonClicked = false;
    exitButtonClicked = false;
    saveButtonClicked = false;
}
