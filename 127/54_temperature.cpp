//Modified by: Ze Hong Wu (Jason)
//Email: zehong.wu17@myhunter.cuny.edu
//Date: November 24, 2020
//Converts temperature.

#include <iostream>
using namespace std;
#include <iomanip>

int main(){
  float input;
  cout << "Temperature in Celsius: ";
  cin >> input;
  float output = input * 9.0 / 5.0 + 32;
  cout << fixed << setprecision(1);
  cout << "The temp in Fahrenheit is: " << output;
  return 0;
}
