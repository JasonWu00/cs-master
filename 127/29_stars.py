#Name: Ze Hong Wu (Jason)
#Email: zehong.wu17@myhunter.cuny.edu
#Date: October 19, 2020
#Returns average of a field for every star type.

import pandas as pd

filename = input("File name: ")
column = input("Column to be averaged: ")

star = pd.read_csv(filename)

avg = star.groupby(["Star type"]).mean()

#print("Average ", column, " for each type of star will be printed below.")

print(avg[column])

#Code prints output properly on IDLE and on windows command line interface but fails on auto-grader.
