#include <wx/wx.h>
#include "control_window.h"
#include "render_window.h"
#include "fractals/fractal.h"
#include "fractals/mandelbrot.h"

wxBEGIN_EVENT_TABLE(ControlWindow, wxPanel)
    EVT_COMBOBOX(FRACTAL_DROPDOWN, ControlWindow::ChangeSelectedColorPalette)
    EVT_BUTTON(RENDER_BUTTON, ControlWindow::RenderFractal)
wxEND_EVENT_TABLE()

ControlWindow::ControlWindow(wxFrame* parent, RenderWindow* renderWindow)
             : wxPanel(parent, wxID_ANY)
{
    this->renderWindow = renderWindow;
    int width = parent->GetSize().GetWidth() * 0.2;
    int height = parent->GetSize().GetHeight();
    SetSize(wxSize(width, height));

    fractalMap.emplace(wxT("Mandelbrot"), new Mandelbrot());

    fractalDropdown = new wxComboBox(this, FRACTAL_DROPDOWN);
    int fractalDropdownWidth = width * 0.8;
    int fractalDropdownHeight = 35;
    int fractalDropdownXOffset = width * 0.1;
    int fractalDropdownYOffset = 10;
    fractalDropdown->SetSize(wxSize(fractalDropdownWidth, fractalDropdownHeight));
    fractalDropdown->SetPosition(wxPoint(fractalDropdownXOffset, fractalDropdownYOffset));
    for (auto fractal : fractalMap) {
        fractalDropdown->Append(fractal.first);
    }
    fractalDropdown->SetSelection(0);

    renderButton = new wxButton(this, RENDER_BUTTON, "Render");
    int renderButtonWidth = width * 0.4;
    int renderButtonHeight = 30;
    int renderButtonXOffset = width * 0.3;
    int renderButtonYOffset = fractalDropdownYOffset + fractalDropdownHeight + 10;
    renderButton->SetSize(wxSize(renderButtonWidth, renderButtonHeight));
    renderButton->SetPosition(wxPoint(renderButtonXOffset, renderButtonYOffset));
}

void ControlWindow::ChangeSelectedColorPalette(wxCommandEvent& event)
{

}

void ControlWindow::RenderFractal(wxCommandEvent& event)
{
    Fractal* selectedFractal = fractalMap[fractalDropdown->GetStringSelection()];
    renderWindow->RenderFractal(selectedFractal);
}