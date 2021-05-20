//Modified by: Ze Hong Wu (Jason)
//Email: zehong.wu17@myhunter.cuny.edu
//Date: February 8, 2021
//Lab 2a

#include <iostream>
using namespace std;

int main() {
  double num; //encountered error when inputting large number
              //where the while loop would not wait for a responses
  cout << "Enter a number between 0 and 100: ";
  cin >> num;
  while (num <= 0 or num >= 100) {
    cout << "Your number does not fall within the interval, try again: ";
    cin >> num;
    //forces user to enter correct value
  }
  cout << num * num << endl; //returns answer
  return 0;
}
