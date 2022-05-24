#include "../headers/cApp.h"

Welcome* Data::welcome = nullptr;
cMain* Data::main = nullptr;

void Data::setGame(Game* game){
    this->game = game;
}
Game* Data::getGame(){
    return game;
}

void Data::setRandint(int randint){
    this->randint = randint;
}
int Data::getRandint(){
    return randint;
}

int Data::no_ofTries(){
    switch(difficulty){
        case 1:
            return 6;
        case 2:
            return 4;
        case 3:
            return 2;
        default:
            return 4;
    }
}
void Data::setTries(int tries){
    this->tries = tries;
}
void Data::incTries(){
    this->tries++;
}
int Data::getTries(){
    return tries;
}
int Data::remainingTries(){
    return (no_ofTries() - tries);
}

void Data::setGameOver(){
    GameOver = true;
}
bool Data::isGameOver(){
    return GameOver;
}

bool Data::setAns(wxString tmp_ans, cMain* frame1){
    bool return_code = false;
    try{
        long tmp_long = 0;
        bool tmp_bool = true; //true if text input havent changed
        bool successful = tmp_ans.ToLong(&tmp_long);
        if (tmp_long == ans){
            tmp_bool = true;    //input havent changed
        }
        else{
            ans = tmp_long;
            tmp_bool = false;   //input has changed
        }
        if (successful && ans >= 1 && 10 >= ans) {
            if (GameOver || tmp_bool){
                throw -2;
            }
            return_code = true;
        }
        else{
            int x;
            x = -1;
            throw x;
        }
    }
    catch(int x){
        if (x == -1){
            frame1->out->SetLabel("Error: \nPlease enter a integer from 1 to 10");
            return_code = false;
        }
        else if(x == -2){
            return_code = false;
        }
    }
    catch(std::exception e){
        ans = 0;
        frame1->out->SetLabel("Error: \nPlease enter a integer from 1 to 10");
        std::cout << "Error: " << e.what() << std::endl;

        return_code = false;
    }

    return return_code;
}
int Data::getAns(){
    return ans;
}
