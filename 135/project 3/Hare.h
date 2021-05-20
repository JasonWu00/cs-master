#ifndef HARE_H_
#define HARE_H_

class Hare {
public:
  Hare();
  ~Hare();
  Hare(int *pattern, int patternLength, int location);
  int* getPattern() ;
  int getPatternLength() ;
  int getPosition() ;
  void setPosition(int pos);
  void move();
private:
  int location;
  int patternLength;
  int* harePattern;
};

#endif
