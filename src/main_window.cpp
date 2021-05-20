#include <wx/wx.h>
#include <wx/display.h>
#include "main_window.h"
#include "control_window.h"
#include "render_window.h"

MainWindow::MainWindow(wxString& title) : wxFrame(nullptr, wxID_ANY, title)
{
    SetSize(GetInitialSize());
    Centre();

    wxBoxSizer* sizer = new wxBoxSizer(wxHORIZONTAL);
    RenderWindow* renderWindow = new RenderWindow(this);
    ControlWindow* controlWindow = new ControlWindow(this, renderWindow);
}

wxSize MainWindow::GetInitialSize()
{
    wxDisplay display;
    wxRect screen = display.GetClientArea();
    int width  = (int)(screen.GetWidth() * 0.8);
    int height = (int)(screen.GetHeight() * 0.8);
    return wxSize(width, height);
}