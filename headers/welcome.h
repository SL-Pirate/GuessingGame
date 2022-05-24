#ifndef WELCOME_H
#define WELCOME_H

#include "data.h"

class Data;
class cMain;

class Welcome : public wxFrame{
    public:
    Welcome();
    wxStaticText* note = nullptr;
    wxButton* easy = nullptr;
    wxButton* medium = nullptr;
    wxButton* hard = nullptr;
    Data* sendData();
    void setData(Data* data);

    void selectEasy(wxCommandEvent &evt);
    void selectMedium(wxCommandEvent &evt);
    void selectHard(wxCommandEvent &evt);
    void onClose(wxCloseEvent &evt);

    wxDECLARE_EVENT_TABLE();

    private:
    void end(int difficulty);
    Data* data = nullptr;
};

#endif