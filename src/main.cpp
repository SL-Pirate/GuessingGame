#include "../headers/cMain.h"

wxBEGIN_EVENT_TABLE(cMain, wxFrame)
    EVT_BUTTON(1010, cMain::OnButtonClicked)
    EVT_BUTTON(1011, cMain::restart)
    EVT_CLOSE(cMain::onClose)
wxEND_EVENT_TABLE()

cMain::cMain() : wxFrame(nullptr, wxID_ANY, "Guessing Game", wxPoint(250, 50), wxSize(400, 500)){
#ifdef _WIN32
    this->SetBackgroundColour(*wxWHITE);
#endif
    in = new wxStaticText(this, wxID_ANY, "Enter a number from 1 to 10", wxPoint(50, 30), wxSize(300, 100));
    txt = new wxTextCtrl(this, wxID_ANY, "", wxPoint(50, 150), wxSize(300, 50));
    btn = new wxButton(this, 1010, "Submit", wxPoint(150, 220), wxSize(100, 50));
    btn2 = new wxButton(this, 1011, "Restart", wxPoint(150, 220), wxSize(100, 50));
    btn2->Hide();
    out = new wxStaticText(this, wxID_ANY, outLabel, wxPoint(50, 290), wxSize(300, 140));

    data = Data::welcome->sendData();
    game = new Game();
}

void cMain::OnButtonClicked(wxCommandEvent &evt){
    int code = data->setAns(txt->GetValue(), this);
    if (code){
        game->check_ans();
        out->SetLabel(data->comment);
    }
    if (data->isGameOver()){
        btn->Hide();
        btn2->Show();
    }
    evt.Skip();
}
void cMain::restart(wxCommandEvent &evt){
    Restart::restart();
    evt.Skip();
}
void cMain::onClose(wxCloseEvent &evt){
    exit(EXIT_SUCCESS);
}
void cMain::reset(){
    data = Data::welcome->sendData();
    out->SetLabel(outLabel);
    btn2->Hide();
    btn->Show();
    delete(game);
    game = new Game();
}
