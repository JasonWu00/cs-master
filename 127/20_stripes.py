#Name: Ze Hong Wu (Jason)
#Email: zehong.wu17@myhunter.cuny.edu
#Date: October 12, 2020
#Create an image of green stripes.

import matplotlib.pyplot as plt
import numpy as np

imageSize = input("Enter the size of your image here: ")
outputName = input("Enter the name of the file to be outputted: ")

imageSize = int(imageSize)

canvas = np.ones((imageSize, imageSize, 3))

#img = plt.imread(canvas)
#plt.imshow(img)
#plt.show()

canvas[::2, :, ::2] = 0

#img = plt.imread(canvas)
#plt.imshow(img)
#plt.show()

plt.imsave(str(outputName), canvas)
