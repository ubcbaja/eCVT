/*
  Objective of program is to control controls prototype motor through an ESC via potentiometer input with feedback

  Sauce: https://github.com/jondolan/tutorials/blob/master/controls/PWMthroughPID/PID.ino 

  Raymond Yu
  28 February 2020
*/

#include <Arduino.h>
#include <Wire.h>

#define motorInputPin 3
#define feedbackPotPin A1
#define motorPosPin 5
#define motorNegPin 6

const uint32_t loopPeriodMillis = 10; // 10ms = 100hz

const double Kp = 5;
const double Ki = 0.0000001;
const double Kd = 0.0001;

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

void PID(int target);
void motorForward();
void motorBackward();
void motorStop();

void setup() {
  Serial.begin(9600);
  pinMode(motorInputPin, OUTPUT);
  pinMode(feedbackPotPin, INPUT);
  pinMode(motorPosPin, OUTPUT);
  pinMode(motorNegPin, OUTPUT);
}

void loop() {

  PID(5); // target between 0 and 24

}

void PID(int target) {
  // Deploy PID every loop period time (can also use timer interrupt)
  if (millis()- lastMillis > loopPeriodMillis) {
    lastMillis = millis(); // reset time

    /* ENTER INPUT IN FIRST VALUE OF MAP */
    // potInput = analogRead(motorInputPin);
    potInput = map(target, 0, 24, 150, 1023);
    potFeedback = analogRead(feedbackPotPin);
    error = potInput - potFeedback;

    // Stop motor if error too small
    // if ((error < 10) && (error > -10)) {
    //   motorStop();
    //   return;
    // }

    dError = error - lastError;
    errorSum += error; // accumulate error
    effort = (Kp * error) + (Ki * errorSum) + (Kd * dError);
    lastError = error; // reset error

    // Serial.print("Pot input: "); Serial.print(potInput); 
    // Serial.print("\tPot feedback: "); Serial.print(potFeedback); 
    // Serial.print("\tError: "); Serial.print(error); 

    if (effort > 255) {
      effort = 255;
    } else if (effort < -255) {
      effort = -255;
    }
    analogWrite(motorInputPin, abs(effort));

    // Serial.print("\tdError: "); Serial.print(dError); 
    // Serial.print("\tError sum: "); Serial.print(errorSum);
    // Serial.print("\tEffort: "); Serial.println(effort);

    if (effort > 0)
      motorForward();
    else if (effort < 0)
      motorBackward();
    else
      motorStop();
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