#Name: Ze Hong Wu (Jason)
#Email: zehong.wu17@myhunter.cuny.edu
#Date: September 12, 2020
#use ord() and chr() to complete required tasks.

string = input("Enter a message here: \n")
for c in string:
  print(c, ord(c) + 1, chr(ord(c) + 1))
