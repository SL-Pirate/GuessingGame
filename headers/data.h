#ifndef DATA_H
#define DATA_H

#include <wx/wx.h>
#include "cMain.h"
#include "welcome.h"
#include "game.h"

class Welcome;
class cMain;
class Game;

class Data{
    public:
    static cMain* main;
    static Welcome* welcome;
    int difficulty;     //1 = easy; 2 = medium; 3=hard
    bool setAns(wxString tmp_ans, cMain* frame1); //returns true if ans is set correctly (i.e. 1 <= "int" <= 10 is submitted) and if the game is not over yet
    int getAns();
    void setGame(Game* game);
    Game* getGame();
    int no_ofTries();
    void setTries(int tries);
    void incTries();    //increase the number of tries by 1
    int getTries();
    int remainingTries();

    void setRandint(int randint);
    int getRandint();

    void setGameOver();
    bool isGameOver();

    wxString comment;
    
    private:
    int tries = 1;
    int randint;
    long ans;
    bool GameOver = false;
    Game* game = nullptr;
};

#endif