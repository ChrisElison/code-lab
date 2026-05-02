/*
 * sketch_feb27a-protocube-test1.ino
 * Date: 2017-02-27
 * 
 * LED Cube Protoboard Prototype 1 - Test 1
 * 
 * Unfinished code
 *
 * Copyright (c) 2026 Christopher Elison <chriselison.uk>
 * Licensed under the MIT License.
 */

int led1 = 5;
int led2 = 6;
int led3 = 7;
int c1 = 8;

int delayVal = 1000;

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(c1, OUTPUT);
}

void loop() {
  digitalWrite(c1, HIGH);

  digitalWrite(led1, HIGH);
  delay(delayVal);
  digitalWrite(led1, LOW);

  digitalWrite(led2, HIGH);
  delay(delayVal);
  digitalWrite(led2, LOW);

  digitalWrite(led3, HIGH);
  delay(delayVal);
  digitalWrite(led3, LOW);

  digitalWrite(led2, HIGH);
  delay(delayVal);
  digitalWrite(led2, LOW);
}
