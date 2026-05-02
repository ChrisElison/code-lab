/*
 * sketch_jan21a.ino
 * Date: 2017-01-21
 * 
 * Ultrasonic sensor (HC-SR04) distance test
 * 
 * Sound alarm and light LED closer you get to sensor
 *
 * Copyright (c) 2026 Christopher Elison <chriselison.uk>
 * Licensed under the MIT License.
 */

const int trigPin  = 13;
const int echoPin  = 12;
const int ledRPin  = 7;
const int ledYPin  = 6;
const int ledGPin  = 5;
const int ledBPin  = 4;
const int alarmPin = 8;

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledRPin, OUTPUT);
  pinMode(ledYPin, OUTPUT);
  pinMode(ledGPin, OUTPUT);
  pinMode(ledBPin, OUTPUT);
  pinMode(alarmPin, LOW);
}

void loop() {
  long duration, distance;

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2)/29.1;

  // Red LED ON
  if (distance <= 10) {
    Serial.println("STOP! YOU'VE VIOLATED THE LAW!!!");
    
    digitalWrite(ledRPin, HIGH);
    digitalWrite(ledYPin, LOW);
    digitalWrite(ledGPin, LOW);
    digitalWrite(ledBPin, LOW);

    soundAlarm(1);
  }

  // Yellow LED ON
  if (distance >= 11 && distance <= 21 ) {
    digitalWrite(ledRPin, LOW);
    digitalWrite(ledYPin, HIGH);
    digitalWrite(ledGPin, LOW);
    digitalWrite(ledBPin, LOW);

    soundAlarm(2);
  }

  // Green LED ON
  if (distance >= 22 && distance <= 32 ) {
    digitalWrite(ledRPin, LOW);
    digitalWrite(ledYPin, LOW);
    digitalWrite(ledGPin, HIGH);
    digitalWrite(ledBPin, LOW);
  }

  // Blue LED ON
  if (distance >= 33 && distance <= 53 ) {
    digitalWrite(ledRPin, LOW);
    digitalWrite(ledYPin, LOW);
    digitalWrite(ledGPin, LOW);
    digitalWrite(ledBPin, HIGH);
  }

  // Calm mode - All LEDS off
  if (distance >= 54 && distance <= 199) {
    digitalWrite(ledRPin, LOW);
    digitalWrite(ledYPin, LOW);
    digitalWrite(ledGPin, LOW);
    digitalWrite(ledBPin, LOW);
  }

  if (distance >= 200 || distance <= 0) {
    Serial.println("Out of Range!");
  } else {
    Serial.print(distance);
    Serial.println(" cm");
  }
  
  delay(500);
}

void soundAlarm(int type) {
  switch(type) {
    case 1:
      tone(alarmPin, 100, 500);
      delay(10);
      tone(alarmPin, 900, 1500);
      break;

    case 2:
      tone(alarmPin, 800, 100);
      delay(100);
      tone(alarmPin, 300, 100);
      delay(100);
      break;
  }
}
