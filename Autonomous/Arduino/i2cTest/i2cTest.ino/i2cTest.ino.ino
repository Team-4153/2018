
#include <FastLED.h>
#include <Wire.h>
#define green 0x00ff00
#define blue 0x0000ff
#define black 0x000000
#define red 0xff0000
#define white 0xffffff
#define num_leds 50 

CRGB leds[num_leds];
float fork_height;
boolean alliance;
boolean fork;
boolean enabled;

void setup() {
  FastLED.addLeds<NEOPIXEL, 6>(leds, num_leds);
  Wire.begin(84);
  Wire.onReceive(receiveEvent);
}
void loop() {
   if (alliance == false){
    for(int i = 0; i < fork_height; i++)
      leds[i] = blue;
    for (int i = fork_height; i < num_leds; i++)
      leds[i] = white;
   }
   else if (alliance == true){
    for(int i = 0; i < fork_height; i++)
      leds[i] = red;
    for (int i = fork_height; i < num_leds; i++)
      leds[i] = white;
   }
   if (fork == true){
    for(int i = 0; i < fork_height; i++)
      leds[i] = green;
    for (int i = fork_height; i < num_leds; i++)
      leds[i] = white;
      //fork true overides alliance color
   }
  FastLED.show();
  delay(10);
}

void receiveEvent(int howMany) {
  int x = Wire.read();
  if (x <= 100) {
    fork_height=(x/100.0)*num_leds;
  }
  else if (x == 202 || x == 200) {
    enabled = false;
  }
  else if (x == 201 || x == 203) {
    enabled = true;
  }

  else if (x == 121) {
    fork = true;
  }
  else if (x == 120) {
    fork = false;
  }
  else if (x == 130){
    alliance = true;
  }
  else if (x == 131){
    alliance = false;
  } 
}



