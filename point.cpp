#include <iostream>
#include "point.h"
using namespace std;

// Overloaded '!=' operator for use with triangle class
bool Point::operator!=(Point& p) {
   return ( !(this->x == p.getX()) && !(this->y == p.getY()) );
}

// Getters for x and y
float Point::getX() {
   return x;
}

float Point::getY() {
   return y;
}

// Setter for point -- x && y
void Point::setPoint(float x, float y) {
   this->x = x;
   this->y = y;
}
