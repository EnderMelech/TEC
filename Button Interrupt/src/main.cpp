#include <Arduino.h>
#include <TimerOne.h>
#define button 2

bool newState = HIGH;
bool oldState = newState;
int number = 0;

void checkButton() {
  oldState = newState;
}

void changeLights() {
  if(oldState != newState) {
    digitalWrite(LED_BUILTIN, newState);
    newState = !newState;
    number = number + 1;
    Serial.println(number);
    Serial.println("Falling");
  }
}

void setup() {
  pinMode(button, INPUT_PULLUP);
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, newState);
  newState = !newState;
  Timer1.initialize(30000);
  Timer1.attachInterrupt(checkButton);
  attachInterrupt(digitalPinToInterrupt(button), changeLights, FALLING);
  Serial.begin(9600);
}

void loop() {
  
}