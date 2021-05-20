#Modified by: Ze Hong Wu (Jason)
#Email: zehong.wu17@myhunter.cuny.edu
#Date: November 2, 2020
#Determines train ticket cost.

def computeFare(zone, type):
    price = 0
    if (zone == 1):
        if (type == "peak"):
            price = 8.75
        elif (type == "off-peak"):
            price = 6.25
    elif (zone == 2 or zone == 3):
        if (type == "peak"):
            price = 10.25
        elif (type == "off-peak"):
            price = 7.50
    elif (zone == 4):
        if (type == "peak"):
            price = 12.00
        elif (type == "off-peak"):
            price = 8.75
    elif (zone == 5 or zone == 6 or zone == 7):
        if (type == "peak"):
            price = 13.50
        elif (type == "off-peak"):
            price = 9.75
    else:
        price = -1

    return(price)

#code from the csci 127 github page
def main():
    zone = int(input('Enter the number of zones: '))
    type = input('Enter the ticket type (peak/off-peak): ').lower()
    fare = computeFare(zone, type)
    print('The fare is', fare)

#Allow script to be run directly:
if __name__ == "__main__":
     main()
