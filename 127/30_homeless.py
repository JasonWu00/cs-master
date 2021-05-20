#Name: Ze Hong Wu (Jason)
#Email: zehong.wu17@myhunter.cuny.edu
#Date: October 26, 2020
#Provide the given data.

import pandas as pd
import matplotlib.pyplot as plt

filename = input("Enter name of file here: ")
output = input("Enter name of output image name: ")

homeless = pd.read_csv(filename)
homeless["Fraction Single Women"] = homeless["Single Adult Women in Shelter"] / homeless["Total Individuals in Shelter"]

homeless.plot(x = "Date of Census", y = "Fraction Single Women")
plt.show()
plt.savefig(output)
