#ifndef RENDER_WINDOW_H
#define RENDER_WINDOW_H

#include <wx/wx.h>
#include <wx/bannerwindow.h>
#include "pixel_data.hpp"
#include "fractals/color_palettes.hpp"
#include "fractals/fractal.hpp"

class RenderWindow : public wxBannerWindow
{
private:
    PixelData* m_pixelData;
    wxBitmap* m_imageBuffer;
    unsigned int* m_colorPalette;

public:
    RenderWindow(wxFrame* parent);
    void SetColorPalette();
    void RenderFractal(Fractal* fractal, COLOR_PALETTE colorPalette);
    void OnPaint(wxPaintEvent& event);

protected:
    DECLARE_EVENT_TABLE()
};

#endif