import serial
import matplotlib.pyplot as pyplot
from mpl_toolkits.mplot3d import Axes3D
import math

ser = serial.Serial('/dev/ttyACM0', 9600)

# height and length in order to do mathematical calculations to convert the distance readings into Cartesian
h = 1
l = 1

#thresholds to remove noise
maxdis = 50
mindis = 20

x = []
y = []
z = []

# creating the plot and defining it as 3D
fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')

#interactive plotting, show the plot
plt.ion()
plt.show()

#setting labels for the plots
ax.set_xlabel('X axis')
ax.set_ylabel('Y axis')
ax.set_zlabel('Z axis')

while 1:

    #parsing Arduino data
    data = ser.readline()
    dataArray = data.split().strip()

    # convert to floats (for precision) and radians
	theta = ((float(dis[0]))*pi)/180.0
	phi = ((float(dis[1]))*pi)/180.0
    # converted to actual distances with calibration
    r = float(dis[2])  *math.e(4) #put in calibration

    #converting everything into Cartesian
    b = l - r*cos(theta)
    xpt = b * cos(phi)
    ypt = b * sin(phi)
    zpt - h - r*sin(theta)

    if r > mindis and r < maxdis:

        #adds to matrices
		x.append(xpt)
		y.append(ypt)
		z.append(zpt)

        #liveplots data
		ax.scatter(x, y, z)	#plot point
		plt.draw()

#creats permenant plot
plt.ioff()

ax.set_xlabel('X axis') #create axes labels
ax.set_ylabel('Y axis')
ax.set_zlabel('Z axis')
ax.scatter(X, Y, Z)	#plot points
plt.show()
