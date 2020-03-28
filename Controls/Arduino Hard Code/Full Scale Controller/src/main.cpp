// Include libraries
#include <Arduino.h>
#include <Wire.h>

// Initialize constant variables
#define potFeedbackPin A0
#define potInputPin A2
#define motorPosPin 5
#define motorNegPin 6
#define limitSwitchPin 2

// Initialize constant variables
const uint32_t loopPeriodMillis = 2; // freq = 1000/num [Hz]
const double Kp = 1;
const double Ki = 0.000000;
const double Kd = 0.000;

// Initialize variables
int potInput    = 0;
int potFeedback = 512;
double effort = 0;

int32_t   error       = 0;
int32_t   dError      = 0;
int32_t   lastError   = 0;
int32_t   errorSum    = 0;
uint32_t  lastMillis  = 0;
uint32_t  printMillis = 0;

// Initialize function prototypes
void PID();
void forward(int command);
void backward(int command);
void stop();
void estop(); // emergency stop

void setup() {
  // Serial.begin(9600);
  pinMode(potFeedbackPin, INPUT);                                     // set feedback pin as input
  pinMode(motorPosPin, OUTPUT);                                       // set PWM amplifier + pin as output
  pinMode(motorNegPin, OUTPUT);                                       // set PWM amplifier - pin as output 
  pinMode(limitSwitchPin, INPUT_PULLUP);                              // set limit switch as input with pullup
  attachInterrupt(digitalPinToInterrupt(limitSwitchPin), estop, LOW); // set interrupt pin for triggering at logic low
}

void loop() {
  PID();                                                              // call PID control loop continuously
}

/*
  Deploy PID controller
*/
void PID() {
  if (millis() - lastMillis > loopPeriodMillis) {                     // run loop at desired frequency (system bandwidth)
    lastMillis = millis();                                            // reset time for next loop

    potInput = analogRead(potInputPin);                               // read manual potentiometer input for demonstration
    // potFeedback = analogRead(potFeedbackPin);                      // read potentiometer feedback pin for operation
    error = potInput - potFeedback;                                   // calculate error from setpoint

    dError = error - lastError;                                       // get difference in error (derivative)
    errorSum += error;                                                // accumulate error (integral)
    effort = (Kp * error) + (Ki * errorSum) + (Kd * dError);          // get control effort for PWM amplifier
    lastError = error;                                                // reset error

    // Serial.print("Pot input: "); Serial.print(potInput); 
    // Serial.print("\tPot feedback: "); Serial.print(potFeedback); 
    // Serial.print("\tError: "); Serial.print(error); 

    if (effort > 255) {                                               // positive saturation of maximum PWM duty cycle
      effort = 255;
    } else if (effort < -255) {                                       // negative saturation of minimum PWM duty cycle
      effort = -255;
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
  Stop motor & return to new command
*/
void stop() {
  analogWrite(motorPosPin, 0);
  analogWrite(motorNegPin, 0);
}

/*
  Stop motor & reset command input (emergency)
*/
void estop() {
  analogWrite(motorPosPin, 0);
  analogWrite(motorNegPin, 0);
  potFeedback = potInput;
}

