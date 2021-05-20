#Name: Ze Hong Wu (Jason)
#Email: zehong.wu17@myhunter.cuny.edu
#Date: September 19, 2020
#Take in a hex color code and make a turtle that color.

import turtle

hexcolorcode = input("Enter a valid hex color code without pound sign:")

truehex = "#"
truehex += hexcolorcode

demoman = turtle.Turtle()		#Create a turtle
demoman.shape("turtle")
demoman.color(truehex)

demoman.stamp()
