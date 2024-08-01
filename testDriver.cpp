/*
 * testDriver.cpp
 * 
 * Class Description: Tests the List data collection ADT class.
 *
 * Modified on: July 2024
 * Author: AL 
 */

#include <iostream>
#include "List.h"

using std::cout;
using std::endl;

int main() {

  /* Variables declaration */
  const unsigned int MIN_NUMBER_OF_ELEMENTS = 5;
  
  // "new" is the C++ equivalent of "malloc"
  List * aList = new List();  // List object is on the heap

  /* Populating the List appending and prepending */
  cout << "Populating the List." << endl;  
  srand( time( 0 ) );
  unsigned int limit = MIN_NUMBER_OF_ELEMENTS + rand( ) % 10;
  for ( unsigned int i = 0; i < limit; i++ ) {
    if ( ! aList->append( rand( ) % 10 ) ) 
      cout << "Could not aList->append( )." << endl;
    /* Printing the List */ 
    cout << "Print the List with " << aList->getElementCount( ) << " elements." << endl; 
    aList->printList( );
    if ( ! aList->prepend( rand( ) % 10 ) ) 
      cout << "Could not aList->prepend( )." << endl;
    /* Printing the List */ 
    cout << "Print the List with " << aList->getElementCount( ) << " elements." << endl; 
    aList->printList( );
  }
  
  /* Printing the List */ 

    
  /* Getting the element at the front of the List */
  int * memoryReturn; 
  if(aList->getFrontElement(memoryReturn))
    cout << "Front element is " << *memoryReturn << endl;
  
 
  /* Removing the element at the front of the List */
  aList->removeAtFront();
  aList->printList;

   /* Printing the List */ 

  
  /* Getting the new element at the front of the List */ 

  
  // "delete" is the C++ equivalent of "free"
  delete aList;  
  // A good habit to acquire. Avoid dangling pointers!
  aList = NULL;
  
  return 0;
}
