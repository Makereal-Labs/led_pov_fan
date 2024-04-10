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
    char letters[90];
    Drawer * cur_letter;

  public:

    drawManager();
    drawManager(char * , byte);
    void time_update();
    void pos_update();
    void draw_number();
    void draw_pin();
    void update_letters(char, char, char);
    void test();
    void next();

  
};

#endif
