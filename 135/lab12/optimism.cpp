//Author: Ze Hong Wu
//Course: CSCI 135
//Instructor: Tong Yi
//Assignment: Lab 12b
//a
//b
//c

#include <vector>

std::vector<int> goodVibes(const std::vector<int> v) {
  std::vector<int> output;
  for (int i = 0; i < v.size(); i++) {
    int carryover = v[i];
    if (carryover > 0) {
      output.push_back(carryover);
    }
  }
  return output;
}
