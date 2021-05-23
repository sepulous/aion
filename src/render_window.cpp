#include <wx/wx.h>
#include <wx/rawbmp.h>
#include <wx/event.h>
#include <wx/bannerwindow.h>
#include "render_window.hpp"
#include "fractals/color_palettes.hpp"
#include "fractals/fractal.hpp"

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
    m_imageBuffer = new wxBitmap(width, height, 24);
    m_pixelData = new PixelData(width, height);
}

void RenderWindow::RenderFractal(Fractal* fractal, COLOR_PALETTE colorPalette)
{
    fractal->Render(m_pixelData, colorPalette);

    int width = m_pixelData->GetWidth();
    int height = m_pixelData->GetHeight();
    
    wxNativePixelData data(*m_imageBuffer);

    if (!data) {
        std::cout << "NO DATA" << std::endl;
        return;
    }

    wxNativePixelData::Iterator p(data);

    int currentPixelDataLocation = 0;
    auto pixelData = m_pixelData->GetData();
    for (int y = 0; y < height; y++) {
        wxNativePixelData::Iterator rowStart = p;
        for (int x = 0; x < width; x++, p++) {
            p.Red() = pixelData[currentPixelDataLocation++];
            p.Green() = pixelData[currentPixelDataLocation++];
            p.Blue() = pixelData[currentPixelDataLocation++];
        }
        p = rowStart;
        p.OffsetY(data, 1);
    }

    this->Refresh();
    this->Update();
}

void RenderWindow::OnPaint(wxPaintEvent& event)
{
    wxPaintDC dc(this);
    if (m_imageBuffer->IsOk()) {
        dc.DrawBitmap(*m_imageBuffer, 0, 0);
    }
}