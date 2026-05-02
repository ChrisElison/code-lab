/*
 * sketch_jan13a.ino
 * Date: 2017-01-13
 * 
 * Prints temperature to 16x2 LCD display
 *
 * Copyright (c) 2026 Christopher Elison <chriselison.uk>
 * Licensed under the MIT License.
 */

#include <dht.h>
#include <LiquidCrystal.h>

dht DHT;
#define DHT11_PIN 6

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.print("Indoor Temp:");
}

void loop() {
  int chk = DHT.read11(DHT11_PIN);
  lcd.setCursor(0, 1);
  //lcd.print(millis() / 1000);

  //round(temperature*10)/10.0
  lcd.print(round(DHT.temperature*10)/10);
  lcd.print("C");
  Serial.println(DHT.temperature);
  delay(1000);
}
