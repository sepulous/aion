#include <wx/wx.h>
#include <wx/rawbmp.h>
#include <wx/event.h>
#include <wx/bannerwindow.h>
#include "render_window.h"
#include "fractals/fractal.h"

BEGIN_EVENT_TABLE(RenderWindow, wxBannerWindow)
    EVT_PAINT(RenderWindow::OnPaint)
END_EVENT_TABLE()

RenderWindow::RenderWindow(wxFrame* parent)
            : wxBannerWindow(parent)
{
    int parentWidth = parent->GetSize().GetWidth();
    int parentHeight = parent->GetSize().GetHeight();
    int width = parentWidth * 0.8;
    int height = parentHeight;
    SetSize(wxSize(width, height));
    SetPosition(wxPoint(parentWidth - width, 0));
    m_pixelData = new PixelData(width, height);
}

void RenderWindow::RenderFractal(Fractal* fractal)
{
    fractal->Render(m_pixelData);

    int width = this->GetSize().GetWidth();
    int height = this->GetSize().GetHeight();
    
    wxClientDC dc(this);
    wxBitmap b(width, height, 24);
    wxNativePixelData data(b);

    if (!data) {
        return;
    }

    wxNativePixelData::Iterator p(data);

    int currentPixelDataLocation = 0;
    auto pixelData = m_pixelData->GetData();
    for (int y = 0; y < height; y++) {
        wxNativePixelData::Iterator rowStart = p;
        for (int x = 0; x < width; x++) {
            p.Red() = pixelData[currentPixelDataLocation++];
            p.Green() = pixelData[currentPixelDataLocation++];
            p.Blue() = pixelData[currentPixelDataLocation++];
        }
        p = rowStart;
        p.OffsetY(data, 1);
    }

    m_imageBuffer = b;
    this->Refresh();
}

void RenderWindow::OnPaint(wxPaintEvent& event)
{
    wxPaintDC dc(this);
    if (m_imageBuffer.IsOk()) {
        dc.DrawBitmap(m_imageBuffer, 0, 0);
    }
}