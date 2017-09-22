"""
Display analog data from Arduino in real-time
"""

#various needed to import

import pyserial
import numpy as np
from time import sleep
import matplotlib.pyplot as plt

data = []
ser = serial.Serial('com30',9600)

def plotPoints():
    plt.title('Please work please')
    plt.grid(True)
    
    plt.plot(data,'bo-', label='plez')

while True:
    while (ser.inWaiting()==0):
        pass
    datard=ser.readLine()
    dataarray=datard.split(',')
    dataplot = float(dataarray[0]);
    data.append(dataplot)
    drawnow(plotPoints)
    plt.pause(0.000001)
    count=count+1
    if(cnt>50):
        data.pop(0)
