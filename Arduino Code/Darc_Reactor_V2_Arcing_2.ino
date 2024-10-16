#include <Adafruit_NeoPixel.h>

#define PIN            15  // Pin where the NeoPixel ring is connected
#define NUM_PIXELS    24  // Number of pixels in your NeoPixel ring

Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_PIXELS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  strip.begin();
  strip.setBrightness(255);  // Set the brightness level
  strip.show();  // Initialize all pixels to 'off'
  randomSeed(analogRead(0)); // Seed the random number generator
}

void loop() {
  // Set all LEDs to dark red
  for (int i = 0; i < NUM_PIXELS; i++) {
    strip.setPixelColor(i, strip.Color(50, 0, 0)); // Dark red
  }
  strip.show();

  // Simulate arcing for a random LED
  int randomLED = random(NUM_PIXELS);
  uint8_t r = random(256);  // Random red component
  uint8_t g = random(256);  // Random green component
  uint8_t b = random(256);  // Random blue component
  uint32_t arcColor = strip.Color(r, g, b);

  strip.setPixelColor(randomLED, arcColor); // Turn on a random LED with the arc color
  strip.show();
  delay(random(1, 10)); // Longer delay between turning off the arc color
  strip.setPixelColor(randomLED, strip.Color(50, 0, 0)); // Set the LED back to dark red
  strip.show();
  delay(random(1, 5)); // Shorter delay between arcing effects
}
