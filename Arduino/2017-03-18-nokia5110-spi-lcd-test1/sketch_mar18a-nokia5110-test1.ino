/*
 * sketch_mar18a-nokia5110-test1.ino
 * Date: 2017-03-18
 * 
 * Nokia 5110 LCD Test
 * 
 * Display a message on the Nokia 5110 SPI LCD display
 *
 * Copyright (c) 2026 Christopher Elison <chriselison.uk>
 * Licensed under the MIT License.
 */

/*
  Nokia 5110 LCD - 3.3V - PCD8544 - 84x48 dot matrix
  
  LCD Module pins:    Arduino:
    1 - RST           (8)  Orange
    2 - CE            (10) Yellow
    3 - DC            (9)  Blue
    4 - DIN           (11) Green
    5 - CLK           (13) Yellow
    6 - VCC (+3.3V)
    7 - BL  (+3.3V)
    8 - GND
*/
#include <Arduino.h>
#include <U8g2lib.h>

#ifdef U8X8_HAVE_HW_SPI
#include <SPI.h>
#endif
#ifdef U8X8_HAVE_HW_I2C
#include <Wire.h>
#endif

U8G2_PCD8544_84X48_1_4W_SW_SPI u8g2(U8G2_R0, /* clock=*/ 13, /* data=*/ 11, /* cs=*/ 10, /* dc=*/ 9, /* reset=*/ 8);  // Nokia 5110 Display
//U8G2_PCD8544_84X48_1_4W_HW_SPI u8g2(U8G2_R0, /* cs=*/ 10, /* dc=*/ 9, /* reset=*/ 8);           // Nokia 5110 Display

void setup() {
  Serial.begin(9600);
  u8g2.begin();
  u8g2.setContrast(140);
}

void loop() {
  u8g2.firstPage();
  do {
    //u8g2.setFont(u8g2_font_ncenB14_tr);
    u8g2.setFont(u8g2_font_helvB24_tf);
    u8g2.drawStr(0,28,"Hello");

    u8g2.setFont(u8g2_font_crox4hb_tr);
    u8g2.drawStr(0,45,"Insta! :D");
  } while ( u8g2.nextPage() );
  //delay(1000)
}
