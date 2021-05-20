//Author: Ze Hong Wu (Jason)
//Course: CSci 135
//Instructor: Tong Yi
//Assignment: project 1 part c

#include <iostream>
using namespace std;

int main() {

  char sign;
  int num, sum, backup = 0;
  cin >> sum;

  while (cin >> sign >> num) { // While the reading operation is a success
    //cout << "Value of \"sign\" is: " << sign << endl; //debug print messages
    //cout << "Value of \"num\" is: " << num << endl; //more debug prints
    if (sign == ';') {//end current operation
      //cout << "Value returned, calculating new operation" << endl; //debug
      cout << sum << endl; //returns value
      //cin >> num;
      sum = num;
      //resets num and sum back to initial status at the start of loop
    }

    else if (sign == '+') {
      //cout << "adding value" << endl; //debug
      sum += num;
    }
    else if (sign == '-') {
      //cout << "subtracting value" << endl; //debug
      sum -= num;
    }
    //decide whether to add or subtract

    else {
      cout << "We do not recognize this operator" << endl;
    }
    //cout << "Current value of \"sum\": " << sum << endl; //debug
  }
  //cout << "Loop ended" << endl; //debug
  cout << sum << endl;
  return 0;
}
