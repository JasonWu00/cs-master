//Modified by: Ze Hong Wu (Jason)
//Email: zehong.wu17@myhunter.cuny.edu
//Date: February 3, 2021
//LHomework E3.5

#include <iostream>
using namespace std;

int main() {
  int one, two, three;

  cout << "First number: ";
  cin >> one;
  cout << endl;

  cout << "Second number: ";
  cin >> two;
  cout << endl;

  cout << "Third number: ";
  cin >> three;
  cout << endl;

  if (two > one && three > two) {
    cout << "Increasing" << endl;
  }
  else if (three < two && two < one) {
    cout << "Decreasing" << endl;
  }
  else {
    cout << "Neither" << endl;
  }
  return 0;
}
