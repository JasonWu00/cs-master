//Modified by: Ze Hong Wu (Jason)
//Email: zehong.wu17@myhunter.cuny.edu
//Date: February 24, 2021
//Lab 3a

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

  string date;
  double eastSt, eastEl, westSt, westEl;
  string userDate;
  //setting up vars
  cout << "Enter a date: ";
  cin >> userDate;

  while(fin >> date >> eastSt >> eastEl >> westSt >> westEl) {
    if (date == userDate) {//find the date, then return answer
      cout << eastSt << " gallons " << endl;
    }
  }
  return 0;
}
