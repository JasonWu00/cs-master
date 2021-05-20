//Author: Ze Hong Wu
//Course: CSCI 135
//Instructor: Tong Yi
//Assignment: Lab 6a

#include <iostream>
#include <cctype>

int main() {
  std::string input;
  std::cout << "Enter a line of text: ";
  getline(std::cin, input);
  //take in info

  for (int i = 0; i < input.length(); i++) {
    std::cout << input[i] << " " << (int) input[i] << std::endl;
    //print every char and their ascii value
  }
  //std::cout << 'A' << " " << (int) 'A' << std::endl;
  return 0;
}
