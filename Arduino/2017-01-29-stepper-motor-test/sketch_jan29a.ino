/*
 * sketch_jan29a.ino
 * Date: 2017-01-29
 * 
 * Stepper motor test 1
 * 
 * First attempt at working with stepper motor on Arduino
 *
 * Copyright (c) 2026 Christopher Elison <chriselison.uk>
 * Licensed under the MIT License.
 */

#include <Stepper.h>

const int stepsPerRev = 4096;

Stepper myStepper(stepsPerRev, 8, 9, 10, 11);

int stepCount = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  myStepper.step(1);
  Serial.print("Steps: ");
  Serial.println(stepCount);
  stepCount++;
  delay(20);
}
