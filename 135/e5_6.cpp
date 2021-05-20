//Modified by: Ze Hong Wu (Jason)
//Email: zehong.wu17@myhunter.cuny.edu
//Date: March 11, 2021
//LHomework E5.6

#include <iostream>
#include <string>
using namespace std;

string middle(string str) {
  int len = str.length();//length
  if (len % 2 == 0) {
    string output = "";
    output.push_back(str[len / 2 - 1]);
    output.push_back(str[len / 2]);
    return output;
  }//returns 2 letters
  else {
    //returns 1 letter
    string output = "";
    output.push_back( str[(len - 1) / 2] );
    return output;
  }
}

int main() {
    string s;
    cout << "Enter string: ";
    cin >> s;
    string output = middle(s);
    cout << "Output is " << output << endl;
}
