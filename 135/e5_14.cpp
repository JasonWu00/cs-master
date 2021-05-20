//Modified by: Ze Hong Wu (Jason)
//Email: zehong.wu17@myhunter.cuny.edu
//Date: March 11, 2021
//LHomework E5.14

#include <iostream>
using namespace std;

void sort2(int& a, int&b) {
  if (b < a) {
    int temp_storage = b;
    b = a;
    a = temp_storage;
  }
}
