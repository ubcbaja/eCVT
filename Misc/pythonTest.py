# -*- coding: utf-8 -*-
"""
Created on Tue Nov 12 13:05:06 2019

@author: Safet
"""

import time
from datetime import datetime
import numpy as np

x = list(np.linspace(0, 10, 1001))

#print(x)

xs = list(range(0, 200))

#print(xs)
 
#for i in range(0, 1000):
#    start = time.time()
#    end = time.time()
#    elapsed = (end - start) * 1000000
#    print(elapsed)
#    
#    
#
#a = datetime.now()
## do something ...
#b = datetime.now()
#print (b - a)

start = datetime.now()
end = datetime.now()

print(end - start)