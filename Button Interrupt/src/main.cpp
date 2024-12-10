#include <Arduino.h>
#define button 2

bool state = HIGH;

void changeLights() {
  digitalWrite(LED_BUILTIN, state);
  state = !state;
}

void setup() {
  pinMode(button, INPUT_PULLUP);
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, state);
  state = !state;
  attachInterrupt(digitalPinToInterrupt(button), changeLights, FALLING);
  Serial.begin(9600);
}

void loop() {
  
}