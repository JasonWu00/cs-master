//Modified by: Ze Hong Wu (Jason)
//Email: zehong.wu17@myhunter.cuny.edu
//Date: November 30, 2020
//Draws a triangle.

#include <iostream>
using namespace std;

int main(){
  int size;
  cout << "Enter an integer here: ";
  cin >> size;
  int i;
  int j;
  cout << "\n";
  for (i = size; i > 0; i--) {
    for (j = i; j > 0; j--) {
      cout << "* ";
    }
    cout << "\n";
  }
  return 0;
}
