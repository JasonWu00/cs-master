#Modified by: Ze Hong Wu (Jason)
#Email: zehong.wu17@myhunter.cuny.edu
#Date: November 6, 2020
#Uses Folium to make a map with neighborhood airbnb locations plotted.

import folium
import pandas as pd

airbnb = pd.read_csv('AirBnB_NYC_2019.csv')

airbnb.fillna({'reviews_per_month':0, 'last_review':0},inplace=True)
airbnb.fillna({'host_name':"", 'name':""},inplace=True)
airbnb.drop(['host_id','host_name'], axis=1, inplace=True)

allerton = airbnb[airbnb['neighbourhood'] == 'Allerton']

allertonMap = folium.Map(location=[40.8613105, -73.8593181], tiles="Stamen Watercolor")

for index,row in allerton.iterrows():
    lat = row["latitude"]
    lon = row["longitude"]
    name = row["name"]
    newMarker = folium.Marker([lat, lon], popup=name)
    newMarker.add_to(allertonMap)

allertonMap.save(outfile='allertonLocations.html')
