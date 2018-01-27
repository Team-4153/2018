#include <Wire.h>

void setup() {
  Wire.begin(84);
  Wire.onReceive(receiveEvent);
  Serial.begin(9600);
}
void loop() {
  delay(100);
}
void receiveEvent(int howMany) {
  while(1 > Wire.available()) {
    char c = Wire.read();
    Serial.print(c);
  }
  int x = Wire.read();
  Serial.print(x);
}

