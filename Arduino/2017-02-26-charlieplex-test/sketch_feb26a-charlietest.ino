/*
 * sketch_feb26a-charlietest.ino
 * Date: 2017-02-26
 * 
 * Charlieplexing test
 * 
 * Trying to understand 'Charlieplexing' at 4:00 AM
 *
 * Copyright (c) 2026 Christopher Elison <chriselison.uk>
 * Licensed under the MIT License.
 */

int A = 2;
int B = 3;
int C = 4;

int delayVar = 1000;

void setup() {
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
}

void loop() {
  pinMode(A, OUTPUT);
  pinMode(B, INPUT);  // changed to input to trigger tri state.
  pinMode(C, OUTPUT);
  
  digitalWrite(A, HIGH);
  digitalWrite(C, LOW);
  delay(delayVar);

  pinMode(A, OUTPUT);
  pinMode(B, INPUT);  // changed to input to trigger tri state.
  pinMode(C, OUTPUT);
  
  digitalWrite(A, LOW);
  digitalWrite(C, HIGH);
  delay(delayVar);

  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, INPUT);
  
  digitalWrite(A, HIGH);
  digitalWrite(B, LOW);
  delay(delayVar);

  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, INPUT);
  
  digitalWrite(A, LOW);
  digitalWrite(B, HIGH);
  delay(delayVar);

  pinMode(A, INPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  
  digitalWrite(B, HIGH);
  digitalWrite(C, LOW);
  delay(delayVar);

  pinMode(A, INPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  
  digitalWrite(B, LOW);
  digitalWrite(C, HIGH);
  delay(delayVar);

  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, INPUT);
  
  digitalWrite(A, HIGH);
  digitalWrite(B, LOW);
  delay(delayVar);
}
