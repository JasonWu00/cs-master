#ifndef ROAD_H_
#define ROAD_H_

class Road {
  public:
    Road();
    ~Road();
    Road(int length);
    int getLastBlock();
    void mark(int pos, char h);
    char* toString();
    void clear();
  private:
    int length;//the nth block
    char* squares;
};

#endif
