//Modified by: Ze Hong Wu (Jason)
//Email: zehong.wu17@myhunter.cuny.edu
//Date: February 3, 2021
//LHomework E3.1

#include <iostream>
using namespace std;

int main() {
  int input;
  cout << "Enter number: ";
  cin >> input;
  cout << endl;

  if (input > 0) {
    cout << "Positive" << endl;
  }
  else if (input < 0) {
    cout << "Negative" << endl;
  }
  else {
    cout << "Zero" << endl;
  }
  return 0;
}
