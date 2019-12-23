/*
  Code to get distances from VL6180X on ATMega328 MCU (on Arduino Uno and Nano)

  Sauce: PlatformIO Adafruit VL6180X library
*/

#include <Arduino.h>
// #include <Adafruit_VL6180X.h>
// #include <Wire.h>
#include "resources.h" // includes Adafruit and Wire libraries

Adafruit_VL6180X vl = Adafruit_VL6180X();

void setup() {
  Serial.begin(115200);
  Serial.println("Adafruit VL6180x initializing!");

  if (! vl.begin()) {
    Serial.println("Failed to find sensor...");
    while (1);
  }
  Serial.println("Sensor found!");
}

void loop() {
  float lux = vl.readLux(VL6180X_ALS_GAIN_20);
  
  uint8_t range = vl.readRange();
  uint8_t status = vl.readRangeStatus();

  if (status == VL6180X_ERROR_NONE) {
    Serial.print("Range:\t"); Serial.print(range);
    Serial.print("\tLux:\t"); Serial.println(lux);
  }

  // Some error occurred, print it out!
  CheckErrors(status);
}