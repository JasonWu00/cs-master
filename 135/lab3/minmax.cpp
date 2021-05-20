//Modified by: Ze Hong Wu (Jason)
//Email: zehong.wu17@myhunter.cuny.edu
//Date: February 24, 2021
//Lab 3b

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

  double minCap = 1000;
  double maxCap = 0;
  string date;
  double eastSt, eastEl, westSt, westEl;
  //setting up vars

  while(fin >> date >> eastSt >> eastEl >> westSt >> westEl) {
    if (eastSt > maxCap) {//check for max
      maxCap = eastSt;
    }
    if (eastSt < minCap && eastSt) {//check for min
      minCap = eastSt;
    }
  }
  //return answers
  cout << "Returning max and min values " << endl;
  cout << "Minimum: " << minCap << endl;
  cout << "Maximum: " << maxCap << endl;

  return 0;
}
