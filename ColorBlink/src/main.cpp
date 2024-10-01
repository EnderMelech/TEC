#include <Arduino.h>
#include <Adafruit_NeoPixel.h>
#define LED_PIN 48
#define LED_COUNT 1
#define BRIGHTNESS 255
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

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

void setup() {
  strip.begin();
  strip.show();
  strip.setBrightness(BRIGHTNESS);
}

void loop() {
  Red();
  delay(100);
  Green();
  delay(100);
  Blue();
  delay(100);
}