//Author: Ze Hong Wu
//Course: CSCI 135
//Instructor: Tong Yi
//Assignment: Lab 9b
//a

#include <cmath>
#include <iostream>

class Coord3D {
public:
    double x;
    double y;
    double z;
};

double length(Coord3D *p) {
  double output = sqrt(pow((*p).x, 2) + pow((*p).y, 2) + pow((*p).z, 2));
  return output;
}

Coord3D * fartherFromOrigin(Coord3D *p1, Coord3D *p2) {
  if (length(p1) > length(p2)) {
    return p1;
  }
  else {
    return p2;
  }
}

void move(Coord3D *ppos, Coord3D *pvel, double dt) {
  double newX = (*ppos).x + (*pvel).x * dt;
  double newY = (*ppos).y + (*pvel).y * dt;
  double newZ = (*ppos).z + (*pvel).z * dt;
  (*ppos).x = newX;
  (*ppos).y = newY;
  (*ppos).z = newZ;
}//yeah

// allocate memory and initialize
Coord3D* createCoord3D(double x, double y, double z) {
  Coord3D *coord = new Coord3D;
  (*coord).x = x;
  (*coord).y = y;
  (*coord).z = z;
  return coord;
}

// free memory
void deleteCoord3D(Coord3D *p) {
  delete p;
}


/*int main() {
  return 0;
}*/
