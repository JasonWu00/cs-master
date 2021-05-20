#Modified by: Ze Hong Wu (Jason)
#Email: zehong.wu17@myhunter.cuny.edu
#Date: November 16, 2020
#Random turtle movement

import turtle
import random

trey = turtle.Turtle()
trey.speed(5)
steps = 0

while (steps < 200):
  trey.forward(5)
  a = random.randrange(0,360,30)
  trey.right(a)
  steps += 1
