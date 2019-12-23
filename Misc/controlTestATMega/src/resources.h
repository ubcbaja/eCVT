#pragma once

#include <stdint.h>
#include <Adafruit_VL6180X.h>
#include <Wire.h>

void CheckErrors(uint8_t status) {
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
}

