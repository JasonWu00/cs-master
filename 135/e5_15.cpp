//Modified by: Ze Hong Wu (Jason)
//Email: zehong.wu17@myhunter.cuny.edu
//Date: March 11, 2021
//LHomework E5.15

#include <iostream>
using namespace std;

void sort2(int& a, int&b) {
  if (a > b) {
    int temp_storage = b;
    b = a;
    a = temp_storage;
  }
}

void sort3(int& a, int& b, int& c) {
  sort2(a, c);
  sort2(a, b);
  sort2(b, c);
}
