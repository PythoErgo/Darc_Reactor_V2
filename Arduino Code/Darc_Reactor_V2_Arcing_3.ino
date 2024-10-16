#include <Adafruit_NeoPixel.h>

#define PIN            15  // Pin where the NeoPixel ring is connected
#define NUM_PIXELS     24  // Number of pixels in your NeoPixel ring

Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_PIXELS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  strip.begin();
  strip.setBrightness(0);  // Start with brightness level at 0 (completely dark)
  strip.show();            // Initialize all pixels to 'off'
  randomSeed(analogRead(0)); // Seed the random number generator
}

void loop() {
  static int brightness = 0;
  static unsigned long previousMillis = 0; // Tracks time between arc events
  unsigned long currentMillis = millis();  // Get the current time

  // Gradually brighten the LEDs over 5 seconds
  if (brightness < 255) {
    brightness++;  // Increment brightness until it's maxed out at 255
    strip.setBrightness(brightness);

    // Set all LEDs to dark red based on current brightness level
    for (int i = 0; i < NUM_PIXELS; i++) {
      strip.setPixelColor(i, strip.Color((50 * brightness) / 255, 0, 0)); // Dark red scaled by brightness
    }
    strip.show();

    delay(20);  // Slows down the brightening; approx 5000ms / 255 = 19.6ms per step
  }

  // Calculate arc delay based on brightness level
  int arcDelay = map(brightness, 0, 255, 1000, 10);  // Arc once every 1 second when dim, down to 10ms when bright

  // Trigger an arc based on the current brightness level delay
  if (currentMillis - previousMillis >= arcDelay) {
    previousMillis = currentMillis;  // Reset the timer

    int randomLED = random(NUM_PIXELS);
    
    // Generate a random arc color
    uint8_t r = random(256);  // Random red component
    uint8_t g = random(256);  // Random green component
    uint8_t b = random(256);  // Random blue component
    uint32_t arcColor = strip.Color(r, g, b);

    strip.setPixelColor(randomLED, arcColor);  // Turn on a random LED with the arc color
    strip.show();
    
    delay(random(1, 10));  // Short delay for arc flash effect
    
    strip.setPixelColor(randomLED, strip.Color((50 * brightness) / 255, 0, 0));  // Set the LED back to dark red
    strip.show();
  }
}
