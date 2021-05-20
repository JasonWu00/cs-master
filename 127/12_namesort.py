#Name: Ze Hong Wu (Jason)
#Email: zehong.wu17@myhunter.cuny.edu
#Date: September 19, 2020
#Given a list of names, return them as instructed.

string = input("Enter list of names here: ")

ListOfNames = string.split(";")

for i in range(len(ListOfNames)):
    output = ""
    initial = ListOfNames[i].index(",") + 2
    output += ListOfNames[i][initial]
    output += "."
    if i == 0:
        output += " "
    for k in range(initial-2):
        output += ListOfNames[i][k]
    print(output)
