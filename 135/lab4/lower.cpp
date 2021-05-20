//Author: Ze Hong Wu (Jason)
//Course: CSci 135
//Instructor: Tong Yi
//Assignment: lab 4d

#include <iostream>
using namespace std;

int main() {
  int width, height;
  cout << "Enter width: ";
  cin >> width;
  cout << endl;
  //take in info

  for(int i = 0; i < width; i++) {//print each row
    //int oddOrEven = i % 2;
    // 0 for 0th, 2nd, 4th, etc
    // 1 for 1st, 3rd, 5th, etc

    for(int k = 0; k < width; k++){//print each asterisk

      if (k <= i) {
        cout << "*";
      }

      else {
        cout << " ";
      }
    }
    cout << endl;//row breaks
  }
}
