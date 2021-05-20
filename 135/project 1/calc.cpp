//Author: Ze Hong Wu (Jason)
//Course: CSci 135
//Instructor: Tong Yi
//Assignment: project 1 part b

#include <iostream>
using namespace std;

int main() {

  char sign;
  int num, sum = 0;
  cin >> sum;

  while (cin >> sign >> num) { // While the reading operation is a success
    //cout << "Value of \"sign\" is: " << sign << endl; //debug print messages
    //cout << "Value of \"num\" is: " << num << endl; //more debug prints

    if (sign == '+') {
      sum += num;
    }
    else if (sign == '-') {
      sum -= num;
    }
    //decide whether to add or subtract
  }
  cout << sum << endl;
  return 0;
}
