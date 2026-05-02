/*
 * sketch_mar20a-esp8266-mac-addr-test.ino
 * Date: 2017-03-20
 * 
 * ESP8266 Get Mac addresses test
 * 
 * Display ESP8266 MAC address in serial monitor
 *
 * Copyright (c) 2026 Christopher Elison <chriselison.uk>
 * Licensed under the MIT License.
 */

#include <ESP8266WiFi.h>
#include <WiFiClient.h>

uint8_t MAC_array[6];
char MAC_char[18];

uint8_t MAC_array2[6];
char MAC_char2[18];

void setup() {
  Serial.begin(115200);
  
  Serial.println();
  Serial.println("WiFi.macAddress:");
  
  WiFi.macAddress(MAC_array);
  
  for (int i = 0; i < sizeof(MAC_array); ++i) {
    sprintf(MAC_char,"%s%02x:",MAC_char,MAC_array[i]);
  }
  
  Serial.println(MAC_char);


  Serial.println();
  Serial.println("WiFi.softAPmacAddress:");
  
  WiFi.softAPmacAddress(MAC_array2);
  
  for (int i = 0; i < sizeof(MAC_array2); ++i) {
    sprintf(MAC_char2,"%s%02x:",MAC_char2,MAC_array2[i]);
  }
  
  Serial.println(MAC_char2);
}

void loop() {
  
}
