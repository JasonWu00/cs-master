#Modified by: Ze Hong Wu (Jason)
#Email: zehong.wu17@myhunter.cuny.edu
#Date: November 9, 2020
#Returns a html file with a map.

import folium

hunter = folium.Map(location=[40.75, -74.125])
marker = folium.Marker([40.75, -74.125], popup="Hunter College").add_to(hunter)
hunter.save(outfile='nycMap.html')
