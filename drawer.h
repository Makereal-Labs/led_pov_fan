#ifndef DRAWER_H
#define DRAWER_H

#include "arduino.h"

class Drawer{

  private:

    const char * letter;
    byte cnt;

  public:

    Drawer();
    Drawer(char * _letter);
    //Drawer(int _indent);
    char next();
    bool finished();
    
};

#endif
