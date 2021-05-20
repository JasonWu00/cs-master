#Modified by: Ze Hong Wu (Jason)
#Email: zehong.wu17@myhunter.cuny.edu
#Date: November 2, 2020
#Takes in a csv file and returns useful info.

import pandas as pd

#filename = input("Enter name of csv file here: ")

#film = pd.read_csv(filename)
df = pd.read_csv('Film_Permits.csv')
#totalLicenses = int(film.shape[0])

print(df["EventID"].max())
print()

#print("There are a total of ", totalLicenses, " licenses")

#avg = film.groupby(['Borough']).count()

#print(avg['EventID'])

#print("The 3 most popular types of events are: ")
#print(film['EventType'].value_counts()[:3])
