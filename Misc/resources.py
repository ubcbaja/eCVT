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

# Set rotary servo angle between 0 and 90 degrees
def SetAngle(angle, PWMpin, p):
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

# Set linear servo angle between 0 and 20mm
def SetPosition(position, PWMpin, p):
    """
    Enter position command, pin for PWM output, and PWM setting. If command is below 0 command will be 0, if above 20, command will be 20. 
    """
    try:
        if position < 0:
            position = 0
        elif position > 20:
            position = 20
        
        duty = mapVal(position, (20, 0), (4.2, 9.2))
        # print("Duty cycle is: " + str(duty))
        GPIO.output(PWMpin, True)
        p.ChangeDutyCycle(duty)
        sleep(0.5)
        GPIO.output(PWMpin, False)
        p.ChangeDutyCycle(0)
        return True
    except ValueError:
        print("Enter valid value between 0 and 20mm!")

# Function to map number from one range to another using linear scale
def mapVal(val, fromRange, toRange):
    return ((float(val) - fromRange[0]) / (fromRange[1] - fromRange[0])) * (toRange[1] - toRange[0]) + toRange[0]