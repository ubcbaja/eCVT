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

PWMpin = 37
GPIO.setmode(GPIO.BOARD)
GPIO.setup(PWMpin, GPIO.OUT)
p = GPIO.PWM(PWMpin, 50) # 50Hz
p.start(0)

# Set rotary servo angle between 0 and 90 degrees
def SetAngle(angle):
    if angle < 0 or angle > 90:
        return False
    else:
        duty = angle / 18 + 2
        GPIO.output(PWMpin, True)
        p.ChangeDutyCycle(duty)
        sleep(1)
        GPIO.output(PWMpin, False)
        p.ChangeDutyCycle(0)
        return True

# Set ilnear servo angle between 0 and 20mm
def SetPosition(position):
    if position < 0 or position > 20:
        return False
    else:
        duty = (float(position) + 4) / 3
        duty = map(position, (0, 20), (130, 30))

        # test first with just values, no PWM

        print("Duty cycle is: " + duty)
        GPIO.output(PWMpin, True)
        p.ChangeDutyCycle(duty)
        sleep(1)
        GPIO.output(PWMpin, False)
        p.ChangeDutyCycle(0)
        return True

# Function to map number from one range to another using linear scale
def map(val, fromRange, toRange):
    return ((val - fromRange[0]) / (fromRange[1] - fromRange[0])) * (toRange[1] - toRange[0]) + toRange[0]

while True:
    try:
        print("Enter angle input:\n", end = "\r")
        angleInput = int(input())
        SetAngle(angleInput)
    except KeyboardInterrupt:
        print("\nStopping program")
        break

# Linear servo angle input range: 30 (fully extended) to 130 (fully retracted)
# Create new function for "set distance"

# print("Duty cycle 1")
# p.ChangeDutyCycle(1)
# sleep(1)
# print("Duty cycle 2")
# p.ChangeDutyCycle(20)
# sleep(1)

print("Done")

p.stop()
GPIO.cleanup()