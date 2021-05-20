#ifndef CONTROL_WINDOW_H
#define CONTROL_WINDOW_H

#include <unordered_map>
#include <wx/wx.h>
#include "render_window.h"
#include "fractals/fractal.h"

#define FRACTAL_DROPDOWN 10
#define RENDER_BUTTON 11

class ControlWindow : public wxPanel
{
private:
    RenderWindow* renderWindow;
    wxComboBox* fractalDropdown;
    wxButton* renderButton;
    std::unordered_map<wxString, Fractal*> fractalMap;

public:
    ControlWindow(wxFrame* parent, RenderWindow* renderWindow);
    void ChangeSelectedColorPalette(wxCommandEvent& event);
    void RenderFractal(wxCommandEvent& event);

private:
    DECLARE_EVENT_TABLE()
};

#endif