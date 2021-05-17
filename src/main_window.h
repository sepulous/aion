#include <wx/wx.h>

class MainWindow : public wxFrame
{
private:
    wxPanel* controlWindow;
    wxFrame* renderWindow;

private:
    wxSize GetInitialSize();
    
public:
    MainWindow(wxString& title);
};