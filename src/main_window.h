#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <wx/wx.h>
#include <wx/bannerwindow.h>

class MainWindow : public wxFrame
{
private:
    wxPanel* controlWindow;
    wxBannerWindow* renderWindow;

private:
    wxSize GetInitialSize();
    
public:
    MainWindow(wxString& title);
};

#endif