#include <Adafruit_NeoPixel.h>

#define PIN 15

Adafruit_NeoPixel strip = Adafruit_NeoPixel(24, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  strip.begin();
  strip.setBrightness(255); // Set the brightness (0-255)
  strip.show(); // Initialize all pixels to 'off'
}

void loop() {
  // Turn on LEDs in a circular pattern one by one over 2 seconds
  for (int i = 0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i, 255, 255, 255); // Daylight white color (255, 255, 255)
    strip.show();
    delay(100); // Divide 2000ms by 12 LEDs for a 2-second animation
  }

  // Keep all LEDs at daylight white color indefinitely
  for (int i = 0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i, 255, 255, 255); // Daylight white color (255, 255, 255)
  }
  strip.show();
  
  // Add any other code or functions you want to run here
  
  while (true) {
    // Keep the LEDs on forever
  }
}
