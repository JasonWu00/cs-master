#Name: Ze Hong Wu (Jason)
#Email: zehong.wu17@myhunter.cuny.edu
#Date: October 26, 2020
#Parse through a csv file to return a line graph.

import pandas as pd
import matplotlib.pyplot as plt

filename = input("Enter name of file here: ")
output = input("Enter name of output image name: ")

attendance = pd.read_csv(filename)
attendance["% Attending"] = (attendance["Present"] / attendance["Enrolled"]) * 100

attendance["Date"] = pd.to_datetime(attendance["Date"].apply(str))

attendance.plot(x = "Date", y = "% Attending")
plt.show()
plt.savefig(output)
