/*
 * sketch_mar29a-nano-test1.ino
 * Date: 2017-03-29
 * 
 * Arduino Nano v3 test sketch
 * 
 * Just testing my new Arduino Nano, it works just like an Uno really
 *
 * Copyright (c) 2026 Christopher Elison <chriselison.uk>
 * Licensed under the MIT License.
 */

const int ledPin = 2;

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  digitalWrite(ledPin, HIGH);
  delay(250);
  digitalWrite(ledPin, LOW);
  delay(250);
  digitalWrite(ledPin, HIGH);
  delay(250);
  digitalWrite(ledPin, LOW);
  
  delay(1000);
}

