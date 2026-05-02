/*
 * sketch_apr27b-ws2811-rgb-strip-test2.ino
 * Date: 2017-04-27
 * 
 * WS2811 RGB LED Strip Test 2 - FastLED
 * 
 * Testing the WS2811 RGB LED strip
 *
 * Copyright (c) 2026 Christopher Elison <chriselison.uk>
 * Licensed under the MIT License.
 */

#include "FastLED.h"

// How many leds in your strip?
#define NUM_LEDS 30

// For led chips like Neopixels, which have a data line, ground, and power, you just
// need to define DATA_PIN.  For led chipsets that are SPI based (four wires - data, clock,
// ground, and power), like the LPD8806 define both DATA_PIN and CLOCK_PIN
#define DATA_PIN 4
//#define CLOCK_PIN 13

// Define the array of leds
CRGB leds[NUM_LEDS];

void setup() { 
      // Uncomment/edit one of the following lines for your leds arrangement.
      // FastLED.addLeds<TM1803, DATA_PIN, RGB>(leds, NUM_LEDS);
      // FastLED.addLeds<TM1804, DATA_PIN, RGB>(leds, NUM_LEDS);
      // FastLED.addLeds<TM1809, DATA_PIN, RGB>(leds, NUM_LEDS);
      FastLED.addLeds<WS2811, DATA_PIN, BRG>(leds, NUM_LEDS);
      // FastLED.addLeds<WS2812, DATA_PIN, RGB>(leds, NUM_LEDS);
      // FastLED.addLeds<WS2812B, DATA_PIN, RGB>(leds, NUM_LEDS);
      //FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
      // FastLED.addLeds<UCS1903, DATA_PIN, RGB>(leds, NUM_LEDS);
      // FastLED.addLeds<UCS1903B, DATA_PIN, RGB>(leds, NUM_LEDS);
      // FastLED.addLeds<GW6205, DATA_PIN, RGB>(leds, NUM_LEDS);
      // FastLED.addLeds<GW6205_400, DATA_PIN, RGB>(leds, NUM_LEDS);
      
      // FastLED.addLeds<WS2801, RGB>(leds, NUM_LEDS);
      // FastLED.addLeds<SM16716, RGB>(leds, NUM_LEDS);
      // FastLED.addLeds<LPD8806, RGB>(leds, NUM_LEDS);

      // FastLED.addLeds<WS2801, DATA_PIN, CLOCK_PIN, RGB>(leds, NUM_LEDS);
      // FastLED.addLeds<SM16716, DATA_PIN, CLOCK_PIN, RGB>(leds, NUM_LEDS);
      // FastLED.addLeds<LPD8806, DATA_PIN, CLOCK_PIN, RGB>(leds, NUM_LEDS);
}

void loop() {
  for (int i=0; i<10; i++) {
    leds[i] = CRGB::Red;
    FastLED.show();
    delay(100);
    // Now turn the LED off, then pause
    leds[i] = CRGB::Black;
    //FastLED.show();
    //delay(100);
  }

  for (int i=0; i<10; i++) {
    leds[i] = CRGB::Green;
    FastLED.show();
    delay(100);
    // Now turn the LED off, then pause
    leds[i] = CRGB::Black;
    //FastLED.show();
    //delay(100);
  }

  for (int i=0; i<10; i++) {
    leds[i] = CRGB::Blue;
    FastLED.show();
    delay(100);
    // Now turn the LED off, then pause
    leds[i] = CRGB::Black;
    //FastLED.show();
    //delay(100);
  }


  for (int i=0; i<10; i++) {
    leds[i] = CRGB::Amethyst;
  }
  FastLED.show();
  delay(1000);
  FastLED.show();


  for (int i=0; i<10; i++) {
    leds[i] = CRGB::Aquamarine;
  }
  FastLED.show();
  delay(1000);
  FastLED.show();


  for (int i=0; i<10; i++) {
    leds[i] = CRGB::CornflowerBlue;
  }
  FastLED.show();
  delay(1000);
  FastLED.show();


  for (int i=0; i<10; i++) {
    leds[i] = CRGB::DeepPink;
  }
  FastLED.show();
  delay(1000);
  FastLED.show();


  for (int i=0; i<10; i++) {
    leds[i] = CRGB::Orange;
  }
  FastLED.show();
  delay(1000);
  FastLED.show();


  for (int i=0; i<10; i++) {
    leds[i] = CRGB::GreenYellow;
  }
  FastLED.show();
  delay(1000);
  FastLED.show();


  for (int i=0; i<10; i++) {
    leds[i] = CRGB::LightSkyBlue;
  }
  FastLED.show();
  delay(1000);
  FastLED.show();


  for (int i=0; i<10; i++) {
    leds[i] = CRGB::MediumPurple;
  }
  FastLED.show();
  delay(1000);
  FastLED.show();


  for (int i=0; i<10; i++) {
    leds[i] = CRGB::Navy;
  }
  FastLED.show();
  delay(1000);
  FastLED.show();


  for (int i=0; i<10; i++) {
    leds[i] = CRGB::LightPink;
  }
  FastLED.show();
  delay(1000);
  FastLED.show();
  
}

