#ifndef C_APP_H
#define C_APP_H

#include <wx/wx.h>
#include "welcome.h"
#include "data.h"

class Welcome;
class cMain;
class Data;

class cApp : public wxApp{
    public:
    virtual bool OnInit();
};

#endif