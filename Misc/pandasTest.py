# -*- coding: utf-8 -*-
"""
Created on Tue Nov  5 15:34:15 2019

@author: Safet
"""

import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import seaborn as sns
import time
import datetime
import sys

sns.set_style("whitegrid")

data = np.zeros((10, 3))

df = pd.DataFrame(data, columns = ['Time', 'Distance', 'Force'])

print(df)