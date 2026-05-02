/*
 * sketch_may03a-ws2811-rgb-strip-test3.ino
 * Date: 2017-05-03
 * 
 * WS2811 RGB LED Strip Test 3 - Mode/Colour adjust board
 * 
 * Control addressable RGB LED strip, change R/G/B with potentiometers, mode switch
 *
 * Copyright (c) 2026 Christopher Elison <chriselison.uk>
 * Licensed under the MIT License.
 */

#include "FastLED.h"

#define NUM_LEDS 60
#define DATA_PIN 4
#define R_PIN 15
#define G_PIN 16
#define B_PIN 17

int r_val = 0;
int g_val = 0;
int b_val = 0;

// Define the array of leds
CRGB leds[NUM_LEDS];

void setup() {
  FastLED.addLeds<WS2811, DATA_PIN, BRG>(leds, NUM_LEDS);
}

void loop() {
  getRGBvals();

  // Left to right segment on/off effect
  for (int i=0; i<21; i++) {
    getRGBvals();
    leds[i].setRGB(r_val, g_val, b_val);
    FastLED.show();
    delay(100);
    // Now turn the LED off, then pause
    //leds[i] = CRGB::Black;
    //FastLED.show();
    //delay(100);
  }
  
  // Right to left
  for (int i=21; i>0; i--) {
    getRGBvals();
    leds[i].setRGB(r_val, g_val, b_val);
    FastLED.show();
    delay(100);
    // Now turn the LED off, then pause
    //leds[i] = CRGB::Black;
    //FastLED.show();
    //delay(100);
  }

  getRGBvals();
  for (int i=0; i<20; i++) {
    leds[i].setRGB(r_val, g_val, b_val);
  }
  FastLED.show();
  delay(50);
}

void getRGBvals() {
  // Read in values from RGB potentiometers
  r_val = map(analogRead(R_PIN), 0, 1023, 0 ,255);
  g_val = map(analogRead(G_PIN), 0, 1023, 0 ,255);
  b_val = map(analogRead(B_PIN), 0, 1023, 0 ,255);
}

