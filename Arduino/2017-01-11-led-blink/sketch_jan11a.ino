/*
 * sketch_jan11a.ino
 * Date: 2017-01-11
 * 
 * Blinks an LED connected to pin 7 on an Arduino
 *
 * Copyright (c) 2026 Christopher Elison <chriselison.uk>
 * Licensed under the MIT License.
 */

const int outPin = 7;

void setup() {
  // put your setup code here, to run once:
  pinMode(outPin, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(outPin, HIGH);
  delay(1000);
  digitalWrite(outPin, LOW);
  delay(1000);
}
