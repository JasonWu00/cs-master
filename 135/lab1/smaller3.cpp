//Modified by: Ze Hong Wu (Jason)
//Email: zehong.wu17@myhunter.cuny.edu
//Date: February 3, 2021
//Lab part 2

#include <iostream>
using namespace std;
#include <iomanip>

int smallerOfTwo(int number1, int number2) {
  int smaller;
  if (number1 < number2) {
    smaller = number1;
  }
  else {
    smaller = number2;
  }
  return smaller;
}

int main(){
  int number1;
  int number2;
  int number3;
  // initialize ints
  cout << "First num:";
  cin >> number1;
  cout << "Second num:";
  cin >> number2;
  cout << "Third num:";
  cin >> number3;
  //takes in numbers

  int smaller = smallerOfTwo(number1, number2);
  //if-else to find smaller of 2, placed in its own function

  if (smaller < number3) {
    cout << smaller << endl;
  }
  else {
    cout << number3 << endl;
  }
  //if-else decision to decide what number to output
  return 0;
  //end
}
