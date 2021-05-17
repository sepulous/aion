#include <wx/wx.h>
#include <wx/display.h>
#include "main_window.h"

MainWindow::MainWindow(wxString& title) : wxFrame(nullptr, wxID_ANY, title)
{
    SetSize(GetInitialSize());
    Centre();
}

wxSize MainWindow::GetInitialSize()
{
    wxDisplay display;
    wxRect screen = display.GetClientArea();
    int width  = (int)(screen.GetWidth() * 0.8);
    int height = (int)(screen.GetHeight() * 0.8);
    return wxSize(width, height);
}