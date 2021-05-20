#Name: Ze Hong Wu (Jason)
#Email: zehong.wu17@myhunter.cuny.edu
#Date: October 12, 2020
#Count number of pixels with >75% brightness.

import matplotlib.pyplot as plt
import numpy as np

imageName = input("Enter the name of your image here: ")

image = plt.imread(imageName)
snowCount = 0
threshold = 0.8

for i in range(image.shape[0]):
    for j in range(image.shape[1]):
        if (image[i, j, 0] > threshold) and (image[i, j, 1] > threshold) and (image[i, j, 2] > threshold):
            snowCount += 1

#img = plt.imread(canvas)
#plt.imshow(img)
#plt.show()

print("Snow count: ", snowCount)
