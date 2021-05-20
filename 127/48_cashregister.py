#Modified by: Ze Hong Wu (Jason)
#Email: zehong.wu17@myhunter.cuny.edu
#Date: November 16, 2020
#Takes in many price values and calculates a total cost.

print("Cash register open. Enter your values.")
currentcost = float(input("Enter a value here: "))
totalcost = 0.0

while (currentcost >= 0):
    totalcost += currentcost
    currentcost = float(input("Enter a value here: "))

totalcost *= 1.0875

print("Taxed total: ", totalcost)
