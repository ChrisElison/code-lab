/*
 * sketch_jun28a.ino
 * Date: 2020-06-28
 * 
 * Project Gizmo - Display the date/time on an 0.96" I2C OLED display!
 * 
 * Displaying date/time on OLED using DS3231 RTC module
 *
 * Copyright (c) 2026 Christopher Elison <chriselison.uk>
 * Licensed under the MIT License.
 */

#include <U8g2lib.h>
#include <Wire.h>
#include "RTClib.h"

U8G2_SSD1306_128X64_NONAME_1_SW_I2C u8g2(U8G2_R0, /* clock=*/ SCL, /* data=*/ SDA, /* reset=*/ U8X8_PIN_NONE);
RTC_DS3231 rtc;

#define MINI_LOGO

char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

void setup() {
  Serial.begin(9600);
  u8g2.begin();

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
  //Serial.print(now.toString(dateTimeStr));

  u8g2.firstPage();
  do {
    u8g2.setFontMode(1);  // Transparent
    u8g2.setFontDirection(0);
    u8g2.setFont(u8g2_font_freedoomr10_mu);
    u8g2.drawStr(0, 18, "PROJECT GIZMO V1.2");
    u8g2.setFont(u8g2_font_5x8_tf);
    u8g2.drawStr(10,35, now.toString(dateTimeStr));
    
    //u8g2.drawHLine(2, 35, 47);
    //u8g2.drawHLine(3, 36, 47);
    //u8g2.drawVLine(45, 32, 12);
    //u8g2.drawVLine(46, 33, 12);

    u8g2.setFont(u8g2_font_5x8_tf);
    u8g2.drawStr(10,58,"CPM: 0   uS/h: 0.00");
    
  } while ( u8g2.nextPage() );
}
