/*
 * sketch_jan29b-servotest.ino
 * Date: 2017-01-29
 * 
 * Servo motor test with Arduino
 * 
 * Change pos of servo with potentiometer
 *
 * Copyright (c) 2026 Christopher Elison <chriselison.uk>
 * Licensed under the MIT License.
 */

#include <Servo.h>

Servo myServo;

int potpin = 0;
int val;

void setup() {
  myServo.attach(9);
}

void loop() {
  val = analogRead(potpin);
  val = map(val, 0, 1023, 0, 180);
  myServo.write(val);
  delay(50);
}
