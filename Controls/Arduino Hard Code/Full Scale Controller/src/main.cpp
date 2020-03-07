#include <Arduino.h>
#include <Wire.h>

#define potFeedbackPin A0
#define potInputPin A2
#define motorPosPin 5
#define motorNegPin 6
#define limitSwitchPin 2

const uint32_t loopPeriodMillis = 2; // freq = 1000/num [Hz]

const double Kp = 1;
const double Ki = 0.000000;
const double Kd = 0.000;

int potInput    = 0;
int potFeedback = 0;

int32_t   error       = 0;
int32_t   dError      = 0;
int32_t   lastError   = 0;
int32_t   errorSum    = 0;
uint32_t  lastMillis  = 0;
uint32_t  printMillis = 0;

double effort = 0;

void PID();
void forward(int command);
void backward(int command);
void stop();

void setup() {
  Serial.begin(9600);
  pinMode(potFeedbackPin, INPUT);
  pinMode(motorPosPin, OUTPUT);
  pinMode(motorNegPin, OUTPUT);
  pinMode(limitSwitchPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(limitSwitchPin), stop, LOW);
}

void loop() {
  PID();
}

/*
  Deploy PID controller
*/
void PID() {
  if (millis() - lastMillis > loopPeriodMillis) {
    lastMillis = millis(); // reset time

    potInput = analogRead(potInputPin);
    // potFeedback = analogRead(potFeedbackPin);
    potFeedback = 512;
    error = potInput - potFeedback;

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

    // Serial.print("\tdError: "); Serial.print(dError); 
    // Serial.print("\tError sum: "); Serial.print(errorSum);
    // Serial.print("\tEffort: "); Serial.println(effort);

    if (effort > 0)
      forward(effort);
    else if (effort < 0)
      backward(abs(effort));
    else
      stop();
  }
}

/*
  Move motor forward
  Input: int between 0 and 255
*/
void forward(int command) {
  analogWrite(motorPosPin, command);
  analogWrite(motorNegPin, 0);
}

/*
  Move motor backward
  Input: int between 0 and 255
*/
void backward(int command) {
  analogWrite(motorPosPin, 0);
  analogWrite(motorNegPin, command);
}

/*
  Stop motor
*/
void stop() {
  analogWrite(motorPosPin, 0);
  analogWrite(motorNegPin, 0);
}