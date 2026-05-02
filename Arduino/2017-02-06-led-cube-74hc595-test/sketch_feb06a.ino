/*
 * sketch_feb06a.ino
 * Date: 2017-02-06
 * 
 * Testing prototype code for LED cube with 74HC595
 * 
 * Unfinished code
 *
 * Copyright (c) 2026 Christopher Elison <chriselison.uk>
 * Licensed under the MIT License.
 */

int latchPin = 8;
int clockPin = 12;
int dataPin  = 11;

void setup() {
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
}

void loop() {
  for (int i=0; i<16; i++) {
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, MSBFIRST, byte(i));
    digitalWrite(latchPin, HIGH);
    delay(500);
  }
}
