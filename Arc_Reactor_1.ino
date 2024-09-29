#include <Adafruit_NeoPixel.h>

#define PIN 15

Adafruit_NeoPixel strip = Adafruit_NeoPixel(24, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  strip.begin();
  strip.setBrightness(255); // Set the brightness (0-255)
  strip.show(); // Initialize all pixels to 'off'
}

void loop() {
  // Pulsating light blue/cyan effect
  for (int b = 0; b <= 255; b++) {
    for (int i = 0; i < strip.numPixels(); i++) {
      strip.setPixelColor(i, 0, 100, 255); // Light blue/cyan color
      strip.setBrightness(b);
    }
    strip.show();
    delay(10); // Adjust the speed of pulsating
  }

  for (int b = 255; b >= 0; b--) {
    for (int i = 0; i < strip.numPixels(); i++) {
      strip.setPixelColor(i, 0, 100, 255); // Light blue/cyan color
      strip.setBrightness(b);
    }
    strip.show();
    delay(10); // Adjust the speed of pulsating
  }
}
