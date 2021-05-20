//Author: Ze Hong Wu
//Course: CSCI 135
//Instructor: Tong Yi
//Assignment: Midterm - Question 19

#include <iostream>

int main() {
  int size;
  std::cout << "Enter an integer: ";
  std::cin >> size;

  if (size % 2 == 0) {
    return 0;
  }
  for int (tick = 1; tick <= size; tick += 2) {
    int spaceCount = (size - tick) / 2;

    for int (tick2 = 0; tick2 < spaceCount; tick2++) {
      std::cout << " ";
    }
    for int (tick3 = 0; tick3 < tick; tick3++) {
      std::cout << "*";
    }

    std::cout << endl;
  }

  return 0;
}
