/*
 * sketch_mar17a-esp8266-blink-test.ino
 * Date: 2017-03-17
 * 
 * ESP8266 Blink/WiFi test
 * 
 * Unfinished code, I think this just connects to WiFi and blinks LEDs
 *
 * Copyright (c) 2026 Christopher Elison <chriselison.uk>
 * Licensed under the MIT License.
 */

// DefaultSSID: AI-THINKER_169589   MAC: a2:20:a6:16:95:89

/*
 Based on ESP8266 Blink by Simon Peter
 
 The blue LED on the ESP-01 module is connected to GPIO1 
 (which is also the TXD pin; so we cannot use Serial.print() at the same time)
 
 Note that this sketch uses LED_BUILTIN to find the pin with the internal LED
*/

#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>

// WiFi AP details
const char* ssid = "WIFI_SSID";
const char* password = "WIFI_PASSWORD";

ESP8266WebServer server(80);

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

  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  if (WiFi.status() == WL_CONNECTED) {
    Serial.print("Connected to network: ");
    Serial.println(ssid);
    Serial.print("Server IP: ");
    Serial.println(WiFi.localIP());
  } else {
    Serial.println("WiFi not connected!");
  }
}

void loop() {
  digitalWrite(ledRed, HIGH);                  
  delay(1000);
  digitalWrite(ledRed, LOW);                  
  delay(1000);

  digitalWrite(ledGrn, HIGH);                  
  delay(1000);
  digitalWrite(ledGrn, LOW);                  
  delay(1000);

  digitalWrite(ledBlu, HIGH);                  
  delay(1000);
  digitalWrite(ledBlu, LOW);                  
  delay(1000);
}
