#include <Arduino.h>
#include <Wire.h>

#define potPin A0
#define motorPosPin 5
#define motorNegPin 6

int potInput = 0;

void PID();
void forward(int command);
void backward(int command);
void stop();

void setup() {
  Serial.begin(9600);
  pinMode(potPin, INPUT);
  pinMode(motorPosPin, OUTPUT);
  pinMode(motorNegPin, OUTPUT);
}

void loop() {

  potInput = map(analogRead(potPin), 0, 1023, 0, 255);
  Serial.print("Pot input:\t"); Serial.println(potInput);

  analogWrite(motorPosPin, potInput);
  analogWrite(motorNegPin, 0);
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