//Author: Ze Hong Wu (Jason)
//Course: CSci 135
//Instructor: Tong Yi
//Assignment: lab 4g

#include <iostream>
using namespace std;

int main() {
  int width, height;
  cout << "Enter width: ";
  cin >> width;
  cout << endl;
  cout << "Enter height: ";
  cin >> height;
  cout << endl;
  //take in relevant data

  int oddOrEven = 0;
  //0 for every 1st, 2nd, and 3rd row
  //1 for every 4th, 5th, 6th row

  for (int h = 0; h < height; h++) {

    if (h % 6 <= 2) {
      oddOrEven = 0;
    }
    else {
      oddOrEven = 1;
    }

    for (int w = 0; w < width; w++) {//prints stuff per row

      if (oddOrEven == 0) {
        if (w % 6 <= 2) {//print stars
          cout << "*";
        }
        else {
          cout << " ";
        }
      }

      else {//oddOrEven is 1
        if (w % 6 >= 3) {//print stars, but differently
          cout << "*";
        }
        else {//prints spaces where it would have printed stars with oddOrEven as 0
          cout << " ";
        }
      }

    }//end of loop for each row
    cout << endl; //make newlines
  }

  return 0;
}
