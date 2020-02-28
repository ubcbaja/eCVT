/*
  Objective of program is to control controls prototype motor through an ESC via potentiometer input with feedback

  Raymond Yu
  28 February 2020
*/

#include <Arduino.h>
#include <Wire.h>

#define inputPotPin A0
#define feedbackPotPin A1
#define motorPos 5
#define motorNeg 6

int potInput = 0;
int potFeedback = 0;
int difference = 0;
int command = 0;

int Kp = 10;
int Ki = 0;
int Kd = 0;

void setup() {
  Serial.begin(9600);
  pinMode(inputPotPin, INPUT);
  pinMode(feedbackPotPin, INPUT);
  pinMode(motorPos, OUTPUT);
  pinMode(motorNeg, OUTPUT);
}

void loop() {
  potInput = analogRead(inputPotPin);
  potFeedback = analogRead(feedbackPotPin);

  difference = potInput - potFeedback;

  Serial.print("Pot input:\t"); Serial.print(potInput); Serial.print("\tPot feedback:\t"); Serial.print(potFeedback); 
  Serial.print("\tError:\t"); Serial.println(difference);

  if (difference > 10) {
    analogWrite(motorPos, map(difference, 0, 1023, 0, 255));
    analogWrite(motorNeg, 0);
  }

  else if (difference < -10) {
    analogWrite(motorPos, 0);
    analogWrite(motorNeg, map((1023 - difference), 0, 1023, 0, 255));
  }

  else {
    analogWrite(motorPos, 0);
    analogWrite(motorNeg, 0);
  }

  delay(10);
}