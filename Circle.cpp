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
Circle::Circle() {
	
  // Put your code here
  
}

// Parameterized constructor
// Description: A constructor with parameters for x, y, and radius.
//              Constructs a new circle with the given values.
Circle::Circle(int xCoord, int yCoord, double aRadius) {

  // Put your code here
  
}

// Description: Returns the circle's x coordinate.
// PostCondition: Does not change the circle.
int Circle::getX() const {

  // Put your code here
  
}

// Description: Returns the circle's y coordinate.
// PostCondition: Does not change the circle.
int Circle::getY() const {

  // Put your code here
  
}

// Description: Returns the circle's radius.
// PostCondition: Does not change the circle.
double Circle::getRadius() const {

  // Put your code here
  
}


// Description: Changes the circle's radius to aRadius,
//              or to 10.0 if aRadius is <= 0.0 (invalid).
void Circle::setRadius(double aRadius) {

  // Put your code here
  
} 

// Description: Moves the circle the given horizontal and 
//              vertical distances (therefore changing 
//              its x and y data members (aka attributes).
// Replace void setX(int x); and void setY(int y);
void Circle::move(int horiz, int vert) {

  // Put your code here
  
} 

// Description: Computes and returns the circle's area.
// PostCondition: Does not change the circle. 
double Circle::computeArea() const	{

  // Put your code here
  
}

// Description: Prints the circle's data members like this:
//           	"This circle has a radius of 10.0 and is located at point (12,7)."
// PostCondition: Does not change the circle.
void Circle::printCircle() const {

  // Put your code here
  
}