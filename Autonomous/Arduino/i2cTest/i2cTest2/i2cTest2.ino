
#include <FastLED.h>

#include <Wire.h>

CRGB leds[43];
int fork_height;
boolean alliance;
boolean fork;
boolean enabled;

void setup() {
  FastLED.addLeds<NEOPIXEL, 6>(leds, 43);
  Wire.begin(84);
  Wire.onReceive(receiveEvent);
  Serial.begin(9600);
}
void loop() {
  FastLED.show();
  delay(2);
}
void receiveEvent(int howMany) {
  int x = Wire.read();
  if (x <= 100) {
    fork_height=x;
  }
  else if (x == 200) {
    enabled = false;
  }
  else if (x == 201) {
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
//Serial.print(x);


