//Author: Ze Hong Wu
//Course: CSCI 135
//Instructor: Tong Yi
//Assignment: Lab quiz 4

#include <iostream>
#include <cstring>
#include <fstream>
#include <cstdlib>
#include <climits>

int main() {
  std::ifstream fin("data.txt");

  if (fin.fail()) {
    std::cerr << "File cannot be opened for reading." << std::endl;
    exit(1); // exit if failed to open the file
  }

  std::string output;
  while (fin >> output) {
    std::cout << output << std::endl;
  }

  fin.close();
  return 0;
}
