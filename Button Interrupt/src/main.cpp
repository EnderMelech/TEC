#include <Arduino.h>
#define button 2

bool oldState = HIGH;
int mode = 0;

void changeLights() {
  if
}

void setup() {
  pinMode(button, INPUT_PULLUP);
  pinMode(LED_BUILTIN, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(button), changeLights, FALLING);
  Serial.begin
}

void loop() {
 
}