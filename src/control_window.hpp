#ifndef CONTROL_WINDOW_H
#define CONTROL_WINDOW_H

#include <unordered_map>
#include <wx/wx.h>
#include "render_window.hpp"
#include "fractals/fractal.hpp"
#include "fractals/color_palettes.hpp"

#define FRACTAL_DROPDOWN 10
#define PALETTE_DROPDOWN 11
#define RENDER_BUTTON 12

class ControlWindow : public wxPanel
{
private:
    RenderWindow* renderWindow;
    wxComboBox* fractalDropdown;
    wxComboBox* paletteDropdown;
    wxButton* renderButton;
    std::unordered_map<wxString, Fractal*> fractalMap;
    std::unordered_map<wxString, COLOR_PALETTE> paletteMap;

public:
    ControlWindow(wxFrame* parent, RenderWindow* renderWindow);
    void RenderFractal(wxCommandEvent& event);

private:
    DECLARE_EVENT_TABLE()
};

#endif