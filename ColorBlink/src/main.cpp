#include <Arduino.h>
#include <Adafruit_NeoPixel.h>
#define LED_PIN 48
#define LED_COUNT 1
#define BRIGHTNESS 50
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

// Fill strip pixels one after another with a color. Strip is NOT cleared
// first; anything there will be covered pixel by pixel. Pass in color
// (as a single 'packed' 32-bit value, which you can get by calling
// strip.Color(red, green, blue) as shown in the loop() function above),
// and a delay time (in milliseconds) between pixels.
void colorWipe(uint32_t color, int wait) {
  for(int i=0; i<strip.numPixels(); i++) { // For each pixel in strip...
    strip.setPixelColor(i, color);         //  Set pixel's color (in RAM)
    strip.show();                          //  Update strip to match
    delay(wait);                           //  Pause for a moment
  }
}

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