/*
 * sketch_mar20b-esp8266-wifi-connect-test.ino
 * Date: 2017-03-20
 * 
 * ESP8266 WiFi connection test
 * 
 * Connect to WiFi AP using ESP8266
 *
 * Copyright (c) 2026 Christopher Elison <chriselison.uk>
 * Licensed under the MIT License.
 */

/*
  DefaultSSID: AI-THINKER_169589
  AP MAC: a2:20:a6:16:95:89
  ST MAC: a0:20:a6:16:95:89
*/

#include <ESP8266WiFi.h>
#include <WiFiClient.h>

// WiFi AP details
const char* ssid = "WIFI_SSID";
const char* password = "WIFI_PASSWORD";

// LED GPIO pins
const int ledRed = 5;
const int ledGrn = 4;
const int ledBlu = 14;

void setup() {
  pinMode(ledRed, OUTPUT);
  pinMode(ledGrn, OUTPUT);
  pinMode(ledBlu, OUTPUT);

  Serial.begin(115200);
  WiFi.begin(ssid, password);
  digitalWrite(ledRed, HIGH);
  
  Serial.println();
  Serial.println("Attempting to connect to wireless network...");
  
  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }

  if (WiFi.status() == WL_CONNECTED) {
    Serial.println();
    Serial.print("Connected to network: ");
    Serial.println(ssid);
    Serial.print("Local IP: ");
    Serial.println(WiFi.localIP());
    digitalWrite(ledRed, LOW);
    digitalWrite(ledGrn, HIGH);
  }
}

void loop() {
  
}
