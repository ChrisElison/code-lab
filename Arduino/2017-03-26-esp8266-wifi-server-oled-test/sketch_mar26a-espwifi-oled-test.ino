/*
 * sketch_mar26a-espwifi-oled-test.ino
 * Date: 2017-03-26
 * 
 * ESP8266/OLED test - Display ESP connection status with 0.96" I2C OLED
 * 
 * Control LEDs from web server page on ESP8266, isplay status on OLED
 *
 * Copyright (c) 2026 Christopher Elison <chriselison.uk>
 * Licensed under the MIT License.
 */

/*
 * Based on HelloServer, SDWebServer (HTTP stuff)
 * - Attempt to connect to WiFi AP
 * - Turn on green LED on successful connection
 * - Start web server
 * - Update OLED with local IP
 * - Update LED when web form data submitted
 */

#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>
#include <U8g2lib.h>

// OLED onstructor
//U8G2_SSD1306_128X64_NONAME_1_SW_I2C u8g2(U8G2_R0, SCL, SDA, U8X8_PIN_NONE);
U8G2_SSD1306_128X64_NONAME_F_SW_I2C u8g2(U8G2_R0, SCL, SDA, U8X8_PIN_NONE);  // Full buffer?

// WiFi AP/network details
const char* ssid      = "WIFI_SSID";     // WiFi SSID to connnect to
const char* password  = "WIFI_PASSWORD"; // Access point passphrase
char* IPAddr          = "";             // Placeholder for DHCP assigned local IP
const char* HTTPport  = "80";           // Web server listen port
char* serverInfo = "";

// Web server constructor
ESP8266WebServer HTTPserver(atoi(HTTPport));

// LED GPIO pins
const int ledRed = 12;
const int ledGrn = 14;
const int ledBlu = 13;

bool ledState = 0; // Blue LED state on/off

void setup() {
  Serial.begin(115200);         // Begin serial monitor output (debugging)
  pinMode(ledRed, OUTPUT);
  pinMode(ledGrn, OUTPUT);
  pinMode(ledBlu, OUTPUT);
  
  u8g2.begin();                 // Initialise OLED
  WiFi.begin(ssid, password);   // Begin WiFi connection
  digitalWrite(ledRed, HIGH);   // Turn red LED on until connection made
  
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
    IPAddr = WiFi.localIP().toCharArray();
    Serial.println(WiFi.localIP());
    digitalWrite(ledRed, LOW);
    digitalWrite(ledGrn, HIGH);
  }

  strcat(serverInfo, IPAddr);
  strcat(serverInfo, ":");
  strcat(serverInfo, HTTPport);

  // HTTP server URL handlers
  HTTPserver.on("/", handleRoot);
  HTTPserver.on("/led-on", turnLedOn);
  HTTPserver.on("/led-off", turnLedOff);
  HTTPserver.begin();
}

void loop() {
  u8g2.clearBuffer();          // clear the internal memory
  u8g2.setFontDirection(0);
  u8g2.setFont(u8g2_font_helvB10_tr);
  u8g2.drawStr(1,14,"WiFi Connected!");

  u8g2.setFont(u8g2_font_helvR08_tr);
  u8g2.drawStr(1,34,"Web server started at:");
  u8g2.drawStr(1,48,serverInfo);

  // Check if blue LED is on or off
  if (ledState == 0) {
    u8g2.drawStr(20,62,"LED status: OFF");
  } else {
    u8g2.drawStr(20,63,"LED status: ON");
  }
  u8g2.sendBuffer();          // transfer internal memory to the display
  
  HTTPserver.handleClient();
  delay(500); 
}

void handleRoot() {
  String resp = "\
<!DOCTYPE html>\n\
<html>\n\
  <head>\n\
    <meta charset=\"utf-8\">\n\
    <title>LED Admin Panel</title>\n\
    <style>\n\
      body { color: #333; font-family: Arial, Sans-serif\; }\n\
      .btn { color: #333; background-color: #ddd; border: 1px solid #333; font-weight: bold; padding: 10px; text-decoration: none; }\n\
      .btn:hover { background-color: #eaeaea; }\n\
      h2 { color: #d5d5d5; font-family: Segoe UI, Sans-serif; }\n\
      h3 { padding-bottom: 20px; }\n\
    </style>\n\
  </head>\n\
  <body>\n\
    <h2>NodeMCU ESP8266-12E</h2>\n";

    if (ledState == 0) {
      resp = resp + "<h3>Blue LED state: Off</h3>\n";
    } else {
      resp = resp + "<h3>Blue LED state: On</h3>\n";
    }
    
    resp = resp + "\
    <a class=\"btn\" href=\"/led-on\">Turn LED ON</a>\n\
    <a class=\"btn\" href=\"/led-off\">Turn LED OFF</a>\n\
  </body>\n\
</html>\n";

  HTTPserver.send(200, "text/html", resp);
}

void turnLedOn() {
  ledState = 1;
  digitalWrite(ledBlu, HIGH);
  
  HTTPserver.sendHeader("Location", String("/"), true);
  HTTPserver.send(302, "text/plain", "");
}

void turnLedOff() {
  ledState = 0;
  digitalWrite(ledBlu, LOW);
  
  HTTPserver.sendHeader("Location", String("/"), true);
  HTTPserver.send(302, "text/plain", "");
}

