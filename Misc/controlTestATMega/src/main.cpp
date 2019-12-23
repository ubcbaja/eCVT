/*
  Code to get distances from VL6180X on ATMega328 MCU (on Arduino Uno and Nano)

  Sauce: PlatformIO Adafruit VL6180X library
*/

#include <Arduino.h>
#include <Adafruit_VL6180X.h>
#include <Wire.h>

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
  float lux = vl.readLux(VL6180X_ALS_GAIN_5);
  
  uint8_t range = vl.readRange();
  uint8_t status = vl.readRangeStatus();

  if (status == VL6180X_ERROR_NONE) {
    Serial.print("Range:\t"); Serial.print(range);
    Serial.print("\tLux:\t"); Serial.println(lux);
  }

  // // Some error occurred, print it out!
  
  if  ((status >= VL6180X_ERROR_SYSERR_1) && (status <= VL6180X_ERROR_SYSERR_5)) {
    Serial.println("System error");
  }
  else if (status == VL6180X_ERROR_ECEFAIL) {
    Serial.println("ECE failure");
  }
  else if (status == VL6180X_ERROR_NOCONVERGE) {
    Serial.println("No convergence");
  }
  else if (status == VL6180X_ERROR_RANGEIGNORE) {
    Serial.println("Ignoring range");
  }
  else if (status == VL6180X_ERROR_SNR) {
    Serial.println("Signal/Noise error");
  }
  else if (status == VL6180X_ERROR_RAWUFLOW) {
    Serial.println("Raw reading underflow");
  }
  else if (status == VL6180X_ERROR_RAWOFLOW) {
    Serial.println("Raw reading overflow");
  }
  else if (status == VL6180X_ERROR_RANGEUFLOW) {
    Serial.println("Range reading underflow");
  }
  else if (status == VL6180X_ERROR_RANGEOFLOW) {
    Serial.println("Range reading overflow");
  }
  delay(50);

}