#include <ArduinoUnit.h>

void setup() {
  Serial.begin(9600);
  while(!Serial);
}

void loop() {
  Test::run();
}

