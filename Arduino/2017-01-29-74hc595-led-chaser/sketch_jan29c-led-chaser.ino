/*
 * sketch_jan29c-led-chaser.ino
 * Date: 2017-01-29
 * 
 * LED chaser/pattern ring with 74HC595 shift register
 * 
 * Control rate of pattern with pot, not sure if I got this to work, can't remember
 *
 * Copyright (c) 2026 Christopher Elison <chriselison.uk>
 * Licensed under the MIT License.
 */

int latchPin = 8;
int clockPin = 12;
int dataPin  = 11;
int potPin = 0;

void setup() {
  Serial.begin(9600);
  
  // Set shift register pins as output
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
}

void loop() {
  int x = 1;
  
  for (int c = 0; c < 8; c++) {
    int rate = analogRead(potPin);
    Serial.print("Pot: ");
    Serial.println(rate);
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, MSBFIRST, byte(x));
    digitalWrite(latchPin, HIGH);
    delay(rate);
    x = x << 1;
  }
}

