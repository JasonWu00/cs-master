//Author: Ze Hong Wu (Jason)
//Course: CSci 135
//Instructor: Tong Yi
//Assignment: project 1 part d

#include <iostream>
using namespace std;

int main() {

  char prevOp = '_';
  char nextOp = '_';
  char currentOp;
  int exponentTime = 0;
  int num, sum = 0;
  cin >> sum;
  int numPrev = sum;

  while (cin >> currentOp/*>> num*/) { // While the reading operation is a success

    if (currentOp == '^') {
      //num = numPrev * numPrev;
      //cout << "Found an exponent" << endl;
      cin >> nextOp >> num;
      exponentTime = 1;
    }
    else if (currentOp != '^') {
      //cout << "No exponent found" << endl;
      cin >> num;
      exponentTime = 0;
    }

    //cout << "Current value of \"sum\": " << sum << endl; //debug
    /*
    cout << "Value of \"prevOp\" is: " << prevOp << endl; //debug print messages
    cout << "Value of \"currentOp\" is: " << currentOp << endl; //debug print messages
    cout << "Value of \"nextOp\" is: " << nextOp << endl; //debug print messages
    cout << "Value of \"num\" is: " << num << endl; //more debug prints
    cout << "Value of \"numPrev\" is: " << numPrev << endl; //more debug prints
    cout << "Value of \"sum\" is: " << sum << endl; //more debug prints
    cout << "Value of \"exponentTime\" is: " << exponentTime << endl;
    */

    if (nextOp != '+' && nextOp != '-' && nextOp != ';' && nextOp != '^') {
      nextOp = ';';
    }
    if (exponentTime == 1) {
      currentOp = nextOp;
    }

    if (exponentTime == 1) {//correcting for unaccounted for exponent
      if (prevOp == '-') {
        //cout << "Correcting for exponent and subtraction" << endl;
        sum += numPrev;
        sum -= (numPrev * numPrev);
      }
      else if (prevOp == '+') {
        //cout << "Correcting for exponent and addition" << endl;
        sum -= numPrev;
        sum += (numPrev * numPrev);
      }
      else if (prevOp = '_') {
        //cout << "First number is an exponent" << endl;
        sum *= sum;
      }
    }
    numPrev = num;
    prevOp = currentOp;
    //cout << "Value of \"sum\", after correction, is: " << sum << endl; //more debug prints

    if (currentOp == ';') {//end current operation
      //cout << "Value returned, calculating new operation" << endl << endl; //debug
      cout << sum << endl << endl; //returns value
      sum = num;
      //resets num and sum back to initial status at the start of loop
    }

    else if (currentOp == '+') {
      //cout << "adding value" << endl; //debug
      sum += num;
    }
    else if (currentOp == '-') {
      //cout << "subtracting value" << endl; //debug
      sum -= num;
    }
    //decide whether to add or subtract
    else {
      //cout << "Something went wrong" << endl;
    }
  }

  //cout << "Loop ended" << endl; //debug
  //cout << sum << endl << endl;
  return 0;
}
