/*
  Objective of program is to control controls prototype motor through an ESC via potentiometer input with feedback

  Raymond Yu
  28 February 2020
*/

#include <Arduino.h>
#include <Wire.h>
#include <PID_v1.h>

#define inputPotPin A0
#define feedbackPotPin A1
#define motorPos 5
#define motorNeg 6

int potInput = 0;
int potFeedback = 0;
int error = 0;
int effort = 0;

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

  error = potInput - potFeedback;
  effort = error * Kp;

  Serial.print("Pot input: "); Serial.print(potInput); Serial.print("\tPot feedback: "); Serial.print(potFeedback); 
  Serial.print("\tError: "); Serial.print(error);  

  if (error > 10) {
    analogWrite(motorPos, map(effort, 0, 1023*Kp, 0, 255));
    analogWrite(motorNeg, 0);
    Serial.print("\tCommand pos: "); Serial.println(map(effort, 0, 1023*Kp, 0, 255));
  }

  else if (error < -10) {
    effort = -1 * effort;
    analogWrite(motorPos, 0);
    analogWrite(motorNeg, map(effort, 0, 1023*Kp, 0, 255));
    Serial.print("\tCommand neg: "); Serial.println(map(effort, 0, 1023*Kp, 0, 255));
  }

  else {
    analogWrite(motorPos, 0);
    analogWrite(motorNeg, 0);
    Serial.print("\tCommand: "); Serial.println("0");
  }

  delay(10);
}