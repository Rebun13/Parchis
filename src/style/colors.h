#ifndef COLORS_H
#define COLORS_H

#include "raylib.h"

const Color bgColor = {37, 53, 92, 255};
const Color bgColorAlt = {33, 89, 219, 255};

const Color primaryColor = {163, 224, 66, 50};
const Color primaryColorHover = {142, 179, 79, 255};
const Color primaryColorPress = {78, 92, 53, 255};

const Color secondaryColor = {160, 94, 66, 255};
const Color secondaryColorHover = {163, 78, 41, 255};
const Color secondaryColorPress = {160, 94, 66, 255};

const Color fontColor = {0, 0,0,255};

enum ColorIndex
{
    BG_COLOR,
    BG_COLOR_ALT,
    PRIMARY_COLOR,
    PRIMARY_COLOR_HOVER,
    PRIMARY_COLOR_PRESS,
    SECONDARY_COLOR,
    SECONDARY_COLOR_HOVER,
    SECONDARY_COLOR_PRESS,
    FONT_COLOR
};

inline Color GetThemeColor(ColorIndex index)
{
    switch (index)
    {
    case BG_COLOR:
        return bgColor;
    case BG_COLOR_ALT:
        return bgColorAlt;
    case PRIMARY_COLOR:
        return primaryColor;
    case PRIMARY_COLOR_HOVER:
        return primaryColorHover;
    case PRIMARY_COLOR_PRESS:
        return primaryColorPress;
    case SECONDARY_COLOR:
        return secondaryColor;
    case SECONDARY_COLOR_HOVER:
        return secondaryColorHover;
    case SECONDARY_COLOR_PRESS:
        return secondaryColorPress;
    case FONT_COLOR:
    return fontColor;
    default:
        return {0, 0, 0, 255}; // Default to black if index is invalid
    }
}

#endif