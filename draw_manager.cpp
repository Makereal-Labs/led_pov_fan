#include "draw_manager.h"
#include "led_letters.h"
#include "arduino.h"
#include <TimeLib.h>
#define DISPLAY 90

void led_OFF(){

  for(byte i = 0; i < 7; ++i) digitalWrite(red_leds[i], LOW);
  for(byte i = 0; i < 5; ++i) digitalWrite(blue_leds[i], LOW);
  
}

void led_ON(){

  for(byte i = 0; i < 7; ++i) digitalWrite(red_leds[i], HIGH);
  for(byte i = 0; i < 5; ++i) digitalWrite(blue_leds[i], HIGH);
  
}

drawManager::drawManager(char * _letters , byte _startpos, int _angle_offset) : startpos(_startpos){

    sprintf(letters, "%s", _letters);
    cnt = 0;
    pos = _startpos;
    last_rnd = 0;
    rnd_time = 200;
    angle_offset = _angle_offset;
    cur_letter = new Drawer(ascii_letters[letters[cnt]]);

};

void drawManager::time_update(){

    if((micros()-last_rnd)<<1 < rnd_time) return;
    
    led_OFF();
    rnd_time = micros() - last_rnd;
    last_rnd = micros();
    pos = startpos;
    cnt = 0;
    
    hour_angle = ((((hour()%12+6)%12)*30 + (byte)(minute()*0.5) + angle_offset)%360)*rnd_time;
    min_angle = (((minute()+30)%60 * 6 + angle_offset)%360)*rnd_time;
    hour_printed = 0, min_printed = 0;

    frame_cnt = angle_offset;
    frame_angle = (frame_cnt*rnd_time);
    
    free(cur_letter);
    cur_letter = new Drawer(ascii_letters[letters[cnt]]);
  
}

void drawManager::draw_pin(){

  //hour pin = 0.5 x min + 30 x (hour%12)
  unsigned long cangle = (micros()-last_rnd) * 360;

  if(!min_printed && cangle > min_angle){

    for(int i = 0; i < 5; ++i){

      digitalWrite(red_leds[i], HIGH);
      
    }
    for(int i = 0; i < 5; ++i){

      digitalWrite(red_leds[i], LOW);
      
    }
    min_printed = true;
    
  }
  
  if(!hour_printed && cangle > hour_angle){

    for(int i = 0; i < 3; ++i){

      digitalWrite(red_leds[i], HIGH);
      
    }
    for(int i = 0; i < 3; ++i){

      digitalWrite(red_leds[i], LOW);
      
    }
    hour_printed = true;
    
  }
}

void drawManager::draw_frame(){

  unsigned long cangle = (micros()-last_rnd) * 360;

  digitalWrite(red_leds[6], LOW);
  if(cangle > frame_angle){

      digitalWrite(red_leds[6], HIGH);
      digitalWrite(red_leds[6], LOW);

      frame_cnt += 30;
      frame_angle = (frame_cnt*rnd_time);
    
  }
  
  
}

void drawManager::test(){

  if((micros()-last_rnd) * 2 > rnd_time) led_ON();
  else led_OFF();
  
}

void drawManager::draw_number(){

  //digitalWrite(3,(*letter_ptr - '0' < 10 && *letter_ptr - '0' > 0)?HIGH:LOW);
   if(letters[cnt] == '\0') return;

  if((micros() - last_rnd)*DISPLAY > rnd_time*pos){
    
    char col = cur_letter->next();
    for(byte i = 0; i < 5; ++i){
  
      digitalWrite(blue_leds[i], (col&(1<<i) ? HIGH : LOW));
        
    }
    led_OFF();
    ++pos;
    
    if(cur_letter->finished()) next();
    
  }
  
}

void drawManager::next(){

    free(cur_letter);
    cnt++;
    if(letters[cnt] == '\0') return;
    cur_letter = new Drawer(ascii_letters[letters[cnt]]);

}

void drawManager::update_letters(char h, char m, char s){

    sprintf(letters, "%02d:%02d:%02d", h, m, s);

}
