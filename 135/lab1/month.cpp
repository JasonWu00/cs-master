//Author: Ze Hong Wu (Jason)
//Course: CSci 135
//Instructor: Tong Yi
//Assignment: Lab part 4

#include <iostream>
using namespace std;

int findLeapYear(int year) {
  string yeartype;
  // takes in year, inits year type

  if (year % 4 == 0 && year % 100 != 0) {
    return 1;
  }
  else if (year % 100 == 0 && year % 400 == 0) {
    return 1;
  }
  else {
    return 0;
  }
  //returns how many days to add in in order to account for leap years
}

int main() {
  int year, month;
  cout << "The year: ";
  cin >> year;
  cout << "The month: ";
  cin >> month;
  //takes in year and month

  int days;

  if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
    days = 31;
  }
  else if (month == 2) {
    days = findLeapYear(year);
    //account for leap years
    days += 28;
  }
  else {
    days = 30;
  }
  //calulates days

  cout << days << " days" << endl;
  //return answer
  return 0;
}
