#include "MemoryGame.hpp"
#include <cstdlib> //srand, rand
#include <ctime>
#include <iomanip> //setw
#include <iostream> //std
#include <string>
using namespace std;

int* randomize(int numSpaces); //function to randomize layout
void swap(int* arr, int i, int j);
void displaySeparateLine(int numSpaces);

//
//TODO: implement by students
MemoryGame::MemoryGame() { //default constructor,
  // srand(time(NULL));
  srand(1);

  numPairs = 3;
  numSpaces = 2 * numPairs + 2;

  int *randomNumbers = new int[numPairs];

  for (int i = 0; i < numPairs; i++){
    randomNumbers[i] = rand()%1000;
  }
  int *array = randomize(numSpaces);
  values = new string[numSpaces];//init values

  //array will be removed eventually, no need to use new

  // cout << "Printing out array[] for debug" << endl;
  // for (int i = 0; i < numSpaces; i++) {
  //   cout << array[i] << endl;
  // }

  int ticker = 0;

  for (int i = 0; i < numSpaces; i++){
    if (i < numPairs * 2){
      values[array[i]] = to_string(randomNumbers[i / 2]); //converts int to string
      values[array[i + 1]] = to_string(randomNumbers[i / 2]);
    }
    else{
      values[array[i]] = "";
    }
  }
  /*
  for (ticker = 0; ticker <= numSpaces / 2; ticker+= 2) {
    //cout << "ticker is: " << ticker << endl;
    int currentRandomValue = rand()%1000;
    //cout << "rand is: " << currentRandomValue << endl;

    for (int i = 0; i < numSpaces; i++) {
      if (array[i] == ticker || array[i] == ticker+1) {
        values[i] = to_string(currentRandomValue);
        //cout << "values[" << i << "] is: " << values[i] << endl;
      }
    }
  }*/

  //free up memory
  delete[] randomNumbers;
  randomNumbers = nullptr;
  delete[] array;
  array = nullptr;

  // cout << "Printing out values[] for debug" << endl;
  // for (int i = 0; i < numSpaces; i++) {
  //   cout << values[i] << endl;
  // }

    //put 3 pairs of randomly generated ints in [0, 1000)
    //randomly in numSpaces blocks.
    //Note that 2 added after 2 * numPairs means number of
    //two extra blocks without actual data.
    //srand(time(NULL)); //TODO: uncomment this line to see
        //different layouts of numbers in different runnings.
        //time(NULL) is the current running time.
        //use the current running time to grow random sequence
        //Since running time differs,
        //the random sequence looks different
        //at different running time.

    //TODO: your code here
}

//TODO: implement by students
MemoryGame::~MemoryGame(){
  //delete values;
    //When an object is no longer in need,
    //release dynamically allocated memory by
    //data members of the current object.
}

//TODO: implement by students
//randomize is not a member function,
//so there is no MemoryGame:: before function name randomize.
//Return an array of randomly allocated 0, 1, .., size-1
//In constructors, randomly assign the data in dataVector
//to array values
int* randomize(int size){
    //idea to randomize 0, 1, 2, 3, 4, 5,
    //generate a random int in [0, 6), say 3,
    //then move arr[3] to the end,
    //say, 0, 1, 2, 5, 4, 3
    //generate a random int in [0, 5), say 3 again,
    //then swap arr[3], which is 5 now, with arr[4],
    //get 0, 1, 2, 4, 5, 3
    //generate a random int in [0, 4), say 2,
    //swap arr[2] with the current arr[3]
    //get 0, 1, 4, 2, 5, 3
    //continue to randomize arr[0..2].
    //afterwards, continue to randomize arr[0..1].
  int *array = new int[size];
  for (int i = 0; i < size; i++){
    array[i] = i;
  }
  while (size > 0){
    int index = rand() % size;
    swap(array, index, size - 1);
    size--;
  }

  return array;
}

//TODO: implement by students
//int* arr means int array arr, which implies the address
//of the first element of array arr.
//swap arr[i] and arr[j] in array of ints arr.
void swap(int *arr, int i, int j) {
  int intermediate = arr[j];
  arr[j] = arr[i];
  arr[i] = intermediate;
}

//Display -----+ for numSpaces times.
//Add an extra + when for the first block (when index i is 0).
//So suppose numSpaces is 8, we get
//+-----+-----+-----+-----+-----+-----+-----+-----+
//followed by a new line.
void displaySeparateLine(int numSpaces)
{
    for (int i = 0; i < numSpaces; i++)
    {
        if (i == 0) {
           cout << "+";
         }
        cout << "-----+";
    }
    cout << endl;
}

//TODO: implement by students
//display the items in values array where bShown is true.
void MemoryGame::display(bool* bShown) {
  //display indices label
  cout << " ";
  for (int i = 0; i < numSpaces; i++){
    cout << setw(3) << i;
    cout << setw(3) << " ";
  }
  cout << endl;

  displaySeparateLine(numSpaces);
  cout << "|";
  for (int i = 0; i < numSpaces; i++) {
    if (bShown[i]) {
      //cout << "  0  |";
      cout << setw(5) << values[i] << "|";
    }
    else {
      cout << "     |";
    }
  }
  cout << endl;
  displaySeparateLine(numSpaces);
}

//TODO: implement by students
//rules for a round
//(1) pick a number, flip it
//(2) pick a second number, if the number is the same as
//    previous pick, display the second number,
//    otherwise, unflip the previous pick.
//(3) Finish until every pair are chosen correctly.
void MemoryGame::play(){

  bool* bShown = new bool[numSpaces];
  for (int i = 0; i < numSpaces; i++) {
    // bShown[i] = true;
    bShown[i] = false;
  }
  //cout << "Test" << endl;
  display(bShown);

  // delete[] bShown;
  // bShown = nullptr;
  int index; //index of the current flip
  int first; //hold the index of the first flip in each round
  int numFlips = 0;
  int pairsFound = 0;

  while (pairsFound < numPairs) {//game continues to run until win
    cout << "Enter index of slot to flip: ";
    cin >> index;

    while (index < 0 || index >= numSpaces || bShown[index] == true) {
      if (index < 0 || index >= numSpaces) {
        cout << "index out of range." << endl;
      }
      else {
        cout << "This cell has already been flipped." << endl;
      }
      cout << "Re-enter an index: ";
      cin >> index;
    }

    if (numFlips % 2 == 0) {//no lone flips
      bShown[index] = true;
      first = index;
    }
    else {//there is one lone flip
      if (values[first] == values[index] && values[first] != "") {//matching pair found
        bShown[index] = true;
        pairsFound++;
      }
      else {//non-matching pair
        bShown[first] = false;
      }
    }

    display(bShown);
    numFlips++;
  }

  cout << "Congratulations! Take " << numFlips << " steps to find all matched pairs." << endl;
  //victory message
  //now to clean up the game
  delete[] bShown;
  bShown = nullptr;
  /*
  */
}
