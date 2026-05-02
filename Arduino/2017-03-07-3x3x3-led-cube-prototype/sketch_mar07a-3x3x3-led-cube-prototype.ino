/*
 * sketch_mar07a-3x3x3-led-cube-prototype.ino
 * Date: 2017-03-07
 * 
 * Chris Elison's 3x3x3 (yellow 3mm) LED cube prototype
 * 
 * Test code to test my terribly soldered attempt at a 3x3x3 LED cube - works though :)
 *
 * Copyright (c) 2026 Christopher Elison <chriselison.uk>
 * Licensed under the MIT License.
 */

// Shift register pins
int latchPin  = 8;
int clockPin  = 12;
int dataPin   = 11;

// Delay
int delayVal = 500;

// Pin numbers for the three cathode transistors
int cathodePins[] = {7, 6, 5};
byte testBuff[] = {
  '0000000000000001',
  '0000000000000010',
  '0000000000000100',
  '0000000000001000',
  '0000000000010000',
  '0000000000100000',
  '0000000001000000',
  '0000000010000000',
  '0000000100000000',
};

unsigned long interval = 1000; // the time we need to wait
unsigned long previousMillis = 0;

void setup() {
  // Set shift register pins as output
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);

  // Set cathode transistor base pins as output
  //pinMode(cathodePins[0], OUTPUT);
  //pinMode(cathodePins[1], OUTPUT);
  pinMode(cathodePins[2], OUTPUT);
}

void loop() {
  /* Millis test - https://www.baldengineer.com/millis-tutorial.html
  unsigned long currentMillis = millis();
  
  if ((unsigned long)(currentMillis - previousMillis) >= interval) {
    genRandomNumber();
    previousMillis = millis();
  }
  */

  // Test cycle
  //for(int i=0; i<3; i++) {
  //  digitalWrite(cathodePins[0], HIGH);
  //  for (int j=0; j<9; j++) {
  //    digitalWrite(latchPin, LOW);
  //    shiftOut(dataPin, clockPin, LSBFIRST, testBuff[j]);
  //    digitalWrite(latchPin, HIGH);
  //    delay(500);
  //  }
    //delay(1000);
    //digitalWrite(cathodePins[i], LOW);
  //}

  digitalWrite(cathodePins[0], LOW);
  digitalWrite(cathodePins[1], LOW);
  digitalWrite(cathodePins[2], HIGH);
  
  // Anim frame 0
  //digitalWrite(latchPin, LOW);
  //shiftOut(dataPin, clockPin, LSBFIRST, B00000000);
  //shiftOut(dataPin, clockPin, LSBFIRST, B00000000);
  //digitalWrite(latchPin, HIGH);
  //delay(delayVal);

  // Anim frame 1
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, B00000001);
  shiftOut(dataPin, clockPin, LSBFIRST, B00000000);
  digitalWrite(latchPin, HIGH);
  delay(delayVal);

  // 2
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, B00000010);
  shiftOut(dataPin, clockPin, LSBFIRST, B00000000);
  digitalWrite(latchPin, HIGH);
  delay(delayVal);

  // 3
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, B00000100);
  shiftOut(dataPin, clockPin, LSBFIRST, B00000000);
  digitalWrite(latchPin, HIGH);
  delay(delayVal);

  // 4
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, B00001000);
  shiftOut(dataPin, clockPin, LSBFIRST, B00000000);
  digitalWrite(latchPin, HIGH);
  delay(delayVal);

  // 5
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, B00010000);
  shiftOut(dataPin, clockPin, LSBFIRST, B00000000);
  digitalWrite(latchPin, HIGH);
  delay(delayVal);

  // 6
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, B00100000);
  shiftOut(dataPin, clockPin, LSBFIRST, B00000000);
  digitalWrite(latchPin, HIGH);
  delay(delayVal);

  // 7
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, B00000000);
  shiftOut(dataPin, clockPin, LSBFIRST, B00000001);
  digitalWrite(latchPin, HIGH);
  delay(delayVal);

  // 8
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, B10000000);
  shiftOut(dataPin, clockPin, LSBFIRST, B00000000);
  digitalWrite(latchPin, HIGH);
  delay(delayVal);

  // 9
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, B01000000);
  shiftOut(dataPin, clockPin, LSBFIRST, B00000000);
  digitalWrite(latchPin, HIGH);
  delay(delayVal);
  
  /*
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, B00001111);
  shiftOut(dataPin, clockPin, LSBFIRST, B00000000);
  digitalWrite(latchPin, HIGH);
  delay(delayVal);

  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, B00011111);
  shiftOut(dataPin, clockPin, LSBFIRST, B00000000);
  digitalWrite(latchPin, HIGH);
  delay(delayVal);

  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, B00111111);
  shiftOut(dataPin, clockPin, LSBFIRST, B00000000);
  digitalWrite(latchPin, HIGH);
  delay(delayVal);

  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, B01111111);
  shiftOut(dataPin, clockPin, LSBFIRST, B00000000);
  digitalWrite(latchPin, HIGH);
  delay(delayVal);

  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, B11111111);
  shiftOut(dataPin, clockPin, LSBFIRST, B00000000);
  digitalWrite(latchPin, HIGH);
  delay(delayVal);

  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, B11111111);
  shiftOut(dataPin, clockPin, LSBFIRST, B00000001);
  digitalWrite(latchPin, HIGH);
  delay(delayVal);

  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, B00000000);
  shiftOut(dataPin, clockPin, LSBFIRST, B00000000);
  digitalWrite(latchPin, HIGH);
  delay(delayVal);
  */
}
