/*
  Code to get distances from VL6180X on ATMega328 MCU (on Arduino Uno and Nano)

  Sauce: PlatformIO Adafruit VL6180X library
*/

#include <Arduino.h>
// #include <Adafruit_VL6180X.h>
// #include <Wire.h>
#include "resources.h" // includes Adafruit and Wire libraries
#include <servo.h>

Adafruit_VL6180X vl = Adafruit_VL6180X();
int PWMPin = 3;
Servo linearServo; // create servo instance
unsigned long command = 0;
unsigned long start, finish, elapsed;
// unsigned long previousTime = 0;
// unsigned long timeInterval = 20000; // 20000 micros

void setup() {
  Serial.begin(115200);
  Serial.println("Adafruit VL6180x and servo initializing!");

  if (! vl.begin()) {
    Serial.println("Failed to find sensor...");
    while (1);
  }
  Serial.println("Sensor found!");

  linearServo.attach(PWMPin);
  Serial.println("Servo attached!");
}

void loop() {
  start = micros(); // time in microseconds
  float lux = vl.readLux(VL6180X_ALS_GAIN_20);
  
  uint8_t range = vl.readRange();
  uint8_t status = vl.readRangeStatus();

  if (status == VL6180X_ERROR_NONE) {
    if (range < 0)
      range = 0;
    else if (range > 20)
      range = 20;

  command = map(range, 0, 20, 0, 180);
  linearServo.write(command);

  finish = micros();
  elapsed = finish - start;

  Serial.print("Time: "); Serial.print(elapsed); Serial.print("\tRange: "); Serial.print(range); Serial.print("\tCommand: "); Serial.println(command);
  
  // Serial.print("Range:\t"); Serial.println(range);
  // Serial.print("\tLux:\t"); Serial.println(lux);
  }

  // Some error occurred, print it out!
  CheckErrors(status);
}