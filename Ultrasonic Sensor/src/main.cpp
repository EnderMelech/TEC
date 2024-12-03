#include <Arduino.h>
#define echo 3
#define trig 2

int t0=0;
unsigned long t1=0;
unsigned long t2=0;
unsigned long t1Local=0;
unsigned long t2Local=0;
bool falling = false;

void measureTime() {
 if (digitalRead(echo) == HIGH) {
    t1=micros();
 }
 if (digitalRead(echo) == LOW) {
    t2=micros();
    falling = true;
 }
}

void setup() {
 pinMode(trig, OUTPUT);
 pinMode(echo, INPUT);
 attachInterrupt(digitalPinToInterrupt(echo), measureTime, CHANGE);
 Serial.begin(9600);
}

void loop() {
 if (millis()-t0>=100) {
    t0=millis(); // the time of the most recent spike (when you pulled the trigger)
    digitalWrite(trig, HIGH);
    delayMicroseconds(10);
    digitalWrite(trig, LOW);
 if (falling == true) {
   noInterrupts();
   unsigned long t1Local = t1;
   unsigned long t2Local = t2;
   interrupts();
   Serial.println(0.0343*((t2Local-t1Local)/2));
 }
 }
}