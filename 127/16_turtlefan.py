#Name: Ze Hong Wu (Jason)
#Email: zehong.wu17@myhunter.cuny.edu
#Date: September 19, 2020
#make a turtle fan.

import turtle

stamps = int(input("How many stamps (integers only)? "))

pyro = turtle.Turtle()
pyro.shape("circle")
steps = 20
pyro.penup()

for i in range(stamps):
    pyro.stamp()
    if i % 4 == 0:
        steps += 2
    pyro.forward(steps)
    pyro.right(24)
