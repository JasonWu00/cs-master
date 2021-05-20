//Author: Ze Hong Wu
//Course: CSCI 135
//Instructor: Tong Yi
//Assignment: Lab 11a

#include <cmath>
#include <cstring>
#include <iostream>
using namespace std;

class Profile {
private:
    string username;
    string displayname;
public:
    // Profile constructor for a user (initializing
    // private variables username=usrn, displayname=dspn)
    Profile(string usrn, string dspn);
    // Default Profile constructor (username="", displayname="")
    Profile();
    // Return username
    string getUsername();
    // Return name in the format: "displayname (@username)"
    string getFullName();
    // Change display name
    void setDisplayName(string dspn);
};

class Network {
private:
  static const int MAX_USERS = 20; // max number of user profiles
  int numUsers;                    // number of registered users
  Profile profiles[MAX_USERS];     // user profiles array:
                                   // mapping integer ID -> Profile

  // Returns user ID (index in the 'profiles' array) by their username
  // (or -1 if username is not found)
  int findID (string usrn);
public:
  // Constructor, makes an empty network (numUsers = 0)
  Network();
  // Attempts to sign up a new user with specified username and displayname
  // return true if the operation was successful, otherwise return false
  bool addUser(string usrn, string dspn);
};

Network::Network() {
  numUsers = 0;
}

int Network::findID(string usrn) {
  for (int i = 0; i < numUsers; i++) {
    if (profiles[i].getUsername() == usrn) {//identical usernames
      return i;
    }
  }
}

bool Network::addUser(string usrn, string dspn) {

  if (usrn == "") {
    return false;
  }

  int arrayLength = usrn.length();
  char *array = new char[arrayLength];
  strcpy(array, usrn.c_str());

  for (int i = 0; i < usrn.length(); i++) {
    char c = array[i];
    int c_int = (int) c;

    bool isAlphanumeric = (48 <= c_int && c_int <= 57) || (65 <= c_int && c_int <= 90) || (97 <= c_int && c_int <= 122);
    //cout << "character: " << c << endl;
    //cout << "(int) char: " << c_int << endl;
    //cout << "isAlpha value: " << isAlphanumeric << endl;
    //char is number, lowercase, or uppercase
    if (not isAlphanumeric) {//detected a non-alphanumeric value
      return false;
    }
  }

  delete[] array;

  if (numUsers > 0) {//there are other users
    for (int i = 0; i < numUsers; i++) {
      if (profiles[i].getUsername() == usrn) {//identical usernames
        return false;
      }
    }
  }

  if (numUsers == MAX_USERS) {//full array
    return false;
  }


  //add user
  profiles[numUsers] = {usrn, dspn};
  numUsers++;
  return true;

}

Profile::Profile() {
  username = "";
  displayname = "";
}

Profile::Profile(string usrn, string dspn) {
  username = usrn;
  displayname = dspn;
}

string Profile::getUsername() {
  return username;
}

string Profile::getFullName() {
  string output = displayname + "(@" + username + ")";
  return output;
}

void Profile::setDisplayName(string dspn) {
  displayname = dspn;
}

int main() {
  Network nw;
  cout << nw.addUser("mario", "Mario") << endl;     // true (1)
  cout << nw.addUser("luigi", "Luigi") << endl;     // true (1)

  cout << nw.addUser("mario", "Mario2") << endl;    // false (0)
  cout << nw.addUser("mario 2", "Mario2") << endl;  // false (0)
  cout << nw.addUser("mario-2", "Mario2") << endl;  // false (0)

  for(int i = 2; i < 20; i++)
      cout << nw.addUser("mario" + to_string(i),
                 "Mario" + to_string(i)) << endl;   // true (1)

  cout << nw.addUser("yoshi", "Yoshi") << endl;     // false (0)
}
