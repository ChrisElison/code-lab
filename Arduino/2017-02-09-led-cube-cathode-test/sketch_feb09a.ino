/*
 * sketch_feb09a.ino
 * Date: 2017-02-09
 * 
 * Testing LED cube cathode activation
 * 
 * More LED cube code, unfinished
 *
 * Copyright (c) 2026 Christopher Elison <chriselison.uk>
 * Licensed under the MIT License.
 */

// Transistors seem best bet to control active cathode layers
// Multiplex each cathode layer, Persistence of Vision solution!

int cathode1Pin = 8;
int cathode2Pin = 9;
int cathode3Pin = 10;

void setup() {
  pinMode(cathode1Pin, OUTPUT);
  pinMode(cathode2Pin, OUTPUT);
  pinMode(cathode3Pin, OUTPUT);
}

void loop() {
  digitalWrite(cathode1Pin, HIGH);
  delay(333);
  digitalWrite(cathode1Pin, LOW);
  
  digitalWrite(cathode2Pin, HIGH);
  delay(333);
  digitalWrite(cathode2Pin, LOW);

  digitalWrite(cathode3Pin, HIGH);
  delay(333);
  digitalWrite(cathode3Pin, LOW);
}
