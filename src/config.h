#pragma once

#define WINDOW_HEIGHT 720
#define WINDOW_WIDTH 480
#define WINDOW_TITLE "Parchix"

#define TARGET_FPS 60

#if defined(PLATFORM_DESKTOP)
    #define GLSL_VERSION            330
#else   // PLATFORM_ANDROID, PLATFORM_WEB
    #define GLSL_VERSION            100
#endif

#define TURN_MAX_DURATION 30