# -*- coding: utf-8 -*-
"""
Created on Wed Jan 15 21:30:23 2020

@author: Safet
"""

import Reward_Func_Error as ErrorReward

import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
import matplotlib.patches as patches
import seaborn as sns
import time
import datetime
import sys

sns.set_style("whitegrid")
sns.set_palette("muted")

x = np.linspace(0, 3, 100)
y = np.zeros(len(x))

for i, val in enumerate(x):
    y[i] = ErrorReward.GetReward(val)

#%%

ax = sns.scatterplot(x, y, hue = y, legend = None)
ax.set_title("Error Reward Function")
ax.set_xlabel("Raw value")
ax.set_ylabel("Reward")

