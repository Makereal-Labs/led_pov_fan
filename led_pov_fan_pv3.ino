#include "drawer.h"
#include "draw_manager.h"
#define HALL_PIN 2

#include <stdlib.h>
#include <TimeLib.h>


drawManager fan = drawManager("04:24:35",33, 4);

void setup() {

  //Serial.begin(9600);

  pinMode(HALL_PIN, INPUT);
  for(byte i = 0; i < 7; ++i) pinMode(red_leds[i], OUTPUT);
  for(byte i = 0; i < 5; ++i) pinMode(blue_leds[i], OUTPUT);

}

void loop() {

  bool detected = digitalRead(HALL_PIN) == LOW;

  if(detected){

    fan.time_update();
    fan.update_letters(hour(), minute(), second());
    
  }

  fan.draw_number();
  fan.draw_img();
  //fan.draw_pin();
  //fan.draw_frame();
  
}
