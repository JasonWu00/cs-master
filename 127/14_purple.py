#Name: Ze Hong Wu (Jason)
#Email: zehong.wu17@myhunter.cuny.edu
#Date: September 19, 2020
#Take in an image and purplefy it.

import matplotlib.pyplot as plt
import numpy as np

imageToEdit = input("Enter name of input image: ")
outputName = input("Name of your output image: ")

img = plt.imread(imageToEdit)   #Read in image
#plt.imshow(img)		                 #Load image into pyplot
#plt.show()

img2 = img.copy()        #make a copy of our image
img2[:,:,1] = 0          #Set the green channel to 0

#plt.imshow(img2)         #Load our new image into pyplot
#plt.show()               #Show the image (waits until closed to continue)

plt.imsave(outputName, img2)  #Save the image we created to the selected output name
