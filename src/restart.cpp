#include "../headers/restart.h"

void Restart::restart(){
   delete(Data::welcome->sendData());
   Data* newData = new Data();
   Data::welcome->setData(newData);
   Data::main->reset();
   Data::main->txt->SetValue("");

   Data::main->Hide();
   Data::welcome->Show();
}
