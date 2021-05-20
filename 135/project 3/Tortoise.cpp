#include "Tortoise.h"
#include <cstdlib> //srand
#include <iostream> //use cout
#include <iomanip> //setw

Tortoise::Tortoise() {
  location = 0;
  patternLength = 10;

  torPattern = new int[patternLength];
  //int testPattern[] = {1, 2, 3, 4, 5};
  int defaultPattern[] = {3, 3, 3, 3, 3, -6, -6, 1, 1, 1};
  for (int i = 0; i < patternLength; i++) {
    this->torPattern[i] = defaultPattern[i];
  }
}

Tortoise::Tortoise(int *pattern, int patternLength, int location) {
  if (patternLength > 0){
    this->location = location;
    this->patternLength = patternLength;

    this->torPattern = new int[this->patternLength];
    for (int i = 0; i < patternLength; i++) {
      torPattern[i] = pattern[i];
    }
  }

  else {
    this->patternLength = 10;

    this->torPattern = new int[patternLength];
    //int testPattern[] = {1, 2, 3, 4, 5};
    int defaultPattern[] = {3, 3, 3, 3, 3, -6, -6, 1, 1, 1};
    for (int i = 0; i < this->patternLength; i++) {
      this->torPattern[i] = defaultPattern[i];
    }
    this->location = location;
  }
}

Tortoise::~Tortoise() {
  delete[] torPattern;
  torPattern = 0;
}

int Tortoise::getPosition() {
  return location;
}

int* Tortoise::getPattern() {
  return torPattern;
}

int Tortoise::getPatternLength() {
  return patternLength;
}

void Tortoise::setPosition(int pos) {
  location = pos;
}

void Tortoise::move() {
  int rng = rand() % patternLength;
  location += torPattern[rng];
}
