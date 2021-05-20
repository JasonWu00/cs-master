//Author: Ze Hong Wu
//Course: CSCI 135
//Instructor: Tong Yi
//Assignment: Lab 12c
//a
//b
//c
//d
#include <iostream>
#include <vector>

std::vector<int> sumPairWise(std::vector<int> &v1, std::vector<int> &v2) {
  std::vector<int> output;
  int first_size = v1.size();
  int second_size = v2.size();
  int larger_size;

  if (first_size > second_size) {
    larger_size = first_size;
  }
  else {
    larger_size = second_size;
  }

  for (int i = 0; i < larger_size; i++) {
    int sum = 0;

    if (i < v1.size()) {
      sum += v1[i];
    }
    if (i < v2.size()) {
      sum += v2[i];
    }

    output.push_back(sum);
  }
  return output;
}

/*
int main() {
  std::cout << "Test" << std::endl;
  std::vector<int> a = {1, 2, 3};
  std::vector<int> b = {1, 2, 3, 4};
  std::vector<int> c = sumPairWise(a, b); //should be {2, 4, 6, 4}
  std::cout << c[0] << std::endl;
  std::cout << c[1] << std::endl;
  std::cout << c[2] << std::endl;
  std::cout << c[3] << std::endl;
  return 0;
}
*/
