//Modified by: Ze Hong Wu (Jason)
//Email: zehong.wu17@myhunter.cuny.edu
//Date: March 11, 2021
//LHomework E8.1

#include <iostream>
#include <cstring>
#include <fstream>
#include <cstdlib>
#include <climits>
using namespace std;

int main() {
  ofstream textfile("hello.txt");

  if (textfile.fail()) {
    cerr << "File cannot be opened for reading." << endl;
    exit(1); // exit if failed to open the file
  }

  textfile << "Hello, World!";
  textfile.close();

  ifstream textfile2("hello.txt");

  if (textfile2.fail()) {
    cerr << "File cannot be opened for reading." << endl;
    exit(1); // exit if failed to open the file
  }

  string junk, output;
  while (textfile2 >> junk) {
    output.append(junk);
    output.append(" ");
  }
  cout << output << endl;

  return 0;
}
