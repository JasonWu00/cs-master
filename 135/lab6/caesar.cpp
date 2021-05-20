//Author: Ze Hong Wu
//Course: CSCI 135
//Instructor: Tong Yi
//Assignment: Lab 6b

#include <iostream>
#include <cctype>

char shiftChar(char c, int rshift) {
  int asciiValue = (int) c;
  //capital letters go from 65 to 90
  //lowercase letters go from 97 to 122
  int newAscii;

  if (asciiValue >= 65 && asciiValue <= 90) {//capital letters
    newAscii = asciiValue + rshift;
    if (newAscii > 90) {
      newAscii -= (90 - 65 + 1);
    }
  }

  else if (asciiValue >= 97 && asciiValue <= 122) {//lowercase letters
    newAscii = asciiValue + rshift;
    if (newAscii > 122) {
      newAscii -= (122 - 97 + 1);
    }
  }

  else {
    newAscii = asciiValue;
  }

  return (char) newAscii;
}

std::string encryptCaesar(std::string plaintext, int rshift) {
  std::string output = "";//start out as an empty string
  for (int i = 0; i < plaintext.length(); i++) {
    output += shiftChar(plaintext[i], rshift);//add every new char to output
  }
  return output;
}

int main() {
  std::string input;
  std::cout << "Enter a line of text: ";
  getline(std::cin, input);
  int rshift;
  std::cout << "Enter a shift value: ";
  std::cin >> rshift;

  std::string output = encryptCaesar(input, rshift);
  std::cout << output << std::endl;
  return 0;
}
