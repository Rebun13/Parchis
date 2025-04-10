#pragma once

#define RAYGUI_IMPLEMENTATION
#define RAYGUI_CUSTOM_ICONS
#include "ricons.h"
#include "raygui.h"

#include "dark.h"
#include <stdlib.h> // for malloc
#include <cstring>  // for memcpy

// Style loading function: Dark
static void GuiLoadStyleDark(void)
{
    // Load style properties provided
    // NOTE: Default properties are propagated
    for (int i = 0; i < DARK_STYLE_PROPS_COUNT; i++)
    {
        GuiSetStyle(darkStyleProps[i].controlId, darkStyleProps[i].propertyId, darkStyleProps[i].propertyValue);
    }

    // Custom font loading
    // NOTE: Compressed font image data (DEFLATE), it requires DecompressData() function
    int darkFontDataSize = 0;
    unsigned char *data = DecompressData(darkFontData, DARK_STYLE_FONT_ATLAS_COMP_SIZE, &darkFontDataSize);
    Image imFont = {data, 256, 256, 1, 2};

    Font font = {0};
    font.baseSize = 14;
    font.glyphCount = 95;

    // Load texture from image
    font.texture = LoadTextureFromImage(imFont);
    UnloadImage(imFont); // Uncompressed image data can be unloaded from memory

    // Copy char recs data from global fontRecs
    // NOTE: Required to avoid issues if trying to free font
    font.recs = (Rectangle *)RAYGUI_MALLOC(font.glyphCount * sizeof(Rectangle));
    memcpy(font.recs, darkFontRecs, font.glyphCount * sizeof(Rectangle));

    // Copy font char info data from global fontChars
    // NOTE: Required to avoid issues if trying to free font
    font.glyphs = (GlyphInfo *)RAYGUI_MALLOC(font.glyphCount * sizeof(GlyphInfo));
    memcpy(font.glyphs, darkFontGlyphs, font.glyphCount * sizeof(GlyphInfo));

    GuiSetFont(font);

    // Setup a white rectangle on the font to be used on shapes drawing,
    // it makes possible to draw shapes and text (full UI) in a single draw call
    Rectangle fontWhiteRec = {254, 254, 1, 1};
    SetShapesTexture(font.texture, fontWhiteRec);

    //-----------------------------------------------------------------

    // TODO: Custom user style setup: Set specific properties here (if required)
    // i.e. Controls specific BORDER_WIDTH, TEXT_PADDING, TEXT_ALIGNMENT
}
