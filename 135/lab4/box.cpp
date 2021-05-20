//Author: Ze Hong Wu (Jason)
//Course: CSci 135
//Instructor: Tong Yi
//Assignment: lab 4a

#include <iostream>
using namespace std;

int main() {
  int width, height;
  cout << "Enter width: ";
  cin >> width;
  cout << "Enter height: ";
  cin >> height;
  cout << endl;
  //take in info

  for(int i = 0; i < height; i++) {//print each row
    for(int k = 0; k < width; k++){//print each asterisk
      cout << "*";
    }
    cout << endl;//row breaks
  }
}
