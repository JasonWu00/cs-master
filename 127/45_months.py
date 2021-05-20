#Modified by: Ze Hong Wu (Jason)
#Email: zehong.wu17@myhunter.cuny.edu
#Date: November 16, 2020
#Takes in a number and returns a month.

def main():
    month = int(input("Enter a month, as an integer: "))
    while(month < 1 or month > 12):
        print("You fool, this isn't a proper value!")
        month = int(input("Enter a month, as an integer: "))
    output = monthString(month)
    print(output)

def monthString(month):
    if (month == 1):
        output = "January"
    elif (month == 2):
        output = "February"
    elif (month == 3):
        output = "March"
    elif (month == 4):
        output = "April"
    elif (month == 5):
        output = "May"
    elif (month == 6):
        output = "June"
    elif (month == 7):
        output = "July"
    elif (month == 8):
        output = "August"
    elif (month == 9):
        output = "September"
    elif (month == 10):
        output = "October"
    elif (month == 11):
        output = "November"
    elif (month == 12):
        output = "December"

    return output

if __name__ == "__main__":
     main()
