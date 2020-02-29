/*
  Objective of program is to control controls prototype motor through an ESC via potentiometer input with feedback

  Sauce: https://github.com/jondolan/tutorials/blob/master/controls/PWMthroughPID/PID.ino 

  Raymond Yu
  28 February 2020
*/

#include <Arduino.h>
#include <Wire.h>

#define inputPotPin A0
#define feedbackPotPin A1
#define motorPosPin 5
#define motorNegPin 6

const uint32_t loopPeriodMillis = 2; // 10ms = 100hz

const double Kp = 1;
const double Ki = 0.00000;
const double Kd = 0.000;

int potInput    = 0;
int potFeedback = 0;
int userInput   = 0;

int32_t   error       = 0;
int32_t   dError      = 0;
int32_t   lastError   = 0;
int32_t   errorSum    = 0;
uint32_t  lastMillis  = 0;
uint32_t  printMillis = 0;

double effort = 0;

void PID();
void motorForward(void);
void motorBackward(void);
void motorStop(void);

void setup() {
  Serial.begin(9600);
  pinMode(inputPotPin, INPUT);
  pinMode(feedbackPotPin, INPUT);
  pinMode(motorPosPin, OUTPUT);
  pinMode(motorNegPin, OUTPUT);
}

void loop() {

  // Serial.print("Enter a number between 0 and 24: ");
  // userInput = Serial.read();
  PID();

}

void PID() {
  // Deploy PID every loop period time (can also use timer interrupt)
  if (millis()- lastMillis > loopPeriodMillis) {
    lastMillis = millis(); // reset time

    // potInput = analogRead(inputPotPin);
    potInput = map(12, 0, 24, 0, 1023);
    potFeedback = analogRead(feedbackPotPin);
    error = potInput - potFeedback;

    // Stop motor if error too small
    // if ((error < 25) && (error > -25)) {
    //   motorStop();
    //   return;
    // }

    dError = error - lastError;
    errorSum += error; // accumulate error
    effort = (Kp * error) + (Ki * errorSum) + (Kd * dError);
    lastError = error; // reset error

    Serial.print("Pot input: "); Serial.print(potInput); 
    Serial.print("\tPot feedback: "); Serial.print(potFeedback); 
    Serial.print("\tError: "); Serial.print(error); 

    Serial.print("\tdError: "); Serial.print(dError); 
    Serial.print("\t Error sum: "); Serial.print(errorSum);
    Serial.print("\t Effort: "); Serial.println(effort);

    if (abs(effort) > 255) {
      effort = 255;
    } 
    analogWrite(inputPotPin, abs(effort));

    if (effort > 0)
      motorForward();
    if (effort < 0)
      motorBackward();
  }
}

void motorForward() {
  digitalWrite(motorPosPin, HIGH);
  digitalWrite(motorNegPin, LOW);
}

void motorBackward() {
  digitalWrite(motorPosPin, LOW);
  digitalWrite(motorNegPin, HIGH);
}

void motorStop() {
  digitalWrite(motorPosPin, LOW);
  digitalWrite(motorNegPin, LOW);
}