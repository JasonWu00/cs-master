#Name: Ze Hong Wu (Jason)
#Email: zehong.wu17@myhunter.cuny.edu
#Date: October 19, 2020
#Return statistics

import matplotlib.pyplot as plt
import pandas as pd

borough = input("Borough: ")

pop = pd.read_csv('nycHistPop.csv',skiprows=5)

print("Min: ", pop[borough].min())
print("Max: ", pop[borough].max())
print("Mean: ", pop[borough].mean())
print("Median: ", pop[borough].median())
print("Standard Deviation: ", pop[borough].std())
