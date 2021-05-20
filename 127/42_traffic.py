#Modified by: Ze Hong Wu (Jason)
#Email: zehong.wu17@myhunter.cuny.edu
#Date: November 9, 2020
#Returns a html file with a map.

import folium
import pandas as pd

filename = input("Enter filename: ")
output = input("Enter output filename: ")

carcrash = pd.read_csv(filename)

crashmap = folium.Map(location=[40.75, -74.125], tiles="Cartodb Positron")

for index,row in carcrash.iterrows():
    lat = row["LATITUDE"]
    lon = row["LONGITUDE"]
    time = row["TIME"]
    newMarker = folium.Marker([lat, lon], popup=time)
    newMarker.add_to(crashmap)

crashmap.save(outfile=output)
