#Modified by: Ze Hong Wu (Jason)
#Email: zehong.wu17@myhunter.cuny.edu
#Date: November 9, 2020
#Returns a html file with a map.

import folium
import pandas as pd

filename = input("Enter filename: ")
output = input("Enter output filename: ")
borough = input("Enter borough: ")

dropoff_csv = pd.read_csv(filename)
dfCopy = dropoff_csv.groupby("Borough").get_group(borough)

dropoffmap = folium.Map(location=[40.75, -74.125], tiles="Stamen Watercolor")

for index,row in dfCopy.iterrows():
    lat = row["Latitude"]
    lon = row["Longitude"]
    time = row["Address"]
    newMarker = folium.Marker([lat, lon], popup=time)
    newMarker.add_to(dropoffmap)

dropoffmap.save(outfile=output)
