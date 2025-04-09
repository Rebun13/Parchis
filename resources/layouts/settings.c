/*******************************************************************************************
*
*   Settings v0.1.0 - First setting menu, inlsuding volume controls.
*
*   LICENSE: Propietary License
*
*   Copyright (c) 2022 Rebun. All Rights Reserved.
*
*   Unauthorized copying of this file, via any medium is strictly prohibited
*   This project is proprietary and confidential unless the owner allows
*   usage in any other form by expresely written permission.
*
**********************************************************************************************/

#include "raylib.h"

#define RAYGUI_IMPLEMENTATION
#include "raygui.h"

//----------------------------------------------------------------------------------
// Controls Functions Declaration
//----------------------------------------------------------------------------------


//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main()
{
    // Initialization
    //---------------------------------------------------------------------------------------
    int screenWidth = 800;
    int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "settings");

    // settings: controls initialization
    //----------------------------------------------------------------------------------
    // Const text
    const char *WindowBox000Text = "SAMPLE TEXT";    // WINDOWBOX: WindowBox000
    const char *volumeGroupText = "VOLUME";    // GROUPBOX: volumeGroup
    const char *BackButtonText = "BACK";    // BUTTON: BackButton
    const char *saveButtonText = "SAVE";    // BUTTON: saveButton
    const char *generalVolumeText = "";    // SLIDERBAR: generalVolume
    const char *musicVolumeText = "";    // SLIDERBAR: musicVolume
    const char *fxVolumeText = "";    // SLIDERBAR: fxVolume
    const char *musicVolumeLabelText = "Music Volume";    // LABEL: musicVolumeLabel
    const char *fxVolumeLabelText = "FX Volume";    // LABEL: fxVolumeLabel
    const char *generalVolumeLabelText = "General Volume";    // LABEL: generalVolumeLabel
    
    // Define anchors
    Vector2 anchor01 = { 72, 48 };            // ANCHOR ID:1
    Vector2 anchor02 = { 120, 168 };            // ANCHOR ID:2
    
    // Define controls variables
    bool WindowBox000Active = true;            // WindowBox: WindowBox000
    bool BackButtonPressed = false;            // Button: BackButton
    bool saveButtonPressed = false;            // Button: saveButton
    float generalVolumeValue = 0.0f;            // SliderBar: generalVolume
    float musicVolumeValue = 0.0f;            // SliderBar: musicVolume
    float fxVolumeValue = 0.0f;            // SliderBar: fxVolume

    // Define controls rectangles
    Rectangle layoutRecs[10] = {
        (Rectangle){ anchor01.x + 0, anchor01.y + 0, 480, 736 },    // WindowBox: WindowBox000
        (Rectangle){ anchor02.x + 0, anchor02.y + 0, 384, 240 },    // GroupBox: volumeGroup
        (Rectangle){ anchor01.x + 360, anchor01.y + 48, 72, 48 },    // Button: BackButton
        (Rectangle){ anchor01.x + 48, anchor01.y + 384, 384, 48 },    // Button: saveButton
        (Rectangle){ anchor02.x + 24, anchor02.y + 48, 336, 24 },    // SliderBar: generalVolume
        (Rectangle){ anchor02.x + 24, anchor02.y + 120, 336, 24 },    // SliderBar: musicVolume
        (Rectangle){ anchor02.x + 24, anchor02.y + 192, 336, 24 },    // SliderBar: fxVolume
        (Rectangle){ anchor02.x + 24, anchor02.y + 96, 336, 24 },    // Label: musicVolumeLabel
        (Rectangle){ anchor02.x + 24, anchor02.y + 168, 336, 24 },    // Label: fxVolumeLabel
        (Rectangle){ anchor02.x + 24, anchor02.y + 24, 336, 24 },    // Label: generalVolumeLabel
    };
    //----------------------------------------------------------------------------------

    SetTargetFPS(60);
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Implement required update logic
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(GetColor(GuiGetStyle(DEFAULT, BACKGROUND_COLOR))); 

            // raygui: controls drawing
            //----------------------------------------------------------------------------------
            // Draw controls
            if (WindowBox000Active)
            {
                WindowBox000Active = !GuiWindowBox(layoutRecs[0], WindowBox000Text);
                BackButtonPressed = GuiButton(layoutRecs[2], BackButtonText); 
                saveButtonPressed = GuiButton(layoutRecs[3], saveButtonText); 
            }
            GuiGroupBox(layoutRecs[1], volumeGroupText);
            GuiSliderBar(layoutRecs[4], generalVolumeText, NULL, &generalVolumeValue, 0, 100);
            GuiSliderBar(layoutRecs[5], musicVolumeText, NULL, &musicVolumeValue, 0, 100);
            GuiSliderBar(layoutRecs[6], fxVolumeText, NULL, &fxVolumeValue, 0, 100);
            GuiLabel(layoutRecs[7], musicVolumeLabelText);
            GuiLabel(layoutRecs[8], fxVolumeLabelText);
            GuiLabel(layoutRecs[9], generalVolumeLabelText);
            //----------------------------------------------------------------------------------

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}

//------------------------------------------------------------------------------------
// Controls Functions Definitions (local)
//------------------------------------------------------------------------------------

