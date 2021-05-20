#Name: Ze Hong Wu (Jason)
#Email: zehong.wu17@myhunter.cuny.edu
#Date: September 27, 2020
#Return hours, minutes, and seconds.

rawtime = int(input("Input number of seconds as an integer here: "))

hours = int(rawtime // 3600)
#print("hours: ", hours)
minutes = int((rawtime - hours * 3600) // 60)
#print("minutes: ", minutes)
seconds = rawtime - minutes * 60 - hours * 3600
#print("seconds: ", seconds)
outputHours = str(hours) + "h:"
outputMinutes = str(minutes) + "m:"
outputSeconds = str(seconds) + "s"

print(outputHours, outputMinutes, outputSeconds)
