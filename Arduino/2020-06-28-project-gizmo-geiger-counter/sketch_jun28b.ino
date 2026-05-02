/*
 * sketch_jun28b.ino
 * Date: 2020-06-28
 * 
 * Project Gizmo - V2.0
 * 
 * Rough prototype for my data-logging Geiger counter
 *
 * Copyright (c) 2026 Christopher Elison <chriselison.uk>
 * Licensed under the MIT License.
 */

// Created:  2020-06-28 23:49 BST
// Modified: 2020-06-30 06:43 BST
// Project Gizmo - V2.0

// Schedule a scan every 5/10/15 minutes, switch on the 555 timer and measure clicks over 1 minute, display
// the result on the OLED. Submit the CPM/uSh value to ThingSpeak & GMCmap.com!

// By Christopher David Elison - chriselison.uk

// Thanks to Radu Motisan, Danyk for the inspiration and technical info!

//#include "ThingSpeak.h"
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>
#include <U8g2lib.h>
#include <Wire.h>
#include "RTClib.h"

U8G2_SSD1306_128X64_NONAME_1_SW_I2C u8g2(U8G2_R0, /* clock=*/ SCL, /* data=*/ SDA, /* reset=*/ U8X8_PIN_NONE);
RTC_DS3231 rtc;
WiFiClient client;

const int detect_pin = 14;                             // Geiger tube pulse detect pin
//const int hv_enable_pin = 14;                        // 555 timer HV enable pin
const int hv_led_pin = 16;                             // HV warning LED pin
unsigned int count = 0;                                // Variable to hold pulse count
unsigned int cpm = 0;                                  // Calculated counts per minute
unsigned int scan_count = 0;                           // Number of scans since turn-on
double avg_cpm = 0.00;                                 // Average CPM value
double microsieverts = 0.00;                           // Variable to hold calculated microsieverts value
float conversion_factor = 0.006666;                    // STS-5 conversion factor (Thanks Radu!)
const int tube_warmup_time = 3000;                     // Milliseconds to wait for tube voltage to rise before measuring
const char* wan_ssid = "";                             // Wireless AP SSID
const char* wan_password = "";                         // Wireless AP password (secret)
unsigned long thingspeak_channel_id = ;                // ThingSpeak channel ID
const char* thingspeak_write_key = "";                 // ThingSpeak API write key (secret)
const char* gmcmap_account_id = "";                    // GMCmap.com account ID
const char* gmcmap_counter_id = "";                    // GMCmap.com Geiger counter ID

char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

void setup() {
  // Initiate serial communication and OLED display
  Serial.begin(74880);
  u8g2.begin();

  // Enable input/output pins
  //pinMode(hv_enable_pin, OUTPUT);
  pinMode(hv_led_pin, OUTPUT);
  pinMode(detect_pin, INPUT);
  
  attachInterrupt(digitalPinToInterrupt(detect_pin), detectPulse, RISING);

  digitalWrite(hv_led_pin, LOW);

  Serial.println("\n");
  Serial.println("Geiger Counter Project Gizmo v2.0");
  Serial.println("By Christopher Elison - chriselison.uk");
  Serial.println("--------------------------------------");

  // Connect to the wireless AP
  WiFi.begin(wan_ssid, wan_password);

  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }
  
  Serial.println("");
  
  if (WiFi.status() == WL_CONNECTED) {
    Serial.print("Connected to network: ");
    Serial.print(wan_ssid);
    Serial.println("");
    Serial.print("Local IP: ");
    Serial.print(WiFi.localIP());
    Serial.println("\n");
  } else {
    Serial.println("WiFi not connected!");
  }
  
  // Initialize ThingSpeak
  //ThingSpeak.begin(client);
  
  if (! rtc.begin()) {
    Serial.println("Couldn't find RTC");
    while (1);
  }

  if (rtc.lostPower()) {
    Serial.println("RTC lost power, lets set the time!");
    // following line sets the RTC to the date & time this sketch was compiled
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  }
}

void loop() {
  DateTime now = rtc.now();
  
  char dateTimeStr[] = "YYYY-MM-DD hh:mm:ss";

  checkTime(now.minute(), now.second());

  u8g2.firstPage();
  do {
    u8g2.setFontMode(1);  // Transparent
    u8g2.setFontDirection(0);
    u8g2.setFont(u8g2_font_freedoomr10_mu);
    u8g2.drawStr(0, 18, "PROJECT GIZMO V2");
    u8g2.setFont(u8g2_font_5x8_tf);
    u8g2.drawStr(15,35, now.toString(dateTimeStr));
    
    u8g2.setFont(u8g2_font_5x8_tf);
    //u8g2.drawStr(15,58,"CPM: 0   uS/h: 0.00");
    //u8g2.drawStr(15,58,"CPM: ");

    // Del
    u8g2.setCursor(15,58);
    u8g2.print("CPM: ");
    u8g2.print(cpm);
    u8g2.setCursor(59,58);
    u8g2.print("uS/h: ");
    u8g2.print(microsieverts);
    
  } while ( u8g2.nextPage() );
}

void checkTime(int minute, int second) {
  // Check if minute is multiple of 5 minutes
  if ((minute == 0 || minute == 10 || minute == 20 || minute == 30 || minute == 40 || minute == 50) && second == 0) {
    DateTime now = rtc.now();
    char timeStr[] = "hh:mm:ss";
    
    // Reset count value
    count = 0;
    digitalWrite(hv_led_pin, HIGH);
    Serial.print("[");
    Serial.print(now.toString(timeStr));
    Serial.print("] - Scan starting!\n");
    // Wait one minute
    delay(30000);
    digitalWrite(hv_led_pin, LOW);

    now = rtc.now();
    Serial.print("[");
    Serial.print(now.toString(timeStr));
    Serial.print("] - Scan finished!\n");

    // Convert counts to CPM to uS/h
    calculateSieverts();

    // Submit data to ThingSpeak
    submitThingSpeak();
  }  
}

/*
 *  Submit data to ThingSpeak
*/
void submitThingSpeak() {
  HTTPClient http;
  
  String serverUrl = "http://api.thingspeak.com/update?";
  String serverPath = serverUrl + "api_key=API_KEY_HERE="+ cpm +"&field2="+ cpm +"&field3="+ microsieverts +"&field4=400";

  Serial.print("Debug URL: ");
  Serial.print(serverPath);
  Serial.print("\n");
  
  http.begin(serverPath.c_str());
  
  // Send HTTP GET request
  int httpResponseCode = http.GET();

  Serial.print("Submitted data to ThingSpeak - HTTP code (");
  Serial.print(httpResponseCode);
  Serial.print(")\n");
  
  http.end();
}

/* 
 *  Calculate microsieverts value
*/
void calculateSieverts() {
  cpm = count * 2;
  microsieverts = cpm * conversion_factor;
}

ICACHE_RAM_ATTR void detectPulse() {
  count++;
}
