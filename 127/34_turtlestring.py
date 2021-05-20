#Modified by: Ze Hong Wu (Jason)
#Email: zehong.wu17@myhunter.cuny.edu
#Date: October 26, 2020
#A program that uses command strings to control turtle drawing

import turtle

tess = turtle.Turtle()
myWin = turtle.Screen()     #The graphics window
commands = input("Please enter a command string: ")

for ch in commands:
    #perform action indicated by the character
    if ch == 'F':            #move forward
        tess.forward(50)
    elif ch == 'L':          #turn left
        tess.left(90)
    elif ch == 'R':          #turn right
        tess.right(90)
    elif ch == '^':          #lift pen
        tess.penup()
    elif ch == 'v':          #lower pen
        tess.pendown()
    elif ch == 'r':          #turn red
        tess.color("red")
    elif ch == 'g':          #turn green
        tess.color("green")
    elif ch == 'b':          #turn blue
        tess.color("blue")
    elif ch == 'S':          #stamp
        tess.stamp()
    elif ch == 'D':          #stamp, but with a dot
        tess.dot()
    elif ch == 'B':          #back up
        tess.backward(50)
    elif ch == 'p':
        tess.color("purple")
    else:                    #for any other character, print an error message
        print("Error: do not know the command:", ch)

print("See graphics window for your image")
myWin.exitonclick()         #Close the window when clicked
