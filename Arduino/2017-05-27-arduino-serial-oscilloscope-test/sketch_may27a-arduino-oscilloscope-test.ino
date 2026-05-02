/*
 * sketch_may27a-arduino-oscilloscope-test.ino
 * Date: 2017-05-27
 * 
 * Arduino Uno Oscilloscope test
 * 
 * Using the serial plotter as a poor man's oscilloscope
 *
 * Copyright (c) 2026 Christopher Elison <chriselison.uk>
 * Licensed under the MIT License.
 */

void setup() {
  Serial.begin(250000);
  pinMode(A0, INPUT);
}

void loop() {
  int val = analogRead(A0);
  float result = val * (5.0 / 1023.0);
  Serial.println(result);
  delay(5);
}
