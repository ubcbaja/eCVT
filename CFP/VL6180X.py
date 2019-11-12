# -*- coding: utf-8 -*-
"""
Created on Mon Nov  4 16:23:27 2019

Resource links:
    https://learn.adafruit.com/adafruit-vl6180x-time-of-flight-micro-lidar-distance-sensor-breakout/overview
    https://circuitpython.readthedocs.io/en/4.x/shared-bindings/busio/__init__.html
    https://learn.sparkfun.com/tutorials/graph-sensor-data-with-python-and-matplotlib/speeding-up-the-plot-animation
@author: Raymond
"""

import board
import digitalio
import busio
import adafruit_vl6180x
import numpy as np
import time
import os
import sys
import datetime
import matplotlib.pyplot as plt
import matplotlib.animation as animation

# Configure I2C port
i2c = busio.I2C(board.SCL, board.SDA)

# Create sensor object
try:
    sensor = adafruit_vl6180x.VL6180X(i2c) # link to I2C
except ValueError:
    print("Sensor not detected! Is an I2C device connected?")

# Set up variables for plotting
DAQRate = 10
xLen = 101 # 101 datapoints per plot
yRange = [0, 100] # Y range from 0 to 100mm

# Set up plot graph
fig = plt.figure()
ax = fig.add_subplot(1, 1, 1)
xs = list(np.linspace(0, DAQRate, xLen)) # x data (time)
ys = [0] * xLen # y data (distance)

line, = ax.plot(xs, ys) # unpack tuple to take first element only

def animate(i, ys):
    range = sensor.range
    
    ys.append(range) # add to plot
    ys = ys[-xLen:] # limit y data
    
    line.set_ydata(ys)
    
    return line

animashun = animation.FuncAnimation(fig, animate, fargs = (ys,), interval = 50, blit = True)
plt.show()

"""
try:
    while True:
        range = sensor.range
        lums = sensor.read_lux(adafruit_vl6180x.ALS_GAIN_1)
        print("Range: {0}mm\t Light: {0}lux".format(range, lums), end = "\r")
        
        time.sleep(1/DAQRate) # 10 Hz DAQ rate
except KeyboardInterrupt:
    print("\nKeyboard interrupt detected, stopping readings...")
"""