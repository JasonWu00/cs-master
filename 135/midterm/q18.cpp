//Author: Ze Hong Wu
//Course: CSCI 135
//Instructor: Tong Yi
//Assignment: Midterm - Question 18

#include <iostream>

bool triangleSum(double a, double b, double c) {
  if (a + b <= c || a + c <= b || b + c <= a) {
    return false;
  }
  else {
    return true;
  }
}

int main() {
  double a, b, c;

  std::cout << "Enter value for a: ";
  std::cin >> a;
  std::cout << "Enter value for b: ";
  std::cin >> b;
  std::cout << "Enter value for c: ";
  std::cin >> c;

  if (not triangleSum(a, b, c)) {
    return 0;
  }

  double p = (a + b + c) / 2;

  double answer = sqrt(p * (p - a) * (p - b) * (p - c));
  std::cout << "Your answer is: " << answer << endl;
  return 0;
}
