#include <Arduino.h>
#include <Adafruit_NeoPixel.h>
#define LED_PIN 48
#define LED_COUNT 1
#define BRIGHTNESS 50
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);
void setup() {

strip.begin();
strip.show();
strip.setBrightness(BRIGHTNESS);
}

void loop() {

// Fill along the length of the strip in various colors...
colorWipe(strip.Color(255,   0,   0)     , 50); // Red
colorWipe(strip.Color(  0, 255,   0)     , 50); // Green
colorWipe(strip.Color(  0,   0, 255)     , 50); // Blue
}

// put function definitions here:
//int myFunction(int x, int y) {
//  return x + y;
//}