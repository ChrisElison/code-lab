/*
 * sketch_mar01a-ir-send-test.ino
 * Date: 2017-03-01
 * 
 * IR send test
 * 
 * Unfinished code, just a test, don't know what I was trying to achieve
 *
 * Copyright (c) 2026 Christopher Elison <chriselison.uk>
 * Licensed under the MIT License.
 */

#include <IRremote.h>
#include <IRremoteInt.h>

IRsend irsend;

unsigned int testBuff[] = {2901, 178, 89, 11, 12, 11, 12, 11, 12, 11, 12, 11, 12, 11, 12, 11, 12, 11, 11, 11, 34, 11, 33, 11, 33, 11, 33, 11, 33, 11, 34, 11, 33, 11, 33, 11, 12, 11, 12, 11, 33, 11, 33, 11, 12, 11, 12, 11, 12, 11, 12, 11, 33, 11, 33, 11, 12, 11, 12, 11, 33, 11, 33, 11, 33, 11, 33, 11};
unsigned int testBuff2[] = {50458, 176, 89, 11, 11, 10, 12, 10, 12, 11, 11, 10, 12, 11, 11, 11, 11, 10, 12, 11, 33, 11, 33, 11, 34, 10, 33, 11, 33, 11, 34, 10, 34, 10, 12, 10, 12, 11, 34, 9, 34, 10, 34, 11, 11, 10, 12, 11, 11, 11, 11, 11, 33, 11, 11, 11, 12, 10, 11, 11, 34, 10, 34, 10, 33, 11, 34, 10};

void setup() {
  
}

void loop() {
  irsend.sendNEC(0xFE708F, 32);
  delay(120);
  irsend.sendNEC(0xFEF00F, 32);
  delay(120);
  irsend.sendNEC(0xFE58A7, 32);
  
  delay(5000);
}
