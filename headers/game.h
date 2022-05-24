#ifndef GAME_H
#define GAME_H

#include "data.h"
#include <time.h>
#include <stdlib.h>

class Data;
class Welcome;

class Game {
    public:
    Game();

    int randint(int d);
    int randint();
    void setData(Data* data);
    void check_ans();

    private:
    Data* data = nullptr;
    void win();
    void wrong();
    void retry();
    void fail();
    wxString hint();
};

#endif