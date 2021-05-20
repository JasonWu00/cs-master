//Modified by: Ze Hong Wu (Jason)
//Email: zehong.wu17@myhunter.cuny.edu
//Date: February 8, 2021
//Lab 2b

#include <iostream>
using namespace std;

int main() {
  int smaller, bigger;
  cout << "Enter lower limit: ";
  cin >> smaller;
  cout << "Enter upper limit: ";
  cin >> bigger;
  //takes in values

  for(int i = smaller; i < bigger; i++) {
    cout << i << " "; //iterates and prints
  }
  cout << endl; //prevents console text from stacking on output
  return 0;
}
