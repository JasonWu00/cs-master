#ifndef TORTOISE_H_
#define TORTOISE_H_

class Tortoise {
public:
  Tortoise();
  ~Tortoise();
  Tortoise(int *pattern, int patternLength, int location);
  int* getPattern() ;
  int getPatternLength() ;
  int getPosition() ;
  void setPosition(int pos);
  void move();
private:
  int location;
  int patternLength;
  int* torPattern;
};

#endif
