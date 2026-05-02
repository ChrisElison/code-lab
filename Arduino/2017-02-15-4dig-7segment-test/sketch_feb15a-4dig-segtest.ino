/*
 * sketch_feb15a-4dig-segtest.ino
 * Date: 2017-02-15
 * 
 * Testing 4-digit 7 segment LED multiplexing with 74HC595
 * 
 * Using 74HC595 & 4 transistors/Mosfets to multiplex 4 digits
 *
 * Copyright (c) 2026 Christopher Elison <chriselison.uk>
 * Licensed under the MIT License.
 */

int latchPin  = 8;
int clockPin  = 12;
int dataPin   = 11;

int digitPins[4][1] = {
  {7}, {6}, {5}, {4}
};

int j = 0;

/*
int digitPin1 = 7;
int digitPin2 = 6;
int digitPin3 = 5;
int digitPin4 = 4;
*/

// Decimal values for LED states
int decVals[] {63, 6, 91, 79, 102, 109, 125, 7, 127, 103};

void setup() {
  //Serial.begin(9600);
  
  // Set shift register pins as output
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  
  pinMode(digitPins[0], OUTPUT);
  pinMode(digitPins[1], OUTPUT);
  pinMode(digitPins[2], OUTPUT);
  pinMode(digitPins[3], OUTPUT);
}

void loop() {
  if (j > 9) {
    j = 0;
  }
  
  for (int i=0; i<4; i++) {
    writeDigit(decVals[j]);
    selectDigit(i);
    delay(200); /* 5 */
  }
  j++;
  //Serial.println("");
}

// Select which digit to write to
void selectDigit(int digit) {
  //Serial.print("Selected digit: ");
  //Serial.println(digit);
  
  digitalWrite(digitPins[0][0], LOW);
  digitalWrite(digitPins[1][0], LOW);
  digitalWrite(digitPins[2][0], LOW);
  digitalWrite(digitPins[3][0], LOW);
  
  digitalWrite(digitPins[digit][0], HIGH);
}

// Write digit to LED digit
void writeDigit(byte val) {
  //Serial.print("Write digit: ");
  //Serial.println(val);
  
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, byte(val));
  digitalWrite(latchPin, HIGH);
}
