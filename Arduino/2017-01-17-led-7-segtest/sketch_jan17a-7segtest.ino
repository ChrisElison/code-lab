/*
 * sketch_jan17a-7segtest.ino
 * Date: 2017-01-17
 * 
 * Single 7 segment LED display test
 * 
 * This was my attempt at displaying numbers on a 7 segment LED before I
 * discovered shift registers! Apologies for the terrible code!
 *
 * Copyright (c) 2026 Christopher Elison <chriselison.uk>
 * Licensed under the MIT License.
 */

// Map LED pins to IO pins (pins 3, 8 not needed)
const int p1  = 6;
const int p2  = 7;
const int p4  = 8;
const int p5  = 9;
const int p6  = 11;
const int p7  = 10;
const int p9  = 5;
const int p10 = 4;

int pinMap[8][1] = {
  {4},
  {5},
  {6},
  {7},
  {8},
  {9},
  {10},
  {11}
};

byte num_0[] = {0,1,1,1,1,0,1,1};
byte num_1[] = {0,0,0,0,1,0,0,1};
byte num_2[] = {1,0,1,1,0,0,1,1};
byte num_3[] = {1,0,0,1,1,0,1,1};
byte num_4[] = {1,1,0,0,1,0,0,1};
byte num_5[] = {1,1,0,1,1,0,1,0};
byte num_6[] = {1,1,1,1,1,0,1,0};
byte num_7[] = {0,0,0,0,1,0,1,1};
byte num_8[] = {1,1,1,1,1,0,1,1};
byte num_9[] = {1,1,0,1,1,0,1,1};

byte char_dot[] = {0,0,0,0,0,1,0,0};

void setup() {
  Serial.begin(9600);
  int i;
  for (i=0; i<8; i++) {
    int j = pinMap[i][0];
    Serial.print("Setting pin ");
    Serial.print(j);
    Serial.print(" to output!\n");
    pinMode(pinMap[i][0], OUTPUT);
  }
}

void loop() {
  render(num_0);
  delay(1000);
  render(num_1);
  delay(1000);
  render(num_2);
  delay(1000);
  render(num_3);
  delay(1000);
  render(num_4);
  delay(1000);
  render(num_5);
  delay(1000);
  render(num_6);
  delay(1000);
  render(num_7);
  delay(1000);
  render(num_8);
  delay(1000);
  render(num_9);
  delay(1000);
  render(char_dot);
  delay(1000);
  
  /* DEBUG 
  int i;
  for (i=0; i<=8; i++) {
    digitalWrite(pinMap[i][0], HIGH);
    delay(1000);
    digitalWrite(pinMap[i][0], LOW);
  }
  */
}

void render(byte n[]) {
  int i;
  
  for (i=0; i<=8; i++) {
    //Serial.println(n[i]);
    if (int(n[i]) == 1) {
      digitalWrite(pinMap[i][0], HIGH); 
    } else { 
      digitalWrite(pinMap[i][0], LOW); 
    }
  }
}
