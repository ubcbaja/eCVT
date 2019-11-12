# -*- coding: utf-8 -*-
"""
Created on Mon Nov  4 16:23:27 2019

Resource links:
    https://learn.adafruit.com/adafruit-vl6180x-time-of-flight-micro-lidar-distance-sensor-breakout/overview
    https://circuitpython.readthedocs.io/en/4.x/shared-bindings/busio/__init__.html

@author: Raymond
"""

import board
import digitalio
import busio
import adafruit_vl6180x
import time
import os
import sys
import datetime

# Configure I2C port
i2c = busio.I2C(board.SCL, board.SDA)

# Create sensor object
try:
    sensor = adafruit_vl6180x.VL6180X(i2c) # link to I2C
except ValueError:
    print("Sensor not detected! Is an I2C device connected?")

try:
    while True:
        range = sensor.range
        lums = sensor.read_lux(adafruit_vl6180x.ALS_GAIN_1)
        print("Range: {0}mm\t Light: {0}lux".format(range, lums), end = "\r")
        time.sleep(0.05)
except KeyboardInterrupt:
    print("\nKeyboard interrupt detected, stopping readings...")

print("This is the line after")