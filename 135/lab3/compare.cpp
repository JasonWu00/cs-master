//Modified by: Ze Hong Wu (Jason)
//Email: zehong.wu17@myhunter.cuny.edu
//Date: February 24, 2021
//Lab 3c

#include <iostream>
#include <cstring>
#include <fstream>
#include <cstdlib>
#include <climits>
using namespace std;

int main() {
  ifstream fin("Current_Reservoir_Levels.tsv");

  if (fin.fail()) {
    cerr << "File cannot be opened for reading." << endl;
    exit(1); // exit if failed to open the file
  }

  string junk;        // new string variable
  getline(fin, junk); // read one line from the file

  string startDate, endDate, date;
  double eastSt, eastEl, westSt, westEl;
  cout << "Enter a start date: " << endl;
  cin >> startDate;
  cout << "Enter an end date: " << endl;
  cin >> endDate;
  bool printStuff = false;
  //setting up variables

  while(fin >> date >> eastSt >> eastEl >> westSt >> westEl) {

    if (date == startDate) {
      printStuff = true;
    }

    if (printStuff) {
      cout << date << " ";

      if (eastEl > westEl) {
        cout << "East";
      }
      else if (eastEl < westEl) {
        cout << "West";
      }
      else {
        cout << "Equal";
      }//returns answers

      cout << endl;
    }

    if (date == endDate) {
      printStuff = false;
    }//determines when to look for information

  }

  return 0;
}
