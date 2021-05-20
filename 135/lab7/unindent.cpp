//Author: Ze Hong Wu
//Course: CSCI 135
//Instructor: Tong Yi
//Assignment: Lab 7a

#include <iostream>
#include <cctype>

std::string removeLeadingSpaces(std::string line) {
  std::string output = "";
  bool spaces = true;
  for (int i = 0; i < line.length(); i++) {
    if (not isspace(line[i])) {
      spaces = false;//turns off and never turns back on
    }
    if (spaces == false) {
      output += line[i];//take in the string
    }
  }

  return output;
}

int main() {
  std::string input;
  std::string output;
  int tabCount = 0;

  while (getline(std::cin, input)) {//take in stuff
    output = removeLeadingSpaces(input);

    std::cout << output << std::endl;//remove space, print
  }
  return 0;
}
