#ifndef C_MAIN_H
#define C_MAIN_H

#include "data.h"
#include "game.h"
#include "restart.h"

class Game;
class Data;

class cMain : public wxFrame{
    public:
    cMain();

    wxButton* btn = nullptr;
    wxButton* btn2 = nullptr;
    wxTextCtrl* txt = nullptr;
    wxStaticText* out = nullptr;
    wxStaticText* in = nullptr;
    wxString outLabel = "\n\n\tResult goes here";

    void OnButtonClicked(wxCommandEvent &evt);
    void onClose(wxCloseEvent &evt);
    void restart(wxCommandEvent &evt);
    void reset();

    wxDECLARE_EVENT_TABLE();

    private:
    Game* game = nullptr;
    Data* data = nullptr;
};

#endif