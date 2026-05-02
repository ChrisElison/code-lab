/*
 * sketch_jan12a.ino
 * Date: 2017-01-12
 * 
 * Prints temperature & humidity to serial monitor
 *
 * Copyright (c) 2026 Christopher Elison <chriselison.uk>
 * Licensed under the MIT License.
 */

#include <dht.h>

dht DHT;

#define DHT11_PIN 7

void setup() {
  Serial.begin(9600);
}

void loop() {
  int chk = DHT.read11(DHT11_PIN);
  Serial.print("Temp: ");
  Serial.print(DHT.temperature);
  Serial.print((char)176);
  Serial.print(" | Humidity: ");
  Serial.print(DHT.humidity);
  Serial.println("");
  delay(5000);
}
