#Modified by: Ze Hong Wu (Jason)
#Email: zehong.wu17@myhunter.cuny.edu
#Date: November 2, 2020
#Two functions for turtles to draw nested squares.
#Uses template from CSCI 127 github page.

import turtle

def setUp(turtle, dist, col):
    turtle.penup()
    turtle.forward(dist)
    turtle.pendown()
    turtle.color(col)


def squares(t, length):
    if (length > 10):
        for i in range(4):
            t.forward(length)
            t.left(90)
        squares(t, int(length / 2))


def nestedSquares(t, length):
    if (length > 10):
        for i in range(4):
            t.forward(length)
            t.left(90)
            nestedSquares(t, int(length / 2))


def main():
    n = int(input('Enter length: '))

    tom = turtle.Turtle()
    setUp(tom, -100, "darkgreen")
    squares(tom, n)

    tess = turtle.Turtle()
    setUp(tess, 100, "steelblue")
    nestedSquares(tess, n)

if __name__ == "__main__":
     main()
