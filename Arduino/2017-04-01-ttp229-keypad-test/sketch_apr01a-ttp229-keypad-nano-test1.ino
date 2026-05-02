/*
 * sketch_apr01a-ttp229-keypad-nano-test1.ino
 * Date: 2017-04-01
 * 
 * TTP229 capacitive touch keypad - Test 1 (Arduino Nano)
 * 
 * Testing the TTP229 touch keypad
 *
 * Copyright (c) 2026 Christopher Elison <chriselison.uk>
 * Licensed under the MIT License.
 */

/*
 * Based on code at http://forum.hobbycomponents.com/viewtopic.php?f=73&t=1781&hilit=hcmodu0079
*/

// Nano pins for I2C clock/data
#define SCL_PIN 8
#define SDO_PIN 9

byte key;

void setup() {
  Serial.begin(9600);
  pinMode(SCL_PIN, OUTPUT);
  pinMode(SDO_PIN, INPUT);
}

void loop() {
  key = keypad_read();

  if (key) {
    Serial.print("Key pressed: ");
    Serial.println(key); 
  }
  
  delay(500);
}

byte keypad_read() {
  byte count;
  byte key_state = 0;

  for (count=1; count<=16; count++) {
    digitalWrite(SCL_PIN, LOW);

    if (!digitalRead(SDO_PIN)) {
      key_state = count;
    }
    
    digitalWrite(SCL_PIN, HIGH);
  }

  return key_state;
}

