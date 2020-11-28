import matplotlib.pyplot as plt
import matplotlib.animation as animation
from matplotlib import style
import random
import serial 
import time
import struct

ser = ""
x = 0
readIn = '' 
xs1 = []
ys1 = []
xs2 = []
ys2 = []
style.use('fivethirtyeight')
fig1 = plt.figure()
ax1 = fig1.add_subplot(1,1,1)
fig2 = plt.figure()
ax2 = fig2.add_subplot(1,1,1)


def handle_close(evt):
    global ser
    
    ser.write(b"\x16\x62" + b"\x00"*31)
    print('Closed Figure!')
    ser.close()

def animate1(i): #currently set to use randomly generated values for testing purposes
    global xs1
    global ys1
    global x
    global ser
    global readIn
    xs1.append(x)
    x = x + 1
    
    readIn =  ser.read(31)#random.randint(0,50)
    print(readIn)
 
    y = struct.unpack("d", readIn[0:4])

    print(x,",",y)
    ys1.append(y)
    ax1.clear()
    ax1.plot(xs1, ys1)

def animate2(i): #currently set to use randomly generated values for testing purposes
    global xs2
    global ys2
    global x
    global ser
    global readIn

    xs2.append(x)
    #x = x + 1
    #y = ser.read(31)#random.randint(0,50)
    
    y = struct.unpack("d", readIn[4:8])

    print(x,",",y)
    ys2.append(y)
    ax2.clear()
    ax2.plot(xs2, ys2)
    
def plot():
    global x
    global fig1
    global fig2
    global ax1
    global ax2
    global ser
    ser = serial.Serial("COM3", 115200)
    time.sleep(2)
    ser.write(b"\x16\x47" + b"\x00"*31)

    if(x > 0):
        fig1 = plt.figure()
        ax1 = fig1.add_subplot(1,1,1)
        fig2 = plt.figure()
        ax2 = fig2.add_subplot(1,1,1)

    x = 0
    xs = []
    ys = []
    style.use('fivethirtyeight')

    #Detect windows close
    fig1.canvas.mpl_connect('close_event', handle_close)
    #fig2.canvas.mpl_connect('close_event', handle_close)
    
    #Animate Plots
    ani1 = animation.FuncAnimation(fig1, animate1, interval=500)
    ani2 = animation.FuncAnimation(fig2, animate2, interval=500)
    plt.show()
    

#plot()

