//Author: Ze Hong Wu
//Course: CSCI 135
//Instructor: Tong Yi
//Assignment: E6.8

#include <iostream>

void sort2(double* p, double* q) {
  double temp;

  if (*p > *q) {
    temp = *q;
    *q = *p;
    *p = temp;
  }
}

/*int main() {
  double p = 5.7;
  double q = 3.2;
  sort2(&p, &q);
  std::cout << p << " " << q << std::endl;
}*/
