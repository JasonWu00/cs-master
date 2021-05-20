//Modified by: Ze Hong Wu (Jason)
//Email: zehong.wu17@myhunter.cuny.edu
//Date: February 21, 2021
//LHomework E4.2

#include <iostream>
#include <cstring>
using namespace std;

int main() {
  string input;
  cout << "Enter a string here." << endl;
  cin >> input;//take input

  int arrayLength = input.length() +1;
  char letters[arrayLength];
  strcpy(letters, input.c_str());
  //parses input into an array

  cout << "Printing out every letter one by one." << endl;
  for (int i = 0; i < arrayLength; i++) {
    cout << letters[i] << endl; //print things in the array 1 at a time
  }
  return 0;
}
