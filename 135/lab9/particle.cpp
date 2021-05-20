//Author: Ze Hong Wu
//Course: CSCI 135
//Instructor: Tong Yi
//Assignment: Lab 9f
//a

#include <cmath>
#include <iostream>

class Coord3D {
public:
    double x;
    double y;
    double z;
};

class Particle {
public:
  double x;
  double y;
  double z;
  double vx;
  double vy;
  double vz;
};

// dynamically allocate memory for a particle and initialize it
Particle* createParticle(double x, double y, double z,
                         double vx, double vy, double vz) {
  Particle *part = new Particle;
  (*part).x = x;
  (*part).y = y;
  (*part).z = z;
  (*part).vx = vx;
  (*part).vy = vy;
  (*part).vz = vz;
  return part;
}

// set its velocity to (vx, vy, vz)
void setVelocity(Particle *p, double vx, double vy, double vz) {
  (*p).vx = vx;
  (*p).vy = vy;
  (*p).vz = vz;
}

// get its current position
Coord3D getPosition(Particle *p) {
  Coord3D *pos = new Coord3D;
  (*pos).x = (*p).x;
  (*pos).y = (*p).y;
  (*pos).z = (*p).z;
  return *pos;//dereference pointer to get class
}

// update particle's position after elapsed time dt
void move(Particle *p, double dt) {
  double newX = (*p).x + (*p).vx * dt;
  double newY = (*p).y + (*p).vy * dt;
  double newZ = (*p).z + (*p).vz * dt;
  (*p).x = newX;
  (*p).y = newY;
  (*p).z = newZ;
}

// delete all memory allocated for the particle passed by pointer
void deleteParticle(Particle *p) {
  delete p;
}
