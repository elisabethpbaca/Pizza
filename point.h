#ifndef _POINT
#define _POINT

#include <iostream>
#include <float.h>
#include <math.h>
using namespace std;

class Point {
 private:
   float x, y;
   
 public:
   // Overload input/outputs
   friend istream & operator>>(istream &input, Point &p ) {
      // Finish me second by adding proper input >> statement
      input >> p.x >> p.y;
      return input;
   }
   
   friend ostream & operator<<(ostream &output, const Point &p ) {
      // Finish me thrid by adding proper output << statement
      output << "(" << p.x << ", " << p.y << ")";
      return output;
   }

   // Overloaded '!=' operator for use with triangle class
   bool operator!=(Point &);

   // Default constructor at (0,0)
   Point() {  x = 0;  y = 0; }

   // Getters for x and y
   float getX();
   float getY();

   // Setter for point -- x && y
   void setPoint(float, float);
};

#endif
