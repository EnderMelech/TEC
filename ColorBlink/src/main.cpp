#include <Arduino.h>
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif

void setup() {

pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {

digitalWrite(LED_BUILTIN, HIGH);
delay(1000);
digitalWrite(LED_BUILTIN, LOW);
delay(1000);
}

// put function definitions here:
//int myFunction(int x, int y) {
//  return x + y;
//}