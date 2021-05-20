#Name: Ze Hong Wu (Jason)
#Email: zehong.wu17@myhunter.cuny.edu
#Date: September 27, 2020
#Return money as change.

cash = int(input("Enter money in cents as an integer: "))

quarters = int(cash // 25)
dimes = int((cash - quarters * 25) // 10)
nickels = int((cash - dimes * 10 - quarters * 25) // 5)
pennies = cash - nickels * 5 - dimes * 10 - quarters * 25

print("Quarters: ", str(quarters))
print("Dimes: ", str(dimes))
print("Nickels: ", str(nickels))
print("Pennies: ", str(pennies))
