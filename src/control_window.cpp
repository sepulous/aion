#include <wx/wx.h>
#include "control_window.hpp"
#include "render_window.hpp"
#include "fractals/color_palettes.hpp"
#include "fractals/fractal.hpp"
#include "fractals/mandelbrot.hpp"

wxBEGIN_EVENT_TABLE(ControlWindow, wxPanel)
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

    paletteMap.emplace(wxT("Summer Palette"), PALETTE_SUMMER);
    paletteMap.emplace(wxT("Fall Palette"), PALETTE_FALL);
    paletteMap.emplace(wxT("Winter Palette"), PALETTE_WINTER);
    paletteMap.emplace(wxT("Spring Palette"), PALETTE_SPRING);
    paletteMap.emplace(wxT("Cotton Candy"), PALETTE_COTTON_CANDY);

    int dropdownWidth = width * 0.8;
    int dropdownHeight = 35;
    int dropdownXOffset = width * 0.1;

    // Fractal dropdown
    fractalDropdown = new wxComboBox(this, FRACTAL_DROPDOWN);
    int fractalDropdownYOffset = 10;
    fractalDropdown->SetEditable(false);
    fractalDropdown->SetSize(wxSize(dropdownWidth, dropdownHeight));
    fractalDropdown->SetPosition(wxPoint(dropdownXOffset, fractalDropdownYOffset));
    for (auto fractal : fractalMap) {
        fractalDropdown->Append(fractal.first);
    }
    fractalDropdown->SetSelection(0);

    // Color palette dropdown
    paletteDropdown = new wxComboBox(this, PALETTE_DROPDOWN);
    int paletteDropdownYOffset = fractalDropdownYOffset + dropdownHeight + 10;
    paletteDropdown->SetEditable(false);
    paletteDropdown->SetSize(wxSize(dropdownWidth, dropdownHeight));
    paletteDropdown->SetPosition(wxPoint(dropdownXOffset, paletteDropdownYOffset));
    for (auto palette : paletteMap) {
        paletteDropdown->Append(palette.first);
    }
    paletteDropdown->SetSelection(0);

    // Render button
    renderButton = new wxButton(this, RENDER_BUTTON, "Render");
    int renderButtonWidth = width * 0.4;
    int renderButtonHeight = 30;
    int renderButtonXOffset = width * 0.3;
    int renderButtonYOffset = paletteDropdownYOffset + dropdownHeight + 10;
    renderButton->SetSize(wxSize(renderButtonWidth, renderButtonHeight));
    renderButton->SetPosition(wxPoint(renderButtonXOffset, renderButtonYOffset));
}

void ControlWindow::RenderFractal(wxCommandEvent& event)
{
    Fractal* selectedFractal = fractalMap[fractalDropdown->GetStringSelection()];
    COLOR_PALETTE selectedPalette = paletteMap[paletteDropdown->GetStringSelection()];
    renderWindow->RenderFractal(selectedFractal, selectedPalette);
}