//Author: Ze Hong Wu
//Course: CSCI 135
//Instructor: Tong Yi
//Assignment: Lab 11d

#include <cmath>
#include <cstring>
#include <iostream>
using namespace std;

struct Post{
  string username;
  string message;
};

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

  static const int MAX_POSTS = 100;
  int numPosts;                    // number of posts
  Post posts[MAX_POSTS];           // array of all posts
public:
  // Constructor, makes an empty network (numUsers = 0)
  Network();
  // Attempts to sign up a new user with specified username and displayname
  // return true if the operation was successful, otherwise return false
  bool addUser(string usrn, string dspn);

  bool follow(string usrn1, string usrn2);
  void printDot();

  // Add a new post
  bool writePost(string usrn, string msg);
  // Print user's "timeline"
  bool printTimeline(string usrn);
};

bool Network::writePost(string usrn, string msg) {
  if (findID(usrn) != -1 && numPosts <= MAX_POSTS) {
    posts[numPosts] = {usrn, msg};
    //cout << posts[numPosts].username << " " << posts[numPosts].message << endl;
    numPosts++;
    return true;
  }
  else {
    return false;
  }
}

Network::Network() {
  numUsers = 0;
  numPosts = 0;
  for (int i = 0; i < MAX_USERS; i++) {
    for (int j = 0; j < MAX_USERS; j++) {
      following[i][j] = false;
    }
  }
}

string Profile::getUsername() {
  return username;
}

int Network::findID(string usrn) {
  for (int i = 0; i < numUsers; i++) {
    if (profiles[i].getUsername() == usrn) {//identical usernames
      return i;
    }
  }
  return -1;
}


bool Network::printTimeline(string usrn) {
  if (findID(usrn) == -1) {
    return false;
  }
  else {
    int userID = findID(usrn);
    for (int i = numPosts; i >= 0; i--) {
      if (posts[i].username == usrn || following[userID][findID(posts[i].username)]) {
        int targetID = findID(posts[i].username);
        cout << profiles[targetID].getFullName() << ": " << posts[i].message << endl;
      }

    }
    return true;
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

  nw.follow("mario", "luigi");
  nw.follow("luigi", "mario");
  nw.follow("luigi", "yoshi");
  nw.follow("yoshi", "mario");

  // write some posts
  nw.writePost("mario", "It's a-me, Mario!");
  nw.writePost("luigi", "Hey hey!");
  nw.writePost("mario", "Hi Luigi!");
  nw.writePost("yoshi", "Test 1");
  nw.writePost("yoshi", "Test 2");
  nw.writePost("luigi", "I just hope this crazy plan of yours works!");
  nw.writePost("mario", "My crazy plans always work!");
  nw.writePost("yoshi", "Test 3");
  nw.writePost("yoshi", "Test 4");
  nw.writePost("yoshi", "Test 5");

  cout << endl;
  cout << "======= Mario's timeline =======" << endl;
  nw.printTimeline("mario");
  cout << endl;

  cout << "======= Yoshi's timeline =======" << endl;
  nw.printTimeline("yoshi");
  cout << endl;
}
