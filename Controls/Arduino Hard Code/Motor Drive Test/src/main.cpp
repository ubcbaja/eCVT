#include <Arduino.h>
#include <Wire.h>

#define potPin A0
#define sigPin 3

int potInput = 0;

void setup() {
  Serial.begin(9600);
  pinMode(potPin, INPUT);
  pinMode(sigPin, OUTPUT);

  TCCR0B = TCCR0B & B11111000 | B00000101; // 60Hz clock
}

void loop() {
  potInput = map(analogRead(potPin), 0, 1023, 0, 255);
  analogWrite(sigPin, potInput);
  Serial.print("Pot output:\t"); Serial.println(potInput);
  delay(10);
}