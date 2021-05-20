//Author: Ze Hong Wu (Jason)
//Course: CSci 135
//Instructor: Tong Yi
//Assignment: lab 4f

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

  if (width - 2 * (height - 1) <= 0) {
    cout << "Impossible height!";
    return 0;
  }

  int spaces = 0;
  int stars = width;
  for (int h = 0; h < height; h++) {

    for (int w = 0; w < spaces; w++) {//print inital spaces
      cout << " ";
    }

    for (int starCount = 0; starCount < stars; starCount++) {
      cout << "*";//print the stars
    }

    spaces++;
    stars -= 2;
    cout << endl;
    //iterates relevant data
    //a
  }

  return 0;
}
