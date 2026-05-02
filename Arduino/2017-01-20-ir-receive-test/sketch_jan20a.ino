/*
 * sketch_jan20a.ino
 * Date: 2017-01-20
 * 
 * Infrared receiver/send test
 * 
 * Not sure if this works, was trying to receive and decode IR signals using my TV remote
 *
 * Copyright (c) 2026 Christopher Elison <chriselison.uk>
 * Licensed under the MIT License.
 */

/*
    Pins:
    
    G - Ground (Blue/Black)
    R - VCC (Red)
    Y - Data (Yellow)
    
*/

#include <IRremote.h>
#include <IRremoteInt.h>

bool inputEnabled = true;
const int greenBtnPin = 6;
const int IRrecvPin = 11;

IRrecv irrecv(IRrecvPin);
IRsend irsend;
decode_results results;

void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn();
  irsend.enableIROut(38);
}

void loop() {
  if (inputEnabled == true) {
    testSendIR();
  }
  
  if (irrecv.decode(&results)) {
    Serial.print("Code: "); Serial.println(results.value, HEX);
    Serial.print("Type: "); Serial.println(results.decode_type);
    Serial.print("Bits: "); Serial.println(results.bits);
    Serial.print("Raw length: "); Serial.println(results.rawlen);
    Serial.print("Raw buffer: "); //Serial.println(results.rawbuf[0]);

    for (int i=0; i<results.rawlen; i++) {
      Serial.print(results.rawbuf[i]);
      Serial.print(", ");
    }
    Serial.println("");

    // Elegoo remote control codes
    if ( results.value == 0xFF6897 ) { Serial.println("Pressed 0 (Elegoo)"); }
    if ( results.value == 0xFF30CF ) { Serial.println("Pressed 1 (Elegoo)"); }
    if ( results.value == 0xFF18E7 ) { Serial.println("Pressed 2 (Elegoo)"); }
    if ( results.value == 0xFF7A85 ) { Serial.println("Pressed 3 (Elegoo)"); }
    if ( results.value == 0xFF10EF ) { Serial.println("Pressed 4 (Elegoo)"); }
    if ( results.value == 0xFF38C7 ) { Serial.println("Pressed 5 (Elegoo)"); }
    if ( results.value == 0xFF5AA5 ) { Serial.println("Pressed 6 (Elegoo)"); }
    if ( results.value == 0xFF42BD ) { Serial.println("Pressed 7 (Elegoo)"); }
    if ( results.value == 0xFF4AB5 ) { Serial.println("Pressed 8 (Elegoo)"); }
    if ( results.value == 0xFF52AD ) { Serial.println("Pressed 9 (Elegoo)"); }

    // TV (Technika) remote control codes
    if ( results.value == 0xFE58A7 ) { Serial.println("Pressed 0 (Technika)"); }
    if ( results.value == 0xFE708F ) { Serial.println("Pressed 1 (Technika)"); }
    if ( results.value == 0xFE609F ) { Serial.println("Pressed 2 (Technika)"); }
    if ( results.value == 0xFEF00F ) { Serial.println("Pressed 3 (Technika)"); }
    if ( results.value == 0xFE48B7 ) { Serial.println("Pressed 4 (Technika)"); }
    if ( results.value == 0xFEE01F ) { Serial.println("Pressed 5 (Technika)"); }
    if ( results.value == 0xFEC837 ) { Serial.println("Pressed 6 (Technika)"); }
    if ( results.value == 0xFE6897 ) { Serial.println("Pressed 7 (Technika)"); }
    if ( results.value == 0xFE40BF ) { Serial.println("Pressed 8 (Technika)"); }
    if ( results.value == 0xFEE817 ) { Serial.println("Pressed 9 (Technika)"); }

    Serial.println("");
    
    irrecv.resume();
  }
}

void testSendIR() {
  //unsigned int testBuff[] = {2901, 178, 89, 11, 12, 11, 12, 11, 12, 11, 12, 11, 12, 11, 12, 11, 12, 11, 11, 11, 34, 11, 33, 11, 33, 11, 33, 11, 33, 11, 34, 11, 33, 11, 33, 11, 12, 11, 12, 11, 33, 11, 33, 11, 12, 11, 12, 11, 12, 11, 12, 11, 33, 11, 33, 11, 12, 11, 12, 11, 33, 11, 33, 11, 33, 11, 33, 11};
  unsigned int testBuff[] = {50458, 176, 89, 11, 11, 10, 12, 10, 12, 11, 11, 10, 12, 11, 11, 11, 11, 10, 12, 11, 33, 11, 33, 11, 34, 10, 33, 11, 33, 11, 34, 10, 34, 10, 12, 10, 12, 11, 34, 9, 34, 10, 34, 11, 11, 10, 12, 11, 11, 11, 11, 11, 33, 11, 11, 11, 12, 10, 11, 11, 34, 10, 34, 10, 33, 11, 34, 10};
  irsend.sendRaw(testBuff, 68, 38);
  irsend.sendRaw(testBuff, 68, 38);
  irsend.sendRaw(testBuff, 68, 38);

  //irsend.sendSony(0xa90, 12);
  inputEnabled = false;
}
