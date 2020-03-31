/*
  Objective of program is to control controls prototype motor through an ESC via potentiometer input

  Raymond Yu
  26 February 2020
*/

#include <Arduino.h>
#include <Wire.h>

/* PWM ESC*/
#define inputPotPin A0
#define motorPos 5
#define motorNeg 6

int potInput = 0;
int difference = 0;

void setup() {
  Serial.begin(9600);
  pinMode(inputPotPin, INPUT);
  pinMode(motorPos, OUTPUT);
  pinMode(motorNeg, OUTPUT);
}

void loop() {
  potInput = analogRead(inputPotPin);

  Serial.print("Pot input: "); Serial.println(potInput);

  if (potInput >= 524) {
    analogWrite(motorPos, map(potInput, 0, 1023, 0, 255));
    analogWrite(motorNeg, 0);
  }

  else if (potInput < 500) {
    analogWrite(motorPos, 0);
    analogWrite(motorNeg, map((1023-potInput), 0, 1023, 0, 255));
  }

  else {
    analogWrite(motorPos, 0);
    analogWrite(motorNeg, 0);
  }

  delay(10);
}

/* RC ESC */
// #define inputPotPin A0
// #define sigPin 5

// int potInput = 0;

// void setup() {
//   Serial.begin(9600);
//   pinMode(inputPotPin, INPUT);
//   pinMode(sigPin, OUTPUT);

//   TCCR0B = TCCR0B & B11111000 | B00000101; // 60Hz clock for ~20ms (16ms) period for RC control
// }

// void loop() {
//   potInput = map(analogRead(inputPotPin), 0, 1023, 16, 32); // 16 is 1ms duty cycle, 32 is 2ms duty cycle
//   analogWrite(sigPin, potInput);
//   Serial.print("Pot output:\t"); Serial.println(potInput);
//   delay(10);
// }
