#Name: Ze Hong Wu (Jason)
#Email: zehong.wu17@myhunter.cuny.edu
#Date: September 19, 2020
#Make a blue U in a 30x30 space.

import matplotlib.pyplot as plt
import numpy as np

canvas = np.ones((30, 30, 3))

#img = plt.imread(canvas)
#plt.imshow(img)
#plt.show()

canvas[0:30, 0:10, 0:2] = 0
canvas[0:30, 20:30, 0:2] = 0
canvas[20:30, 0:30, 0:2] = 0

#img = plt.imread(canvas)
#plt.imshow(img)
#plt.show()

plt.imsave("logo.png", canvas)
