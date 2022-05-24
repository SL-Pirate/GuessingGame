#include "../headers/welcome.h"

wxBEGIN_EVENT_TABLE(Welcome, wxFrame)
    EVT_BUTTON(02, Welcome::selectEasy)
    EVT_BUTTON(03, Welcome::selectMedium)
    EVT_BUTTON(04, Welcome::selectHard)
    EVT_CLOSE(Welcome::onClose)
wxEND_EVENT_TABLE()

Welcome::Welcome() : wxFrame(nullptr, wxID_ANY, "Select difficulty", wxPoint(100, 100), wxSize(400, 400)){
    data = new Data();

#ifdef _WIN32
    this->SetBackgroundColour(*wxWHITE);
#endif
    note = new wxStaticText(this, 01, "", wxPoint(50, 20), wxSize(300, 100));
    easy = new wxButton(this, 02, "Easy", wxPoint(150, 140), wxSize(100, 50));
    medium = new wxButton(this, 03, "Medium/Normal", wxPoint(100, 210), wxSize(200, 50));
    hard = new wxButton(this, 04, "Hard", wxPoint(150, 280), wxSize(100, 50));

    note->SetLabel("Welcome to Guessing Game\nPlease select difficlty");
}

void Welcome::selectEasy(wxCommandEvent &evt){
    end(1);
    evt.Skip();

}
void Welcome::selectMedium(wxCommandEvent &evt){
    end(2);
    evt.Skip();
}
void Welcome::selectHard(wxCommandEvent &evt){
    end(3);
    evt.Skip();
}
void Welcome::onClose(wxCloseEvent &evt){
    exit(EXIT_SUCCESS);
}

void Welcome::end(int difficulty){
    data->difficulty = difficulty;
    this->Hide();
    Data::main->Show();
}

Data* Welcome::sendData(){
    return data;
}
void Welcome::setData(Data* data){
    this->data = data;
}
