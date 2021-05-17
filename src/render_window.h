#include <wx/wx.h>
#include "control_window.h"

class RenderWindow : public wxFrame
{
private:
    unsigned char* imageData;
    unsigned int* colorPalette;

public:
    RenderWindow();
    void SetColorPalette();
    void RenderFractal();
};