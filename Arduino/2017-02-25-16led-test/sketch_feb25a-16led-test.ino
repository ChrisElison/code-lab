/*
 * sketch_feb25a-16led-test.ino
 * Date: 2017-02-25
 * 
 * Shift register 16 LED test
 * 
 * Using 2 chained shift registers to control 16 LEDs with just 3 wires!
 *
 * Copyright (c) 2026 Christopher Elison <chriselison.uk>
 * Licensed under the MIT License.
 */

int latchPin = 8;
int clockPin = 12;
int dataPin  = 11;
int delayVal = 100;
int testNums[] = {1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384};

void setup() {
  //Serial.begin(9600);
  
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);

  //randomSeed(analogRead(0));
}

void loop() {
  //unsigned int j = random(0, 65535);
  //Serial.println(j);

  // Anim frame 0
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, B00000000);
  shiftOut(dataPin, clockPin, LSBFIRST, B00000000);
  digitalWrite(latchPin, HIGH);
  delay(delayVal);

  // Anim frame 1
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, B10000000);
  shiftOut(dataPin, clockPin, LSBFIRST, B00000001);
  digitalWrite(latchPin, HIGH);
  delay(delayVal);
  
  // Anim frame 2
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, B11000000);
  shiftOut(dataPin, clockPin, LSBFIRST, B00000011);
  digitalWrite(latchPin, HIGH);
  delay(delayVal);
  
  // Anim frame 3
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, B00110000);
  shiftOut(dataPin, clockPin, LSBFIRST, B00001100);
  digitalWrite(latchPin, HIGH);
  delay(delayVal);

  // Anim frame 4
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, B00001100);
  shiftOut(dataPin, clockPin, LSBFIRST, B00110000);
  digitalWrite(latchPin, HIGH);
  delay(delayVal);

  // Anim frame 5
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, B00000011);
  shiftOut(dataPin, clockPin, LSBFIRST, B11000000);
  digitalWrite(latchPin, HIGH);
  delay(delayVal);

  // Anim frame 6
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, B00000001);
  shiftOut(dataPin, clockPin, LSBFIRST, B10000000);
  digitalWrite(latchPin, HIGH);
  delay(delayVal);

  // Anim frame 5
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, B00000011);
  shiftOut(dataPin, clockPin, LSBFIRST, B11000000);
  digitalWrite(latchPin, HIGH);
  delay(delayVal);

  // Anim frame 4
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, B00001100);
  shiftOut(dataPin, clockPin, LSBFIRST, B00110000);
  digitalWrite(latchPin, HIGH);
  delay(delayVal);

  // Anim frame 3
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, B00110000);
  shiftOut(dataPin, clockPin, LSBFIRST, B00001100);
  digitalWrite(latchPin, HIGH);
  delay(delayVal);

  // Anim frame 2
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, B11000000);
  shiftOut(dataPin, clockPin, LSBFIRST, B00000011);
  digitalWrite(latchPin, HIGH);
  delay(delayVal);

  // Anim frame 1
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, B10000000);
  shiftOut(dataPin, clockPin, LSBFIRST, B00000001);
  digitalWrite(latchPin, HIGH);
  delay(delayVal);

  // Anim frame 0
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, B00000000);
  shiftOut(dataPin, clockPin, LSBFIRST, B00000000);
  digitalWrite(latchPin, HIGH);
  delay(delayVal);

  /*
  int i=0;
  for (i=0; i<15; i++) {
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, (word)testNums[i]);
    digitalWrite(latchPin, HIGH);
    delay(delayVal);
  }
  */
  
}
