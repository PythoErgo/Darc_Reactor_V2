#include <Adafruit_NeoPixel.h>

#define LED_PIN    15    // Pin where the NeoPixel is connected
#define NUM_LEDS   24   // Number of NeoPixels

Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LEDS, LED_PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  strip.begin();       // Initialize the NeoPixel strip
  strip.show();        // Initialize all pixels to 'off'
  delay(1500);
  flickerLightBlue(100, 2); // Flicker light blue twice, 100ms per flicker
  delay(500);             // Wait half a second (dark)
  brightenToMaxLightBlue(20); // Gradually brighten to max brightness with a 20ms delay
}

void loop() {
}

// Function to flicker light blue twice
void flickerLightBlue(int flickerDelay, int times) {
  for (int i = 0; i < times; i++) {
    setAllPixels(0, 0, 255, 128); // Light blue color, medium brightness (R, G, B, brightness)
    delay(flickerDelay);
    setAllPixels(0, 0, 0, 0);     // Turn off the LEDs
    delay(flickerDelay);
  }
}

// Function to gradually brighten to full light blue
void brightenToMaxLightBlue(int stepDelay) {
  for (int brightness = 0; brightness <= 255; brightness++) {
    setAllPixels(0, 0, 255, brightness); // Gradually increase brightness
    delay(stepDelay);
  }
}

// Helper function to set all pixels to a given color
void setAllPixels(byte r, byte g, byte b, byte brightness) {
  for (int i = 0; i < NUM_LEDS; i++) {
    strip.setPixelColor(i, strip.Color(r * brightness / 255, g * brightness / 255, b * brightness / 255));
  }
  strip.show();
}
