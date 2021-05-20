//Author: Ze Hong Wu
//Course: CSCI 135
//Instructor: Tong Yi
//Assignment: Lab quiz 9

#include <iostream>
#include <cstring>

int unbalanced_brackets(std::string input) {
  char input_array[input.length()+1];
  strcpy(input_array, input.c_str());
  int openBrackets = 0;
  int closedBrackets = 0;
  for (int i = 0; i < input.length() + 1; i++) {
    if (input_array[i] == '{') {
      openBrackets++;
    }
    else if (input_array[i] == '}') {
      closedBrackets++;
    }
  }
  return openBrackets - closedBrackets;
}
