#include <Arduino.h>
#include <string>
#include <Adafruit_NeoPixel.h>
#include <algorithm>
#define xPin 7
#define swPin 5
#define LED_PIN 48
#define LED_COUNT 1
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

boolean oldState = HIGH;
int mode = 0;
int redValue = 0;
int greenValue = 0;
int blueValue = 0;

void setup() {
  Serial.begin(9600);
  pinMode(xPin, INPUT_PULLUP);
  pinMode(swPin, INPUT_PULLUP);
  strip.begin();
  strip.show();
}

void Black() {
  strip.setPixelColor(0, strip.Color(0,   0,    0));
  strip.show();
}

void Color() {
  int rawXValue = analogRead(xPin);
  int xValue = map(rawXValue, 0, 4095, 0, 1532);
  if (xValue >= 0 && xValue <= 255 || xValue >= 1277 && xValue <= 1532) {
    redValue = 255;
  } else {
    redValue = std::max(0, 255-(xValue-255));
  }
  if (xValue >= 255 && xValue <= 766) {
    blueValue = 255;
  } else if (xValue < 255) {
    blueValue = std::max(0, xValue);
  } else {
    blueValue = std::max(0, 255-(xValue-766));
  }
  if (xValue >= 766 && xValue <= 1277) {
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
  boolean newState = digitalRead(swPin);

  if((newState == LOW) && (oldState == HIGH)) {
    delay(20);
    newState = digitalRead(swPin);
    if(newState == LOW) {
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
  while (mode == 1) {
    Color();
    delay(20);
  }
  oldState = newState;
}