#include "drawer.h"

Drawer::Drawer(char * _letter) : letter(_letter){

  cnt = 0;
  
}

char Drawer::next(){

  return letter[cnt++];
      
}
bool Drawer::finished(){

  return letter[cnt-1] == 0;
      
}
