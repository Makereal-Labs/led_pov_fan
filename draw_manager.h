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

    unsigned long hour_angle=0, min_angle=0, sec_angle=0;
    unsigned long frame_angle = 0;
    unsigned long frame_cnt = 0;
    unsigned long img_cnt = 0;
    int angle_offset;
    bool hour_printed = 0, min_printed = 0;

  public:

    drawManager();
    drawManager(char * , byte, int);
    void time_update();
    void pos_update();
    void draw_number();
    void draw_pin();
    void draw_frame();
    void draw_img();
    void update_letters(char, char, char);
    void test();
    void next();

  
};

#endif
