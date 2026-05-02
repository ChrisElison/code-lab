/*
 * sketch_apr08a-max7219-matrix-nano-test.ino
 * Date: 2017-04-08
 * 
 * MAX7219 8x8 LED matrix test - Arduino Nano
 * 
 * Testing the MAX7219 LED matrix module
 *
 * Copyright (c) 2026 Christopher Elison <chriselison.uk>
 * Licensed under the MIT License.
 */

#include "LedControl.h"

LedControl lc = LedControl(12, 11, 10, 1);  // DIN (White), CLK (Orange), CS (Black), Matrices

unsigned long delayTime = 800;

void setup() {
  lc.shutdown(0, false);
  lc.setIntensity(0, 4);
  lc.clearDisplay(0);
}

void loop() {
  //writeArduinoOnMatrix();
  sayHello();
}

void writeArduinoOnMatrix() {
  /* here is the data for the characters */
  byte a[5]={B01111110,B10001000,B10001000,B10001000,B01111110};
  byte r[5]={B00111110,B00010000,B00100000,B00100000,B00010000};
  byte d[5]={B00011100,B00100010,B00100010,B00010010,B11111110};
  byte u[5]={B00111100,B00000010,B00000010,B00000100,B00111110};
  byte i[5]={B00000000,B00100010,B10111110,B00000010,B00000000};
  byte n[5]={B00111110,B00010000,B00100000,B00100000,B00011110};
  byte o[5]={B00011100,B00100010,B00100010,B00100010,B00011100};

  /* now display them one by one with a small delay */
  lc.setRow(0,0,a[0]);
  lc.setRow(0,1,a[1]);
  lc.setRow(0,2,a[2]);
  lc.setRow(0,3,a[3]);
  lc.setRow(0,4,a[4]);
  delay(delayTime);
  lc.setRow(0,0,r[0]);
  lc.setRow(0,1,r[1]);
  lc.setRow(0,2,r[2]);
  lc.setRow(0,3,r[3]);
  lc.setRow(0,4,r[4]);
  delay(delayTime);
  lc.setRow(0,0,d[0]);
  lc.setRow(0,1,d[1]);
  lc.setRow(0,2,d[2]);
  lc.setRow(0,3,d[3]);
  lc.setRow(0,4,d[4]);
  delay(delayTime);
  lc.setRow(0,0,u[0]);
  lc.setRow(0,1,u[1]);
  lc.setRow(0,2,u[2]);
  lc.setRow(0,3,u[3]);
  lc.setRow(0,4,u[4]);
  delay(delayTime);
  lc.setRow(0,0,i[0]);
  lc.setRow(0,1,i[1]);
  lc.setRow(0,2,i[2]);
  lc.setRow(0,3,i[3]);
  lc.setRow(0,4,i[4]);
  delay(delayTime);
  lc.setRow(0,0,n[0]);
  lc.setRow(0,1,n[1]);
  lc.setRow(0,2,n[2]);
  lc.setRow(0,3,n[3]);
  lc.setRow(0,4,n[4]);
  delay(delayTime);
  lc.setRow(0,0,o[0]);
  lc.setRow(0,1,o[1]);
  lc.setRow(0,2,o[2]);
  lc.setRow(0,3,o[3]);
  lc.setRow(0,4,o[4]);
  delay(delayTime);
  lc.setRow(0,0,0);
  lc.setRow(0,1,0);
  lc.setRow(0,2,0);
  lc.setRow(0,3,0);
  lc.setRow(0,4,0);
  delay(delayTime);
}

void sayHello() {
  const byte anim0[8] = {B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000};
  const byte animh[8] = {B00100100,B00100100,B00100100,B00111100,B00100100,B00100100,B00100100,B00100100};
  const byte anime[8] = {B00111100,B00100000,B00100000,B00111100,B00100000,B00100000,B00100000,B00111100};
  const byte animl[8] = {B00100000,B00100000,B00100000,B00100000,B00100000,B00100000,B00100000,B00111100};
  const byte animo[8] = {B00111100,B00100100,B00100100,B00100100,B00100100,B00100100,B00100100,B00111100};
  const byte animx[8] = {B00000100,B00000100,B00000100,B00000100,B00000100,B00000000,B00000100,B00000100};
  const byte heart[8] = {B01100110,B11100111,B11111111,B11111111,B11111111,B01111110,B00111100,B00011000};

  lc.setRow(0,0,anim0[0]);
  lc.setRow(0,1,anim0[1]);
  lc.setRow(0,2,anim0[2]);
  lc.setRow(0,3,anim0[3]);
  lc.setRow(0,4,anim0[4]);
  lc.setRow(0,5,anim0[5]);
  lc.setRow(0,6,anim0[6]);
  lc.setRow(0,7,anim0[7]);
  delay(delayTime);
  
  lc.setRow(0,0,animh[0]);
  lc.setRow(0,1,animh[1]);
  lc.setRow(0,2,animh[2]);
  lc.setRow(0,3,animh[3]);
  lc.setRow(0,4,animh[4]);
  lc.setRow(0,5,animh[5]);
  lc.setRow(0,6,animh[6]);
  lc.setRow(0,7,animh[7]);
  delay(delayTime);

  lc.setRow(0,0,anime[0]);
  lc.setRow(0,1,anime[1]);
  lc.setRow(0,2,anime[2]);
  lc.setRow(0,3,anime[3]);
  lc.setRow(0,4,anime[4]);
  lc.setRow(0,5,anime[5]);
  lc.setRow(0,6,anime[6]);
  lc.setRow(0,7,anime[7]);
  delay(delayTime);

  lc.setRow(0,0,animl[0]);
  lc.setRow(0,1,animl[1]);
  lc.setRow(0,2,animl[2]);
  lc.setRow(0,3,animl[3]);
  lc.setRow(0,4,animl[4]);
  lc.setRow(0,5,animl[5]);
  lc.setRow(0,6,animl[6]);
  lc.setRow(0,7,animl[7]);
  delay(delayTime);
  
  lc.clearDisplay(0);
  delay(50);

  lc.setRow(0,0,animl[0]);
  lc.setRow(0,1,animl[1]);
  lc.setRow(0,2,animl[2]);
  lc.setRow(0,3,animl[3]);
  lc.setRow(0,4,animl[4]);
  lc.setRow(0,5,animl[5]);
  lc.setRow(0,6,animl[6]);
  lc.setRow(0,7,animl[7]);
  delay(delayTime);

  lc.setRow(0,0,animo[0]);
  lc.setRow(0,1,animo[1]);
  lc.setRow(0,2,animo[2]);
  lc.setRow(0,3,animo[3]);
  lc.setRow(0,4,animo[4]);
  lc.setRow(0,5,animo[5]);
  lc.setRow(0,6,animo[6]);
  lc.setRow(0,7,animo[7]);
  delay(delayTime);

  lc.setRow(0,0,animx[0]);
  lc.setRow(0,1,animx[1]);
  lc.setRow(0,2,animx[2]);
  lc.setRow(0,3,animx[3]);
  lc.setRow(0,4,animx[4]);
  lc.setRow(0,5,animx[5]);
  lc.setRow(0,6,animx[6]);
  lc.setRow(0,7,animx[7]);
  delay(delayTime);

  lc.setRow(0,0,heart[0]);
  lc.setRow(0,1,heart[1]);
  lc.setRow(0,2,heart[2]);
  lc.setRow(0,3,heart[3]);
  lc.setRow(0,4,heart[4]);
  lc.setRow(0,5,heart[5]);
  lc.setRow(0,6,heart[6]);
  lc.setRow(0,7,heart[7]);
  delay(delayTime);
}

