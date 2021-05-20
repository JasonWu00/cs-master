#include <iostream>
#include <cstring>
#include <fstream>
#include <cstdlib>
#include <climits>
#include <vector>
//#include <boost>
using namespace std;

int main() {
  ifstream fin("output-onlinecsvtools.tsv");

  if (fin.fail()) {
    cerr << "File cannot be opened for reading." << endl;
    exit(1); // exit if failed to open the file
  }

  string junk;        // new string variable
  getline(fin, junk); // read one line from the file

  int rating, time, rating_2, time_2, rating_3, time_3;
  double kf1_avg, kf2_avg, nc_avg, kf1_count, kf2_count, nc_count;
  /*
  cout << "Enter a start date: " << endl;
  cin >> startDate;
  cout << "Enter an end date: " << endl;
  cin >> endDate;
  bool printStuff = false;
  */
  //setting up variables
  /*
  string line;
  while (getline(fin, line)) {
    // Split line into tab-separated parts
    vector<string> parts;
    split(parts, line, boost::is_any_of("\t"));
    // TODO Your code goes here!
    //cout << "First of " << parts.size() << " elements: " << parts[0] << endl;
    kf1_avg += parts[0];
    kf2_avg += parts[4];
  }
  */
  cout << "Before loop" << endl;
  while (fin >> rating >> time >> rating_2 >> time_2 >> rating_3 >> time_3) {
    //cout << "Looped" << endl;
    kf1_avg += rating;
    kf2_avg += rating_2;
    nc_avg += rating_3;
  }
  string parsed;
  /*
  while (getline(fin, parsed, ' ')) {
     // do some processing.

     // do some processing.
  }*/
  fin.close();
  cout << "Test" << endl;
  cout << "Total for kf1: " << kf1_avg << endl;
  cout << "Total for kf2: " << kf2_avg << endl;
  cout << "Total for nc: " << nc_avg << endl;
  cout << "Avg for kf1: " << kf1_avg / 113 << endl;
  cout << "Avg for kf2: " << kf2_avg / 137 << endl;
  cout << "Avg for nc: " << nc_avg / 118 << endl;

  cout << "nc count for all year: " << 118 * 14 / 4 << endl;

  return 0;
}
