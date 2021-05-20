//Modified by: Ze Hong Wu (Jason)
//Email: zehong.wu17@myhunter.cuny.edu
//Date: February 8, 2021
//Lab 2d

#include <iostream>
using namespace std;

int main() {
  int fib[60];

  fib[0] = 0;
  fib[1] = 1; //we have to start somewhere
  for(int i = 2; i < 60; i++) {
    fib[i] = fib[i-1] + fib[i-2]; //sets up values for fib
  }

  for (int i = 0; i < 60; i++) {
    cout << fib[i] << endl; //prints values of fib
  }
  return 0;
  //numbers go negative since the max value for an int is 2147483647
  //exceeding that will cause an underflow as the value loops around
}
