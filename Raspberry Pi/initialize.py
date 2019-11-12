"""
Run this code first to verify that the Pi is capable of communicating with the sensor.
"""

import board
import digitalio
import busio
import adafruit_vl6180x

print("Verifying that CircuitPython modules with VL6180X installed properly...")

# Create digital input
pin = digitalio.DigitalInOut(board.D4)
print("Digital IO ok!")

# Create I2C device
i2c = busio.I2C(board.SCL, board.SDA)
print("I2C ok!")

# Create SPI device
spi = busio.SPI(board.SCLK, board.MOSI, board.MISO)
print("SPI ok!")

# Create VL6180X sensor
try:
    sensor = adafruit_vl6180x.VL6180X(i2c) # link to I2C
    print("VL6180X ok!")
except ValueError:
    print("Sensor not detected! Is an I2C device connected?")