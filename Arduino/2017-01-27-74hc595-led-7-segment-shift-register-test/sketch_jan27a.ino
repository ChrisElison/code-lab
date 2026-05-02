/*
 * sketch_jan27a.ino
 * Date: 2017-01-27
 * 
 * Control 7 segment LED display with 74HC595 shift register
 * 
 * Much better way to control 7-segment LED display
 *
 * Copyright (c) 2026 Christopher Elison <chriselison.uk>
 * Licensed under the MIT License.
 */

// Better way to count up/down with 7 segment LED and 74HC595 shift register

int latchPin = 8;
int clockPin = 12;
int dataPin  = 11;

// Decimal values for LED states
int decVals[] {63, 6, 91, 79, 102, 109, 125, 7, 127, 103};

void setup() {
  // Set shift register pins as output
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
}

void loop() {
  for (int j = 0; j < 10; j++) {
    digitalWrite(latchPin, LOW);
    //Serial.println(decVals[j]);
    shiftOut(dataPin, clockPin, MSBFIRST, byte(decVals[j]));
    digitalWrite(latchPin, HIGH);
    delay(1000);
  }

  // Counting down
  for (int j = 8; j > 0; j--) {
    digitalWrite(latchPin, LOW);
    //Serial.println(decVals[j]);
    shiftOut(dataPin, clockPin, MSBFIRST, byte(decVals[j]));
    digitalWrite(latchPin, HIGH);
    delay(1000);
  }
}
