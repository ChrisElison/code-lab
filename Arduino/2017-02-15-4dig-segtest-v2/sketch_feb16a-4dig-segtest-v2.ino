/*
 * sketch_feb16a-4dig-segtest-v2.ino
 * Date: 2017-02-16
 * 
 * Testing 4-digit 7 segment LED multiplexing with 74HC595
 * 
 * Improved code I think
 *
 * Copyright (c) 2026 Christopher Elison <chriselison.uk>
 * Licensed under the MIT License.
 */

// Shift register pins
int latchPin  = 8;
int clockPin  = 12;
int dataPin   = 11;

// Pin numbers for the four cathode transistors
int digitPins[4][1] = { {7}, {6}, {5}, {4} };

// Decimal encoded binary values for LED digit states 0-9
int decVals[] {63, 6, 91, 79, 102, 109, 125, 7, 127, 103};

// Test 4 digit number (un-encoded!)
int testNum[] {1, 9, 8, 3};
int testBuff[4];

unsigned long interval = 1000; // the time we need to wait
unsigned long previousMillis = 0;

void setup() {
  // Generate random number
  randomSeed(analogRead(0));
  testBuff[0] = random(1, 9);
  testBuff[1] = random(0, 9);
  testBuff[2] = random(0, 9);
  testBuff[3] = random(0, 9);
  
  // Set shift register pins as output
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);

  // Set cathode transistor base pins as output
  pinMode(digitPins[0], OUTPUT);
  pinMode(digitPins[1], OUTPUT);
  pinMode(digitPins[2], OUTPUT);
  pinMode(digitPins[3], OUTPUT);
}

// Main loop
void loop() {
  /* Millis test - https://www.baldengineer.com/millis-tutorial.html */
  unsigned long currentMillis = millis();
  
  if ((unsigned long)(currentMillis - previousMillis) >= interval) {
    genRandomNumber();
    previousMillis = millis();
  }
  /* */
  
  for (int i=0; i<4; i++) {
    //writeDigit( encodeNumber( testNum[i] ) );
    writeDigit( encodeNumber( testBuff[i] ) );
    selectDigit(i);
    delay(5); /* 5 */
  }
  
}

// Convert a number (0-9) to binary encoded decimal
int encodeNumber(int x) {
  return decVals[x];
}

// Select which digit to write to (open relevant cathode transistor)
void selectDigit(int digit) {
  digitalWrite(digitPins[0][0], LOW);
  digitalWrite(digitPins[1][0], LOW);
  digitalWrite(digitPins[2][0], LOW);
  digitalWrite(digitPins[3][0], LOW);
  
  digitalWrite(digitPins[digit][0], HIGH);
}

// Write digit to LED digit
void writeDigit(byte val) {
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, byte(val));
  digitalWrite(latchPin, HIGH);
}

// Generate random number
void genRandomNumber() {
  randomSeed(analogRead(0));
  testBuff[0] = random(1, 9);
  testBuff[1] = random(0, 9);
  testBuff[2] = random(0, 9);
  testBuff[3] = random(0, 9);
}
