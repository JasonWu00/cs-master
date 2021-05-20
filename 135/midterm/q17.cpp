//Author: Ze Hong Wu
//Course: CSCI 135
//Instructor: Tong Yi
//Assignment: Midterm - Question 17

#include <iostream>

int main() {
  int income;
  std::cout << "Enter your income: ";
  std::cin >> income;

  double taxed_amt = income;
  if (income <= 30000) {
    taxed_amt *= 0.05;
  }
  else if (income > 30000 && income <= 75000) {
    taxed_amt *= 0.10;
  }
  else if (income > 75000 && income <= 150000) {
    taxed_amt *= 0.15;
  }
  else {
    taxed_amt *= 0.20;
  }

  std::cout << "Your will be taxed: " << taxed_amt << " dollars" << endl;
  return 0;
}
