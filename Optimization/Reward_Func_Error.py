# -*- coding: utf-8 -*-
"""
Created on Wed Jan 15 20:30:40 2020

@author: Safet
"""

import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
import matplotlib.patches as patches
import seaborn as sns
import time
import datetime
import sys

# dataIn = 100
dataOut = np.NaN

def GetReward(dataIn):
    # print("Data in is: " + str(dataIn))
    
    # Find if dataIn negative
    dataIn = np.abs(dataIn)
    
    # Map dataIn to graph
    if 0 <= dataIn and dataIn < 0.5:
        dataOut = np.sqrt((0.5)**2 - dataIn**2) + 0.5
    elif 0.5 <= dataIn and dataIn < 1:
        dataOut = -1 * np.sqrt((0.5)**2 - (dataIn - 1)**2) + 0.5
    elif 1 <= dataIn and dataIn < 1.5:
        dataOut = np.sqrt((0.5)**2 - (dataIn - 1)**2) - 0.5
    elif 1.5 <= dataIn:
        dataOut = -1 * np.arctan((16 * (dataIn - 1.5))) / np.pi - 0.5
    
    # print("Reward is: " + str(dataOut))
    
    return dataOut
    
# if __name__ == "__main__":
#     Reward_Func_Error()