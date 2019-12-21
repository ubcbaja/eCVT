# -*- coding: utf-8 -*-
"""
Created on Fri Dec 20 11:34:02 2019

@author: Safet

Test code to control servo based on SEL distance.

Sauce:
    https://projects.raspberrypi.org/en/projects/grandpa-scarer/4

"""

import RPi.GPIO as GPIO
from time import sleep

PWMpin = 37
GPIO.setmode(GPIO.BOARD)
GPIO.setup(PWMpin, GPIO.OUT)
p = GPIO.PWM(PWMpin, 50) # 50Hz
p.start(0)

def SetAngle(angle):
    duty = angle / 18 + 2
    GPIO.output(PWMpin, True)
    p.ChangeDutyCycle(duty)
    sleep(1)
    GPIO.output(PWMpin, False)
    p.ChangeDutyCycle(0)

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