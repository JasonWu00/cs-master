//Author: Ze Hong Wu
//Course: CSCI 135
//Instructor: Tong Yi
//Assignment: Lab 11c

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
  bool following[MAX_USERS][MAX_USERS];

  // Returns user ID (index in the 'profiles' array) by their username
  // (or -1 if username is not found)
  int findID (string usrn);
public:
  // Constructor, makes an empty network (numUsers = 0)
  Network();
  // Attempts to sign up a new user with specified username and displayname
  // return true if the operation was successful, otherwise return false
  bool addUser(string usrn, string dspn);

  bool follow(string usrn1, string usrn2);
  void printDot();
};

Network::Network() {
  numUsers = 0;
  for (int i = 0; i < MAX_USERS; i++) {
    for (int j = 0; j < MAX_USERS; j++) {
      following[i][j] = false;
    }
  }
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
  //cout << "userID: " << numUsers << endl;
  numUsers++;
  return true;

}

bool Network::follow(string usrn1, string usrn2) {
  int firstID = findID(usrn1);
  int secondID = findID(usrn2);
  following[firstID][secondID] = true;
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

void Network::printDot() {
  string tab = "  ";
  cout << "digraph {" << endl;

  for (int i = 0; i < numUsers; i++) {//prints each user, e.g. @mario
    cout << tab << "\"@" << profiles[i].getUsername() << "\"" << endl;
  }
  cout << endl;

  for (int i = 0; i < numUsers; i++) {//for every user e.g. @mario
    for (int j = 0; j < MAX_USERS; j++) {//iterate through following[][]
      if (following[i][j]) {//following this person
        cout << tab << "\"@" << profiles[i].getUsername() << "\"";//print out @mario
        cout << " -> " << "\"@" << profiles[j].getUsername() << "\"" << endl;//print out -> @luigi
      }
    }
  }

  cout << "}" << endl;
}

int main() {
    Network nw;
    // add three users
    nw.addUser("mario", "Mario");
    nw.addUser("luigi", "Luigi");
    nw.addUser("yoshi", "Yoshi");

    // make them follow each other
    nw.follow("mario", "luigi");
    nw.follow("mario", "yoshi");
    nw.follow("luigi", "mario");
    nw.follow("luigi", "yoshi");
    nw.follow("yoshi", "mario");
    nw.follow("yoshi", "luigi");

    // add a user who does not follow others
    nw.addUser("wario", "Wario");

    // add clone users who follow @mario

    for(int i = 2; i < 6; i++) {
        string usrn = "mario" + to_string(i);
        string dspn = "Mario " + to_string(i);
        nw.addUser(usrn, dspn);
        nw.follow(usrn, "mario");
    }
    // additionally, make @mario2 follow @luigi
    nw.follow("mario2", "luigi");

    nw.printDot();
}
