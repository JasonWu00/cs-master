//Modified by: Ze Hong Wu (Jason)
//Email: zehong.wu17@myhunter.cuny.edu
//Date: February 24, 2021
//Lab 3d

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
  bool printStuff = false;
  int ticker = 0;

  cout << "Enter a start date: " << endl;
  cin >> startDate;
  cout << "Enter an end date: " << endl;
  cin >> endDate;

  double westEle[365];
  string times[365];
  //setting up variables

  while(fin >> date >> eastSt >> eastEl >> westSt >> westEl) {
    times[ticker] = date;
    westEle[ticker] = westEl;
    //parse info into arrays
    ticker++;
  }
  /*
  cout << "We got past reading the file" << endl;
  cout << "Example value from arrays" << endl;
  cout << "times[tick]: " << times[42] << endl;
  cout << "westEle[tick]: " << westEle[42] << endl;
  */
  for(int tick = 364; tick >= 0; tick--) {
    if (times[tick] == endDate) {
      printStuff = true;
      //cout << "Start returning info" << endl;
    }

    if (printStuff) {
      cout << times[tick] << " " << westEle[tick] << endl;
      //return info
      //for some reason this didn't work earlier but now it does
    }

    if (times[tick] == startDate) {
      printStuff = false;
      //cout << "End returning info" << endl;
    }//determines when to look for information

  }

  return 0;
}
