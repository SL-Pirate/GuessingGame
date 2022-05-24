#include "../headers/cApp.h"

wxIMPLEMENT_APP(cApp);

bool cApp::OnInit(){;
    Data::welcome = new Welcome();
    Data::main = new cMain();
    Data::welcome->Show();

    return true;
}