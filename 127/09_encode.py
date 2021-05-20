#Name: Ze Hong Wu (Jason)
#Email: zehong.wu17@myhunter.cuny.edu
#Date: September 12, 2020
#Given an input, shift it 13 letters forward.

unencoded = input("Enter text here: ")
encoded = ""

for letter in unencoded:
    offset = ord(letter) - ord("A") + 13
    new_position = (offset % 26)
    encoded += chr(new_position + ord("A"))

print(encoded)
