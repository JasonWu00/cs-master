//Modified by: Ze Hong Wu (Jason)
//Email: zehong.wu17@myhunter.cuny.edu
//Date: February 3, 2021
//LHomework E1.7

#include <iostream>
using namespace std;

int main() {
  double gas, efficiency, price = 0; //init values

  cout << "Gas tank volume (in gallons): ";
  cin >> gas;

  cout << "Engine efficiency (gallons per mile): ";
  cin >> efficiency;

  cout << "Price of a gallon: ";
  cin >> price;

  double costPer100 = (100 / efficiency) * price;
  cout << costPer100 << endl; //calculations, return value

  double maxDist = gas * efficiency;
  cout << maxDist << endl; //calculations, return value

  return 0;
}
