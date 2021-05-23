#ifndef FRACTAL_H
#define FRACTAL_H

#include <wx/wx.h>
#include "color_palettes.hpp"
#include "../pixel_data.hpp"

class Fractal
{
public:
    virtual void Render(PixelData* pixelData, COLOR_PALETTE colorPalette) = 0;
};

#endif