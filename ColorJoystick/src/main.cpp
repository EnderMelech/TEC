#include <Arduino.h>
#include <Adafruit_NeoPixel.h>
#define xPin 7
#define yPin 6
#define swPin 5
#define LED_PIN 48
#define LED_COUNT 1
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

//boolean oldState = HIGH;
//int     mode     = 0;

void setup() {
  Serial.begin(9600);
  pinMode(xPin, INPUT_PULLUP);
  strip.begin();
  strip.show();
}

void Red () {
  strip.setPixelColor(0, strip.Color(255,   0,   0));
  strip.show();
}

void Green () {
  strip.setPixelColor(0, strip.Color(0,   255,   0));
  strip.show();
}

void Blue () {
  strip.setPixelColor(0, strip.Color(0,   0,   255));
  strip.show();
}

void Black() {
  strip.setPixelColor(0, strip.Color(0,   0,    0));
  strip.show();
}

void loop() {
  if (digitalRead(swPin) == LOW) {
    Black();
  }
  int rawXValue = analogRead(xPin);
  int xValue = map(rawXValue, 0, 1023, 0, 255);
  Serial.println(xValue);
  delay(1000);
//  boolean newState = digitalRead(xPin);

//  if((newState == LOW) && (oldState == HIGH)) {
//    delay(20);
//    newState = digitalRead(swPin);
//    if(newState == LOW) {
//      if(++mode > 3) mode = 0;
//      switch(mode) {
//        case 0:
//          Black();
//          break;
//        case 1:
//          Red();
//          break;
//        case 2:
//          Green();
//          break;
//        case 3:
//          Blue();
//          break;
//      }
//    }
//  }

//  oldState = newState;
}