//Modified by: Ze Hong Wu (Jason)
//Email: zehong.wu17@myhunter.cuny.edu
//Date: February 8, 2021
//Lab 2c

#include <iostream>
using namespace std;

int main() {
  int myData[10];

  for(int i = 0; i < 10; i++) {
    myData[i] = 1; //setup
  }

  for(int i = 0; i < 10; i++) {
    cout << myData[i] << " "; //display data
  }
  cout << endl;

  int index, value;

  cout << "You can now make an addition to the array." << endl;
  cout << "To exit the editing sequence, enter a number greater than ten or less than zero." << endl;
  cout << "Index: ";
  cin >> index;
  cout << "Value: ";
  cin >> value;
  //takes in values

  if (index < 0 or index >= 10) {
    cout << "Exiting." << endl;
    return 0;
  }//exit condition

  do {
    myData[index] = value; //update array

    for(int i = 0; i < 10; i++) {
      cout << myData[i] << " ";
    }
    cout << endl;//print array

    cout << "Addition logged. Processing new addition." << endl;
    cout << "Index: ";
    cin >> index;
    cout << "Value: ";
    cin >> value;
    //take in values

    if (index < 0 or index >= 10) {
      cout << "Exiting." << endl;
      return 0;
    }//exit cond
  } while (0 <= index <= 10);

  return 0;
}
