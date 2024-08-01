/*
* testcirc.cpp
*
* Description: Driver program or testing the Circle class.

* Author:
* Creation date: July 2024
*/

#include <iostream> // As we need to print data
#include <iomanip>  // As we need to set the precision of output
#include "Circle.h"

using std::cout;
using std::endl;


int main() {

  Circle c1 = Circle(0,0,3);       // on the stack frame
  Circle c2 = Circle(5,20,10);     // on the stack frame
  // "new" is the C++ equivalent of "malloc"
  Circle * c3 = new Circle(0,0,5); // on the heap 

  cout << "Printing c1";
  c1.printCircle();

  cout << "Printing c2:";
  c2.printCircle();

  cout << "Printing c3:";
  c3->printCircle();
  
  c3->move(10,10);
  c3->setRadius(13);
  c3->printCircle();

  cout << "c3 area" << c3->computeArea() << endl;  

  // "delete" is the C++ equivalent of "free" 
  delete c3;
  // A good habit to acquire. Avoid dangling pointers!
  c3 = nullptr;
  
  return 0;
}
