#Name: Ze Hong Wu (Jason)
#Email: zehong.wu17@myhunter.cuny.edu
#Date: September 5, 2020
#Draw the flower.

import turtle
bk = turtle.Screen()
bk.bgcolor("hotpink")

demoknight = turtle.Turtle()
demoknight.color("yellow")
demoknight.shape("turtle")
demoknight.pencolor("red")
demoknight.fillcolor("yellow")

for i in range(36):
    demoknight.forward(200)
    demoknight.left(170)
    demoknight.stamp()

#demoknight.penup()

#for i in range(36):
    #demoknight.forward(200)
    #demoknight.left(170)
    #demoknight.stamp()
