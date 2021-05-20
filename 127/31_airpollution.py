#Name: Ze Hong Wu (Jason)
#Email: zehong.wu17@myhunter.cuny.edu
#Date: October 26, 2020
#Return the necessary data.

import pandas as pd
import matplotlib.pyplot as plt

filename = input("Enter file name here: ")
output = input("Enter output image name here: ")

#Read in the csv file.
air = pd.read_csv(filename)

#Group the data by location averages.
groupdata = air.groupby('geo_entity_name').mean()['data_valuemessage']

groupdata.plot.bar()

plt.show()

plt.gcf().subplots_adjust(bottom=0.5)
fig = plt.gcf()
fig.savefig(output)
