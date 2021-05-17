#include <wx/wx.h>
#include "render_window.h"

class ControlWindow : wxPanel
{
private:
    RenderWindow* renderWindow;

public:
    ControlWindow(RenderWindow* renderWindow);
};