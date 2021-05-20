import pandas as pd
import matplotlib.pyplot as plt

supermarket = pd.read_csv("review data.csv")

supermarket.fillna({'Units':'NA', 'Comments':'N'},inplace=True)
supermarket.fillna({'Units_2':'NA', 'Comments_2':'N'},inplace=True)
supermarket.fillna({'Units_3':'NA', 'Comments_2':'N'},inplace=True)

first_kf = supermarket.groupby(['Rating'])
second_kf = supermarket.groupby(['Rating_2'])
nc = supermarket.groupby(['Rating_3'])

print("\nAvg rating for the three stores:")
print("1: ", supermarket['Rating'].mean())
print("2: ", supermarket['Rating_2'].max())
print("nc: ", supermarket['Rating_3'].min())
