//Author: Ze Hong Wu
//Course: CSCI 135
//Instructor: Tong Yi
//Assignment: Lab 7b

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

int countChar(std::string line, char c) {
  int output = 0;
  for (int i = 0; i < line.length(); i++) {
    if (line[i] == c) {
      output++;
    }
  }
  return output;
}

int main() {
  std::string input;
  std::string output;
  int openBraceCount;
  int closedBraceCount;
  int tempIndCount;//remembers the indents for one line
  int indentationCount = 0;

  while (getline(std::cin, input)) {//take in stuff
    output = removeLeadingSpaces(input);

    tempIndCount = indentationCount;

    if(output[0] == '}'){
      tempIndCount = indentationCount -1;
      //minus 1 indent, outside of bracket set
    }

    for(int i = 0; i < tempIndCount; i++){
      std::cout << "\t";
    }

    openBraceCount = countChar(output, '{');
    closedBraceCount = countChar(output, '}');
    //counting
    indentationCount += openBraceCount - closedBraceCount;

    std::cout << output << std::endl;//remove space, print
  }
  return 0;
}
