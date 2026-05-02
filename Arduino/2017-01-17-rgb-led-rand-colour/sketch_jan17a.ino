/*
 * sketch_jan17a.ino
 * Date: 2017-01-17
 * 
 * RGB LED test
 * 
 * Display random colours on a RGB LED
 *
 * Copyright (c) 2026 Christopher Elison <chriselison.uk>
 * Licensed under the MIT License.
 */

const int redPin   = 11;
const int greenPin = 10;
const int bluePin  = 9;

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);

  // Push button digital pin
  pinMode(2, INPUT_PULLUP);

  // Seed the random number generator for better randomisation
  randomSeed(analogRead(0));
}

void loop() {
  //randCol();
  //delay(1000);
  
  int buttonVal = digitalRead(2);

  if (buttonVal == LOW) {
    randCol();
    delay(400);
  }
}

/*
  setCol(int, int, int) - Set a specific RGB colour
*/
void setCol(int r, int g, int b) {
  analogWrite(redPin, r);
  analogWrite(greenPin, g);
  analogWrite(bluePin, b);
}

void randCol() {
  int r = random(0, 256);
  int g = random(0, 256);
  int b = random(0, 256);
  setCol(r, g, b);
}
