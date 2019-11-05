# -*- coding: utf-8 -*-
"""
Created on Mon Nov  4 15:59:56 2019

@author: Safet

Purpose: Create timer and threads to determine resopnse for CFP

Links: 
    https://www.youtube.com/watch?v=2ZwuKeL0aHs 
    https://realpython.com/intro-to-python-threading/

"""

import logging
import threading
import time

def sleeper (n, name):
    print ('Helloo this is %s\n', name)
    time.sleep(n)