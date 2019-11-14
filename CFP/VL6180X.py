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
from datetime import datetime
import matplotlib.pyplot as plt
import matplotlib.animation as animation

# Configure I2C port
i2c = busio.I2C(board.SCL, board.SDA)

# Create sensor object
try:
    sensor = adafruit_vl6180x.VL6180X(i2c) # link to I2C
except ValueError:
    print("Sensor not detected! Is an I2C device connected?")
    sys.exit() # exit program

# Set up variables for plotting
timeSpan = 5 # time span for plotting, relative b/c not RTOS
xLen = 101 # 101 datapoints per plot
yRange = [0, 150] # Y range from 0 to 100mm

# Set up plot graph
fig = plt.figure()
ax = fig.add_subplot(1, 1, 1)
ax.set_ylim(yRange)
xs = list(np.linspace(0, timeSpan, xLen)) # x data (time)
ys = [0] * xLen # y data (distance)
line, = ax.plot(xs, ys) # unpack tuple to take first element only
plt.title("VL6180X Distance vs Time")
plt.xlabel("Time (relative)")
plt.ylabel("Distance (mm)")
plt.yticks(np.arange(0, 150, step = 10)) # doesn't work need fix

# Prepare CSV for datalogging
currentDT = datetime.now()
file = open("DistanceTest_" + currentDT.strftime("%Y_%m_%d_%H_%M_%S") + ".txt", "w")
file.write("Time (s)" + "\t" + "Range (mm)" + "\t" + "Lumens (0dB)")

# Main try/except while loop for animations and data updating
startTime = time.time()
while True: 
    try:
        def animate(i, ys):
            range = sensor.range
            lumens = sensor.read_lux(adafruit_vl6180x.ALS_GAIN_20) # default gain_5 suggestion
            print("Range: {0}mm\t Light: {0}lux".format(range, lumens), end = '\r') # '\r' line ending to dynamically write on one line

            # Write to file
            endTime = time.time()
            elapsed = endTime - startTime
            file.write("\n" + "{0:.2f}".format(elapsed) + "\t\t" + str(range) + "\t\t" + "{0:.2f}".format(lumens))

            ys.append(range) # add to plot
            ys = ys[-xLen:] # limit y data
            line.set_ydata(ys)
            
            return line,

        # Use blit to speed things up
        animashun = animation.FuncAnimation(fig, animate, fargs = (ys,), interval = 50, blit = True)
        plt.grid()
        plt.show()

        # Data readouts and datalogging only
        # range = sensor.range
        # lumens = sensor.read_lux(adafruit_vl6180x.ALS_GAIN_5) # default gain_5 suggestion
        # print("Range: {0}mm\t Light: {0}lux".format(range, lumens), end = '\r') # '\r' line ending to dynamically write on one line
        # endTime = time.time()
        # elapsed = endTime - startTime
        # file.write("\n" + "{0:.2f}".format(elapsed) + "\t\t" + str(range) + "\t\t" + "{0:.2f}".format(lumens))


    except AttributeError:
        print("Program stopped due to unknown reason...")
        break
    except KeyboardInterrupt:
        print("\nKeyboard interrupt detected...")
        break
    

file.close()
print("Program exitted...")