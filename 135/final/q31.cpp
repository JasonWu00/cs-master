#include <string>
#include <cstdlib>

int differentLetters(std::string a, std::string b) {
  int a_length = a.size();
  int b_length = b.size();
  int output = abs(a_length - b_length);

  int arrayLength = a.length();
  char *arrayOne = new char[arrayLength];
  strcpy(arrayOne, a.c_str());

  arrayLength = b.length();
  char *arrayTwo = new char[arrayLength];
  strcpy(arrayTwo, b.c_str());

  int loop_length;
  if (a_length < b_length) {
    loop_length = a_length;
  }
  else {
    loop_length = b_length;
  }

  for (int i = 0; i < loop_length; i++) {
    if (arrayOne[i] != arrayTwo[i]) {
      output++;
    }
  }

  return output;
}
