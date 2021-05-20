#Modified by: Ze Hong Wu (Jason)
#Email: zehong.wu17@myhunter.cuny.edu
#Date: November 2, 2020
#Takes in user data and returns a housing score.

def main():
    year = int(input("Year in school (1, 2, 3, 4): "))
    age = int(input("Age: "))
    probation = input("Probation status (yes, no): ")
    fulltime = int(input("Half time or full time (0 or 1): "))
    gpa = float(input("Your GPA: "))
    score = computeScore([year, age, probation, fulltime, gpa])
    print(score)

def computeScore(answers):
    housingscore = 0
    if (answers[0] == 1):
        housingscore += 1
    elif (answers[0] == 2):
        housingscore += 2
    elif (answers[0] == 3):
        housingscore += 3
    elif (answers[0] == 4):
        housingscore += 4

    if (answers[1] >= 23):
        housingscore += 1

    if (answers[2].lower() == "yes"):
        housingscore -= 1

    if (answers[3] == 1):
        housingscore += 1

    if (answers[4] >= 3.5):
        housingscore += 1

    return housingscore

if __name__ == "__main__":
     main()
