//Author: Ze Hong Wu (Jason)
//Course: CSci 135
//Instructor: Tong Yi
//Assignment: project 1 part a

#include <iostream>
using namespace std;

int main() {
    int s;
    int sum = 0;
    while(cin >> s) { // While the reading operation is a success
      sum += s;
        //cout << s << endl;  // sums up the numbers
        //cout << "NEWLINE" << endl;
    }
    cout << sum << endl;
    return 0;
}
