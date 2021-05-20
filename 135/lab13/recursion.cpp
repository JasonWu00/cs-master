//Author: Ze Hong Wu
//Course: CSCI 135
//Instructor: Tong Yi
//Assignment: Lab 12c
//a
//b
#include <iostream>
#include <cstring>

void printRange(int left, int right) {
  if (left <= right) {
    std::cout << left << " ";
    printRange(left+1, right);
  }
  //do nothing if left > right
}

int sumRange(int left, int right) {
  int output;
  if (left > right) {
    output = 0;//nothing to add
  }
  else {
    output = left + sumRange(left+1, right);
  }
  return output;
}

int sumArray(int *arr, int size) {
  int output = 0;
  //int array[5];
  //array = *arr;
  if (size < 1) {
    output = 0; //nothing to add
  }
  else {
    //std::cout << (*arr) << std::endl;
    output = *arr + sumArray(arr+1, size-1);
  }
  return output;
}

bool isAlphanumeric(std::string s) {
  if (s == "") {
    return true;
  }
  else {
    int arrayLength = s.length();
    char *array = new char[arrayLength];
    strcpy(array, s.c_str());

    char firstChar = array[0];
    int c_int = (int) firstChar;
    bool isAlpha = (48 <= c_int && c_int <= 57) || (65 <= c_int && c_int <= 90) || (97 <= c_int && c_int <= 122);
    return (isAlpha && isAlphanumeric(s.substr(1, s.length()-1)));
  }
}

bool nestedParens(std::string s) {
  if (s == "") {
    return true;
  }
  else {
    int arrayLength = s.length();
    char *array = new char[arrayLength];
    strcpy(array, s.c_str());

    return (array[0] == '(' && array[arrayLength-1] == ')' && nestedParens(s.substr(1, s.length()-2)));
  }
}

int main() {

  int arr[] = {1, 2, 3};
  int size = 3;
  int output_two = sumArray(arr, 3);
  std::cout << output_two << std::endl;
  std::string parentheses = "((()))";
  std::cout << nestedParens(parentheses) << std::endl;
  return 0;
}
