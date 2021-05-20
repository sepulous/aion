#ifndef FRACTAL_H
#define FRACTAL_H

#include <wx/wx.h>
#include "../pixel_data.h"

class Fractal
{
public:
    virtual void Render(PixelData* pixelData) = 0;
};

#endif