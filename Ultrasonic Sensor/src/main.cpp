#include <Arduino.h>
#include <TimerOne.h>
#define echo 3
#define trig 2

unsigned long t1=0;
unsigned long t2=0;
unsigned long t1Local=0;
unsigned long t2Local=0;
bool falling = false;

void triggerSensor() {
 digitalWrite(trig, HIGH);
 delayMicroseconds(10);
 digitalWrite(trig, LOW);
}

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
 Timer1.initialize(200000);
 Timer1.attachInterrupt(triggerSensor);
 attachInterrupt(digitalPinToInterrupt(echo), measureTime, CHANGE);
 Serial.begin(9600);
}

void loop() {
 if (falling == true) {
   noInterrupts();
   unsigned long t1Local = t1;
   unsigned long t2Local = t2;
   interrupts();
   Serial.println(0.0343*((t2Local-t1Local)/2));
 }
}