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

PWMpin = 37
GPIO.setmode(GPIO.BOARD)
GPIO.setup(PWMpin, GPIO.OUT)
p = GPIO.PWM(PWMpin, 50) # 50Hz
p.start(0)

while True:
    try:
        print("Enter command input between 0 and 20(mm):\n", end = "\r")
        resources.SetPosition(input(), PWMpin, p)
    except KeyboardInterrupt:
        print("\nStopping program...")
        break

print("Program complete")

p.stop()
GPIO.cleanup()