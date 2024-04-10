#include "drawer.h"
#include "draw_manager.h"
#define HALL_PIN 2

char * s = "042435";
drawManager fan = drawManager(s,30);

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
    while(digitalRead(HALL_PIN) == LOW);
    
  }

  fan.draw();
  
}
