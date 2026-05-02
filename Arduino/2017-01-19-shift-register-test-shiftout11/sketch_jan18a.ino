/*
 * sketch_jan18a.ino
 * Date: 2017-01-19
 * 
 * Shift register 'Hello world' - https://www.arduino.cc/en/Tutorial/ShftOut11
 * 
 * Shift register example
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

  randomSeed(analogRead(0));
}

void loop() {
  while (true) {
    int j = random(0, 256);
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, MSBFIRST, j);
    digitalWrite(latchPin, HIGH);
    delay(500);
  }
  
  /*
  for (int numToDisplay = 0; numToDisplay < 256; numToDisplay++) {
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, MSBFIRST, numToDisplay);
    digitalWrite(latchPin, HIGH);
    delay(100); // 500
  }
  */
}
