#ifndef RENDER_WINDOW_H
#define RENDER_WINDOW_H

#include <wx/wx.h>
#include <wx/bannerwindow.h>
#include "pixel_data.h"
#include "fractals/fractal.h"

class RenderWindow : public wxBannerWindow
{
private:
    PixelData* m_pixelData;
    wxBitmap m_imageBuffer;
    unsigned int* m_colorPalette;

public:
    RenderWindow(wxFrame* parent);
    void SetColorPalette();
    void RenderFractal(Fractal* fractal);
    void OnPaint(wxPaintEvent& event);

protected:
    DECLARE_EVENT_TABLE()
};

#endif