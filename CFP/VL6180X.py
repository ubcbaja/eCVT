# -*- coding: utf-8 -*-
"""
Created on Mon Nov  4 16:23:27 2019

Main resource links:
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
import pandas as pd

# Configure I2C port
i2c = busio.I2C(board.SCL, board.SDA)

# Create sensor object
try:
    sensor = adafruit_vl6180x.VL6180X(i2c) # link to I2C
except ValueError:
    print("Sensor not detected! Is an I2C device connected?")
    sys.exit() # exit program

# Init array for data to write
dataArr = []

# Set up variables for plotting
timeSpan = 5 # time span for plotting, relative b/c not RTOS
xLen = 101 # 101 datapoints per plot
yRange = [0, 40] # Y range from 0 to 30mm

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
plt.yticks(np.arange(0, 40, step = 2))

# Main try/except while loop for animations and data updating
startTime = time.time()
while True:
    try:
        def animate(i, ys):
            range = sensor.range
            lumens = sensor.read_lux(adafruit_vl6180x.ALS_GAIN_20) # default gain_20
            print("Range: {0}mm\t Light: {1:.2f}lux".format(range, lumens), end = '\r') # '\r' line ending to dynamically write on one line

            # Write to array then to file
            endTime = time.time()
            elapsed = round((endTime - startTime), 3)
            dataArr.append([elapsed, range, lumens])

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
        print("Program stopped...")
        break
    except KeyboardInterrupt:
        print("\nKeyboard interrupt detected...")
        break
    except OSError:
        print("\nProgram stopped check wiring...")
        break

# Wrangle data into dataframe (for row titles)
dataArr = np.asarray(dataArr)
dfData = pd.DataFrame({'Time (s)': dataArr[:, 0], 'Range (mm)': dataArr[:, 1], 'Lumens (0dB)': dataArr[:, 2]}, columns = ['Time (s)', 'Range (mm)', 'Lumens (0dB)'])

# Save CSV for datalogging
currentDT = datetime.now()
fileName = "DistanceTest_" + currentDT.strftime("%Y_%m_%d_%H_%M_%S") + ".csv"
dfData.to_csv(fileName, index = False, header = True)

print("Program exitted...")
