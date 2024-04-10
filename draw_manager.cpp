#include "draw_manager.h"
#include "led_letters.h"
#include "arduino.h"
#define DISPLAY 90

void led_OFF(){

  for(byte i = 0; i < 7; ++i) digitalWrite(red_leds[i], LOW);
  for(byte i = 0; i < 5; ++i) digitalWrite(blue_leds[i], LOW);
  
}

void led_ON(){

  for(byte i = 0; i < 7; ++i) digitalWrite(red_leds[i], HIGH);
  for(byte i = 0; i < 5; ++i) digitalWrite(blue_leds[i], HIGH);
  
}

drawManager::drawManager(char * _letters , byte _startpos) : startpos(_startpos){

    sprintf(letters, "%s", _letters);
    cnt = 0;
    pos = _startpos;
    last_rnd = 0;
    rnd_time = 200;
    cur_letter = new Drawer(ascii_letters[letters[cnt]]);

};

void drawManager::time_update(){

    rnd_time = micros() - last_rnd;
    last_rnd = micros();
    pos = startpos;
    cnt = 0;
    
    free(cur_letter);
    cur_letter = new Drawer(ascii_letters[letters[cnt]]);
  
}

void drawManager::pos_update(){

  
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
