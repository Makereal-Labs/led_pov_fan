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

drawManager::drawManager(char* _letters , byte _startpos) : startpos(_startpos){

    letters = _letters;
    cnt = 0;
    pos = _startpos;
    last_rnd = 0;
    rnd_time = 200;
    cur_letter = new Drawer(numbers[letters[cnt]-'0']);

};

void drawManager::time_update(){

    rnd_time = micros() - last_rnd;
    last_rnd = micros();
    pos = startpos;
    cnt = 0;
    
    free(cur_letter);
    cur_letter = new Drawer(numbers[letters[cnt]-'0']);
  
}

void drawManager::pos_update(){

  
}

void drawManager::test(){

  if((micros()-last_rnd) * 2 > rnd_time) led_ON();
  else led_OFF();
  
}

void drawManager::draw(){

  //digitalWrite(3,(*letter_ptr - '0' < 10 && *letter_ptr - '0' > 0)?HIGH:LOW);
  digitalWrite(3,LOW);
   if(cnt == 6) return;
  digitalWrite(3,HIGH);

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
    if(cnt == 6) return;
    cur_letter = new Drawer(numbers[letters[cnt]-'0']);

}
