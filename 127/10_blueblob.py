#Name: Ze Hong Wu (Jason)
#Email: zehong.wu17@myhunter.cuny.edu
#Date: September 19, 2020
#Take file from Lab 3 and modify it.

import turtle				#Import the turtle drawing package

turtle.colormode(255)		#Allows colors to be given as 0...255
tess = turtle.Turtle()		#Create a turtle
tess.shape("turtle")		#Make it turtle shaped
tess.backward(100)			#Move her backwards, to give more space to draw

#For 0,10,20,...,250
for i in range(0,255,10):
     tess.forward(10)		#Move forward
     tess.pensize(i)		#Set the drawing size to be i (larger each time)
     tess.color(0,0,i)		#Set the red channel to be i (brighter each time)

for i in range(255,0,-10):
     tess.forward(10)		#Move forward
     tess.pensize(i)		#Set the drawing size to be i (smaller each time)
     tess.color(0,0,i)		#Set the red channel to be i (dimmer each time)
