#Name: Ze Hong Wu (Jason)
#Email: zehong.wu17@myhunter.cuny.edu
#Date: September 12, 2020
#Given an input, change it as instructed.

string = input("Enter a text here: ")
string = string.upper()
print("Your phrase in all caps: ", string)
splitter = string.split(" ")

print(splitter)

output = ""

for word in splitter:
    output += word[0]

print(output)
