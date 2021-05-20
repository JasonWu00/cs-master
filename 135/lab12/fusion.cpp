//Author: Ze Hong Wu
//Course: CSCI 135
//Instructor: Tong Yi
//Assignment: Lab 12c
//a
//b
//c

#include <vector>

void gogeta(std::vector<int> &goku, std::vector<int> &vegeta) {
  for (int i = 0; i < vegeta.size(); i++) {
    goku.push_back(vegeta[i]);
  }
  vegeta.clear();
}
