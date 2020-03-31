// Include libraries
#include <Arduino.h>
#include <Wire.h>

// Initialize constant variables
#define potFeedbackPin A0
#define potInputPin A2
#define motorPosPin 5
#define motorNegPin 6
#define limitSwitchMaxPin 3
#define limitSwitchMinPin 2
#define MAX_PWM 255
#define MAX_TRAVEL 25

// Initialize controller bandwidth and gain
const uint32_t loopPeriodMillis = 2; // freq = 1000/num [Hz]
const double Kp = 1;
const double Ki = 0.000000;
const double Kd = 0.000;

// Initialize other variables
const int lowResistance   = 150;    // calibrate linear pot lower resistance
const int highResistance  = 1023;   // calibrate linear pot upper resistance
int potInput              = 0;
int potFeedback           = 0;
double effort             = 0;

int32_t   error       = 0;
int32_t   dError      = 0;
int32_t   lastError   = 0;
int32_t   errorSum    = 0;
uint32_t  lastMillis  = 0;
uint32_t  printMillis = 0;

// Initialize function prototypes
void PID(int target, bool demo);
void forward(int command);
void backward(int command);
void stop();
void eStopMax(); // stop if reached max and return other way
void eStopMin(); // stop if reached min and return other way

void setup() {
  // Serial.begin(9600);
  pinMode(potFeedbackPin, INPUT);                                             // set feedback pin as input
  pinMode(motorPosPin, OUTPUT);                                               // set PWM amplifier + pin as output
  pinMode(motorNegPin, OUTPUT);                                               // set PWM amplifier - pin as output 
  pinMode(limitSwitchMaxPin, INPUT_PULLUP);                                   // set limit switch as input with pullup
  pinMode(limitSwitchMinPin, INPUT_PULLUP);                                   // set limit switch as input with pullup
  attachInterrupt(digitalPinToInterrupt(limitSwitchMaxPin), eStopMax, LOW);   // set max limit pin for interrupt
  attachInterrupt(digitalPinToInterrupt(limitSwitchMinPin), eStopMin, LOW);   // set min limit pin for interrupt
}

void loop() {
  PID(10, false);                                                              // set target position of 10mm
}

/*
  Deploy PID controller
  Target: desired sheave displacement (0 - 25mm)
  Demo: demonstration mode with user input variable pot ()
*/
void PID(int target, bool demo) {
  if (millis() - lastMillis > loopPeriodMillis) {                     // run loop at desired frequency (system bandwidth)
    lastMillis = millis();                                            // reset time for next loop

    if (demo)
      potInput = analogRead(potInputPin);                             // read manual potentiometer input for demonstration
    else
      potInput = map(target, 0, MAX_TRAVEL, lowResistance, highResistance);   // 
    
    potFeedback = analogRead(potFeedbackPin);                         // read potentiometer feedback pin for operation
    error = potInput - potFeedback;                                   // calculate error from setpoint

    dError = error - lastError;                                       // get difference in error (derivative)
    errorSum += error;                                                // accumulate error (integral)
    effort = (Kp * error) + (Ki * errorSum) + (Kd * dError);          // get control effort for PWM amplifier
    lastError = error;                                                // reset error

    // Serial.print("Pot input: "); Serial.print(potInput); 
    // Serial.print("\tPot feedback: "); Serial.print(potFeedback); 
    // Serial.print("\tError: "); Serial.print(error); 

    if (effort > MAX_PWM) {                                               // positive saturation of maximum PWM duty cycle
      effort = MAX_PWM;
    } else if (effort < -MAX_PWM) {                                       // negative saturation of minimum PWM duty cycle
      effort = -MAX_PWM;
    }

    // Serial.print("\tdError: "); Serial.print(dError); 
    // Serial.print("\tError sum: "); Serial.print(errorSum);
    // Serial.print("\tEffort: "); Serial.println(effort);

    if (effort > 0)                                                   // forward actuation command
      forward(effort);
    else if (effort < 0)                                              // reverse actuation command
      backward(abs(effort));
    else                                                              // no actuation command
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

/*
  Stop motor at maximum & actuate other way
*/
void eStopMax() {
  analogWrite(motorPosPin, 0);
  analogWrite(motorNegPin, MAX_PWM);
}

/*
  Stop motor at minimum & actuate other way
*/
void eStopMin() {
  analogWrite(motorPosPin, MAX_PWM);
  analogWrite(motorNegPin, 0);
}