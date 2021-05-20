//Author: Ze Hong Wu
//Course: CSCI 135
//Instructor: Tong Yi
//Assignment: Midterm - Question 20

#include <iostream>

int numStarter(string array[], int size, char start) {
  int result = 0;
  for (int tick = 0; tick < size; tick++) {
    if (array[tick][0] == char) {
      result++;
    }
  }
  return result;
}

int main() {
  string fruits[] = ["apple", "banan", "orange"];
  int startCount = numStarter(fruits, 3, 'a');
  std::cout << "The number of fruits starting with \'a\': " << startCount << endl;
}
