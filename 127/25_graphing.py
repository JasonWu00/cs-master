#Name: Ze Hong Wu (Jason)
#Email: zehong.wu17@myhunter.cuny.edu
#Date: October 19, 2020
#Graph Display

import matplotlib.pyplot as plt
import pandas as pd

firstBorough = input("First borough: ")
secondBorough = input("Second borough: ")
filename = input("File name: ")

pop = pd.read_csv('nycHistPop.csv',skiprows=5)
pop["Fraction"] = (pop[firstBorough] + pop[secondBorough]) / pop["Total"]
pop.plot(x="Year", y="Fraction")

plt.show()

plt.savefig(filename)
