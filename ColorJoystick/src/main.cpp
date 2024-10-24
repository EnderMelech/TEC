#include <Arduino.h>
#include <Adafruit_NeoPixel.h>
#include <algorithm>
#define xPin 7
#define swPin 5
#define LED_PIN 48
#define LED_COUNT 1
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

int mode = 0;

void setup() {
  Serial.begin(9600);
  pinMode(xPin, INPUT_PULLUP);
  strip.begin();
  strip.show();
}

void Black() {
  strip.setPixelColor(0, strip.Color(0,   0,    0));
  strip.show();
}

void Color() {
  int redValue = 0;
  int greenValue = 0;
  int blueValue = 0;
  int rawXValue = analogRead(xPin);
  int xValue = map(rawXValue, 0, 4095, 0, 1532);
  if (0 <= xValue <= 255, 1277 <= xValue <= 1532) {
    redValue = 255;
  } else {
    redValue = std::max(0, 255-(xValue-255));
  }
  if (255 <= xValue <= 766) {
    blueValue = 255;
  } else if (xValue < 255) {
    blueValue = std::max(0, xValue);
  } else {
    blueValue = std::max(0, 255-(xValue-766));
  }
  if (766 <= xValue <= 1277) {
    greenValue = 255;
  } else if (xValue < 766) {
    greenValue = std::max(0, xValue-511);
  } else {
    greenValue = std::max(0, 255-(xValue-1277));
  }
  strip.setPixelColor(0, strip.Color(redValue,   greenValue,    blueValue));
  strip.show();
}

void loop() {
  if (digitalRead(swPin) == LOW) {
    if(++mode > 1) mode = 0;
      switch(mode) {
        case 0:
          Black();
          break;
        case 1:
          Color();
          break;
      }
  }
}