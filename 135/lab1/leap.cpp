//Author: Ze Hong Wu (Jason)
//Course: CSci 135
//Instructor: Tong Yi
//Assignment: Lab part 3

#include <iostream>
using namespace std;

int main() {
  int year;
  cout << "Enter year: ";
  cin >> year;
  string yeartype;
  // takes in year, inits year type

  if (year % 4 == 0 && year % 100 != 0) {
    yeartype = "Leap";
  }
  else if (year % 100 == 0 && year % 400 == 0) {
    yeartype = "Leap";
  }
  else {
    yeartype = "Common";
  }
  //decides if something is a leap or common year
  //2 decisions for normal leap years and century leap years

  cout << yeartype << " year" << endl;
  //outputs answer
  return 0;
}
