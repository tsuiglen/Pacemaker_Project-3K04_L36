import matplotlib.pyplot as plt
import matplotlib.animation as animation
from matplotlib import style
import random
x = 0
xs = []
ys = []
style.use('fivethirtyeight')
fig = plt.figure()
ax1 = fig.add_subplot(1,1,1)



def animate(i): #currently set to use randomly generated values for testing purposes
    global xs
    global ys
    global x
    xs.append(x)
    x = x + 1
    y = random.randint(0,50)
    print(x,",",y)
    ys.append(y)
    ax1.clear()
    ax1.plot(xs, ys)

def plot():
    global x
    global xs
    global ys
    global fig
    global ax1

    if(x > 0):
        fig = plt.figure()
        ax1 = fig.add_subplot(1,1,1)

    x = 0
    xs = []
    ys = []
    style.use('fivethirtyeight')

    ani = animation.FuncAnimation(fig, animate, interval=500)
    plt.show()