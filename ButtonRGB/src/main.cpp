#include <Arduino.h>
#include <Adafruit_NeoPixel.h>
#define LED_PIN 48
#define LED_COUNT 1
#define BRIGHTNESS 255
#define BUTTON_PIN   2
#define PIXEL_PIN    6
#define PIXEL_COUNT 16
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

boolean oldState = HIGH;
int     mode     = 0;

void setup() {
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  strip.begin();
  strip.show();
}

void loop() {
  boolean newState = digitalRead(BUTTON_PIN);

  if((newState == LOW) && (oldState == HIGH)) {
    delay(20);
    newState = digitalRead(BUTTON_PIN);
    if(newState == LOW) {
      if(++mode > 3) mode = 0;
      switch(mode) {
        case 0:
          Black();
          break;
        case 1:
          Red();
          break;
        case 2:
          Green();
          break;
        case 3:
          Blue();
          break;
      }
    }
  }

  oldState = newState;
}

void Red () {
  strip.setPixelColor(0, strip.Color(255,   0,   0));
}

void Green () {
  strip.setPixelColor(0, strip.Color(0,   255,   0));
}

void Blue () {
  strip.setPixelColor(0, strip.Color(0,   0,   255));
}

void Black() {
  strip.setPixelColor(0, strip.Color(0,   0,    0));
}