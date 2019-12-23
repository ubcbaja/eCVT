# -*- coding: utf-8 -*-
"""
Created on Fri Dec 20 11:34:02 2019

@author: Safet

Test code to control an Actuonix linear servo based on SEL distance.

Sauces:
    https://projects.raspberrypi.org/en/projects/grandpa-scarer/4
    https://www.instructables.com/id/Servo-Motor-Control-With-Raspberry-Pi/

"""

import RPi.GPIO as GPIO
from time import sleep
import resources
import board
import digitalio
import busio
import adafruit_vl6180x
import numpy as np
import time
import os
import sys

PWMpin = 26
GPIO.setmode(GPIO.BCM) # auto board or BCM pinout config
GPIO.setup(PWMpin, GPIO.OUT) # set pin to be output (for PWM)
p = GPIO.PWM(PWMpin, 50) # 50Hz
p.start(0)

# Configure I2C port
i2c = busio.I2C(board.SCL, board.SDA)

# Create sensor object
try:
    sensor = adafruit_vl6180x.VL6180X(i2c) # link to I2C
except ValueError:
    print("Sensor not detected! Is an I2C device connected?")
    sys.exit() # exit program

while True:
    try:
        range = sensor.range
        lumens = sensor.read_lux(adafruit_vl6180x.ALS_GAIN_20) # default gain_20
        range2 = range - 10

        print("Sensor range: {0}mm\tCommand range: {1}mm".format(range, range2))
        resources.SetPosition(float(range2), PWMpin, p)

    except AttributeError:
        print("Program stopped...")
        break
    except KeyboardInterrupt:
        print("\nKeyboard interrupt detected...")
        break
    except OSError:
        print("\nProgram stopped check wiring...")
        break

print("Program complete")

p.stop()
GPIO.cleanup()