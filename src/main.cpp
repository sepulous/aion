#include <iostream>
#include "main_window.h"

#define AION_VERSION "0.1.0-indev"

class Aion : public wxApp
{
public:
  bool OnInit()
  {
    wxString title;
    title.Printf(wxT("Aion v%s"), AION_VERSION);
    MainWindow* window = new MainWindow(title);
    window->Show(true);
    return true;
  }
};

IMPLEMENT_APP(Aion)
