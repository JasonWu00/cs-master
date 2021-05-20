//Modified by: Ze Hong Wu (Jason)
//Email: zehong.wu17@myhunter.cuny.edu
//Date: February 3, 2021
//Lab part 1

#include <iostream>
using namespace std;
#include <iomanip>

int main(){
  int number1;
  int number2;
  // initialize ints
  cout << "First num:";
  cin >> number1;
  cout << "Second num:";
  cin >> number2;
  //takes in numbers

  if (number1 < number2) {
    cout << number1 << endl;
  }
  else {
    cout << number2 << endl;
  }
  //if-else decision to decide what number to output
  return 0;
  //end
}
