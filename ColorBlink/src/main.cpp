#include <Arduino.h>
#include <Adafruit_NeoPixel.h>
#define LED_PIN 48
#define LED_COUNT 1
#define BRIGHTNESS 50
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

void Red () {
  strip.setPixelColor(strip.Color(255,   0,   0)     , BRIGHTNESS);
    strip.show();
}

void Green () {
  strip.setPixelColor(strip.Color(0,   255,   0)     , BRIGHTNESS);
    strip.show();
}

void Blue () {
  strip.setPixelColor(strip.Color(0,   0,   255)     , BRIGHTNESS);
    strip.show();
}

void setup() {
  strip.begin();
  strip.show();
  strip.setBrightness(BRIGHTNESS);
}

void loop() {
  Red;
  Green;
  Blue;
}