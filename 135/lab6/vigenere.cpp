//Author: Ze Hong Wu
//Course: CSCI 135
//Instructor: Tong Yi
//Assignment: Lab 6c

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

std::string encryptVigenere(std::string plaintext, std::string keyword) {
  std::string output = "";//start out as an empty string
  int ticker = 0;
  for (int i = 0; i < plaintext.length(); i++) {

    int rshift = (int) keyword[(ticker % keyword.length())] - 97;

    int asciiValue2 = (int) plaintext[i];
    //make sure that ticker increment only during letters

    if (asciiValue2 >= 65 && asciiValue2 <= 90) {
      ticker++;
    }

    else if (asciiValue2 >= 97 && asciiValue2 <= 122) {
      ticker++;
    }

    output += shiftChar(plaintext[i], rshift);//add every new char to output

  }
  return output;
}

int main() {
  std::string input;
  std::cout << "Enter a line of text: ";
  getline(std::cin, input);
  std::string keyword;
  std::cout << "Enter a keyword: ";
  std::cin >> keyword;

  std::string output = encryptVigenere(input, keyword);
  std::cout << output << std::endl;
  return 0;
}
