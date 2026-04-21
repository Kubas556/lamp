#include <Arduino.h>
#include <Adafruit_NeoPixel.h>

static constexpr uint16_t LED_COUNT = 12;
static constexpr uint8_t LED_PIN = 1;
static Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  strip.begin();
  strip.setBrightness(255);
  strip.show();
}

void loop() {
  static uint16_t baseHue = 0;
  for (uint16_t i = 0; i < LED_COUNT; ++i) {
    const uint16_t pixelHue = baseHue + (i * (65536 / LED_COUNT));
    const uint32_t color = strip.gamma32(strip.ColorHSV(pixelHue,255,255));
    strip.setPixelColor(i, color);
  }

  strip.show();
  baseHue += 256;
  delay(20);
}

