//Author: Ze Hong Wu
//Course: CSCI 135
//Instructor: Tong Yi
//Assignment: Lab 12a
//a
//b
//c

#include <vector>

std::vector<int> makeVector(int n) {
  std::vector<int> output;
  for (int i = 0; i < n; i++) {
    output.push_back(i);
  }
  return output;
}
