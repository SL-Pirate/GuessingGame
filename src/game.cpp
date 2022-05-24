#include "../headers/game.h"

Game::Game(){
    data = Data::welcome->sendData();
    data->setRandint(randint());
}

int Game::randint(int d){
        srand(time(NULL));
        return (rand() % d) + 1;
}
int Game::randint(){
        srand(time(NULL));
        return (rand() % 10) + 1;
}

void Game::check_ans(){
    if (data->getAns() == data->getRandint()){
        win();
    }
    else {
        wrong();
    }
}

void Game::win(){
    data->comment = "Congratulations... You WON!\nThe Answer was: " + std::to_string(data->getRandint()) + "\nYou used: " + std::to_string(data->getTries()) + " tries\n\nGame Over!";
    data->setGameOver();
}
void Game::fail(){
    data->comment = "You failed! Hidden number was: " + std::to_string(data->getRandint()) + "\n\nGame Over!";
    data->setGameOver();
}
void Game::retry(){
    data->comment = hint() + "\nTries remiain: " + std::to_string(data->remainingTries());
    data->incTries();
}

void Game::wrong(){
    if (data->remainingTries() > 0){
        retry();
    }
    else {
        fail();
    }
}

wxString Game::hint(){
    int v = data->getAns() - data->getRandint();
    if(abs(v) == 1){
        return "\n\nVery close";
    }
    else if(abs(v) == 2){
        return "\n\nClose";
    }
    else if(v > 0){
        return "\n\nToo high";
    }
    else if(v == 0){
        return "How did you break my game?";
    }
    else if (v < 0){
        return "\n\nToo low";
    }
    else{
        return "Something went wrong :(";
    }
}

void Game::setData(Data* data){
    this->data = data;
    this->data->setRandint(randint());
}
