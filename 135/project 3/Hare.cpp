#include "Hare.h"
#include <cstdlib> //srand
#include <iostream> //use cout
#include <iomanip> //setw

Hare::Hare() {
  location = 0;
  patternLength = 10;

  harePattern = new int[patternLength];
  //int testPattern[] = {1, 2, 3, 4, 5};
  int defaultPattern[] = {0, 0, 9, 9, -12, 1, 1, 1, -2, -2};
  for (int i = 0; i < patternLength; i++) {
    harePattern[i] = defaultPattern[i];
  }
}

Hare::Hare(int *pattern, int patternLength, int location) {
  if (patternLength > 0) {
    this->location = location;
    this->patternLength = patternLength;

    this->harePattern = new int[this->patternLength];
    for (int i = 0; i < patternLength; i++) {
      this->harePattern[i] = pattern[i];
    }
  }

  else {
    this->patternLength = 10;

    this->harePattern = new int[patternLength];
    //int testPattern[] = {1, 2, 3, 4, 5};
    int defaultPattern[] = {0, 0, 9, 9, -12, 1, 1, 1, -2, -2};
    for (int i = 0; i < this->patternLength; i++) {
      this->harePattern[i] = defaultPattern[i];
    }
    this->location = location;
  }
}

Hare::~Hare() {
  delete[] harePattern;
  harePattern = 0;
}

int Hare::getPosition() {
  return location;
}

int* Hare::getPattern() {
  return harePattern;
}

int Hare::getPatternLength() {
  return patternLength;
}

void Hare::setPosition(int pos) {
  location = pos;
}

void Hare::move() {
  int rng = rand() % patternLength;
  location += harePattern[rng];
}
