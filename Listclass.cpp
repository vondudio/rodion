/*
 * List.cpp  ***Using a heap-allocated array***
 * 
 * Class Description: List data collection ADT class with the following characteristics:
 *                   - Position-oriented list (unsorted elements).
 *                   - Positions of elements in the List start at 1 (not 0)
 *                     (unlike array indices).
 *
 * Inspired from List in CMPT 225 textbook.
 * Last Modification Date: July 2024
 */

#include <iostream>
#include "List.h"  // Header file

using std::cout;
using std::endl;

// Constructor
List::List() { } 

// Destructor
List::~List() {
  this->clear();
}

/* Getters */
// Description: Returns the current number of elements in the List.
int  List::getElementCount() const {
   return elementCount;
} 

/* Helper method */

// Description: Releases allocated memory and reset all data members to 
//              the state in which the List is in after being constructed.
void List::clear() {
  // If array has been allocated memory on the heap ... 
  if ( elements != nullptr ) {
    // ... then release it!
    delete [] elements;
    // A habit to get into - avoid dangling pointers
	elements = nullptr;  
  }
  elementCount = 0;
  return; 
}


// Description: If 1 <= "position" <= getElementCount() + 1, this method 
//              shifts elements right by 1, starting with the element
//              in the last position down to the element currently in "position".
//              This creates space for the "newElement". This method then inserts
//              "newElement" at "position" in the List. Lastly, it increments
//              "elementCount" by 1 and returns "true". 
//              Otherwise, if this method cannot insert the "newElement"
//              at "position", it returns "false".
bool List::insert(unsigned int position, int newElement) {

   // Validate "position": 1) If 1 <= "position" <= getElementCount() + 1
   //                      2) If List not already full
   bool ableToInsert = (position >= 1) && (position <= elementCount + 1) &&             
                       (elementCount < arraySize);

   if (ableToInsert) {   
      // Have we allocated heap memory for the array yet?
      if ( elements == nullptr ) {
         elements = new int[arraySize];
         if (elements == nullptr) {
            ableToInsert = false;
            return ableToInsert;
         }            		
      }
      // Make room for "newElement" by shifting all elements at
      // positions >= "position" toward the end of the array
      // (no shifting if "position" == elementCount + 1)
      for (unsigned int pos = elementCount; pos >= position; pos--)
         elements[pos] = elements[pos - 1];
         
      // Insert new Element
      elements[position - 1] = newElement;
      // Increase count of elements
      elementCount++;  
   } 

   return ableToInsert;
}  

// Description: If 1 <= "position" <= getElementCount(), this method 
//              shifts elements left by 1, starting with the element
//              in "position" + 1 up to the last element. This "removes"
//              the element at "position". Lastly, it decrements
//              "elementCount" by 1 and returns "true". 
//              Otherwise, if this method cannot remove the element
//              at "position", it returns "false".
bool List::remove(unsigned int position) {

   // Validate "position": 1) If 1 <= "position" <= getElementCount()
   //                      2) The List (array) has been allocated memory
   bool ableToRemove = (position >= 1) && (position <= elementCount) && ( elements != nullptr );
   if (ableToRemove) {

      // Remove element at "position" by shifting all elements, starting at
      // "position" + 1, down by one place, i.e., toward the beginning of the array
      // (no shifting if position == elementCount)
      for (unsigned int fromIndex = position, toIndex = fromIndex - 1; fromIndex < elementCount;
	        fromIndex++, toIndex++)
         elements[toIndex] = elements[fromIndex];
         
      elementCount--;  // Decrease count of elements
   } 
   
   if ( elementCount == 0 ) clear( );
   
   return ableToRemove;
} 

   
// Description: If 1 <= "position" <= getElementCount(), this method 
//              returns the element at "position" via "retrievedElement"
//              and returns "true". Otherwise, if this method cannot 
//              retrieve the element at "position", it returns "false".
// PostCondition: The List is unchanged.
bool List::retrieve(unsigned int position, int * retrievedElement) const {

   // Validate "position": 1) If 1 <= "position" <= getElementCount()
   //                      2) The List (array) has been allocated memory
   bool ableToRetrieve = (position >= 1) && (position <= elementCount) && ( elements != nullptr );
   if (ableToRetrieve)
      *retrievedElement = elements[position - 1];

   return ableToRetrieve;
} 

// Description: If 1 <= "position" <= getElementCount(), this method
//              modifies (replaces) the element at "position" by overwriting it
//              with "newElement" and returns "true".
//              Otherwise, if this method cannot modify the element 
//              at "position" with "newElement", it returns "false".
bool List::modify(unsigned int position, int newElement) {

   // Validate "position": 1) If 1 <= "position" <= getElementCount()
   //                      2) The List (array) has been allocated memory
   bool ableToModify = (position >= 1) && (position <= elementCount) && ( elements != nullptr );
   if (ableToModify)
      elements[position - 1] = newElement;
   
   return ableToModify;
}

// Description: Prints all elements in the List.
// Format: This List has 5 elements: { 88 55 94 70 41 }
// PostCondition: The List is unchanged.
void List::printList() const {
   
   cout << "This List has " << elementCount << " elements: ";
   cout << "{ ";
   for (unsigned int index = 0; index < elementCount; index++)
      cout << elements[index] << " ";

   cout << "}" << endl;
   
   return;
}  