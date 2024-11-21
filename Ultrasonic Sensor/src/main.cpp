#include <Arduino.h>
#define echo 3
#define trig 2

int t0=0; // time when you pulled the trigger
// t1 can represent when you receive the echo, t1-t0=the time for the burst to reach the obstacle and return
// d=v*((t1-t0)/2) d is distance and v is speed (in this case it's speed of sound which is 343 m/s)

void measureTime() {
 if (digitalRead)(echo) == HIGH {
    int t0=micros();
 }
 if (digitalRead(echo) == LOW) {
    int t1=micros();
    Serial.println((343/10^6)*((t1-t0)/2));
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
    delay(1000);
}
}