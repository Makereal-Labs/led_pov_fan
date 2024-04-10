#ifndef DRAW_MANAGER_H
#define DRAW_MANAGER_H

#include "drawer.h"
#include "arduino.h"
#include "led_definition.h"

class drawManager{

  private:

    unsigned long last_rnd;
    unsigned long rnd_time;
    const byte startpos;
    byte pos;
    byte cnt;
    char* letters;;
    Drawer * cur_letter;

  public:

    drawManager();
    drawManager(char* , byte);
    void time_update();
    void pos_update();
    void draw();
    void test();
    void next();

  
};

#endif
