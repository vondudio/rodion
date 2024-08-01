/*
* Circle.cpp
*
* Description: This class models a circle.
* Class Invariant: The circle's radius must be greater than 0.0

* Author:
* Creation date: July 2024
*/

#include <iostream> // As we need to print data
#include <cmath>    // We need this for pow()
#include "Circle.h" // The header file for the class - we need this!

using std::cout;
using std::endl;

/* 
 * Now follows each of the method implementations.  
 * The <class>:: that precedes each method identifies that the method 
 * belongs to the class.  If it is omitted the compiler will attempt 
 * to create a separate function, which may or may not be successful.
 */

// Default constructor
// Description: A default constructor that creates a circle of radius 10 at position (0,0).
//              The default constructor has no parameters.
Circle::Circle() : x(0), y(0), radius(DEFAULT_VALUE) {
  cout << "Calling default constructor," << endl;

  // Put your code here
}

// Parameterized constructor
// Description: A constructor with parameters for x, y, and radius.
//              Constructs a new circle with the given values.
Circle::Circle(int xCoord, int yCoord, double aRadius) {
  cout << "Calling parameterized constructor with x " << xCoord << " and y " << yCoord << " and radius " << aRadius << endl;
  x = xCoord;
  y = yCoord;
  radius = aRadius;

  //(a double), must be greater than 0.0
  if(aRadius < 0.0) radius = DEFAULT_VALUE;

}

// Description: Returns the circle's x coordinate.
// PostCondition: Does not change the circle.
int Circle::getX() const {

  return x;
  // Put your code here
  
}

// Description: Returns the circle's y coordinate.
// PostCondition: Does not change the circle.
int Circle::getY() const {

  return y;
  // Put your code here
  
}

// Description: Returns the circle's radius.
// PostCondition: Does not change the circle.
double Circle::getRadius() const {

  return radius;

}


// Description: Changes the circle's radius to aRadius,
//              or to 10.0 if aRadius is <= 0.0 (invalid).
void Circle::setRadius(double aRadius) {

  radius = aRadius;

  //(a double), must be greater than 0.0
  if(aRadius < 0.0) radius = DEFAULT_VALUE;
  
} 

// Description: Moves the circle the given horizontal and 
//              vertical distances (therefore changing 
//              its x and y data members (aka attributes).
// Replace void setX(int x); and void setY(int y);
void Circle::move(int horiz, int vert) {

  x = x + horiz;
  y = y + vert;
  
} 

// Description: Computes and returns the circle's area.
// PostCondition: Does not change the circle. 
double Circle::computeArea() const	{

  return M_PI * pow(radius,2);
  // Put your code here
  
}

// Description: Prints the circle's data members like this:
//           	"This circle has a radius of 10.0 and is located at point (12,7)."
// PostCondition: Does not change the circle.
void Circle::printCircle() const {

  cout << "This circle has a radius of "<< radius << " and is located at point ("<< x << ", "<< y << ")."<< endl;
  // Put your code here
  
}