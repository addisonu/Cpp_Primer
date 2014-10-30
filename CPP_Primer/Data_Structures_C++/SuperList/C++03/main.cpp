//MAIN FUNCTION TO TEST NODE AND SUPERLIST CLASSES

#include <iostream>
#include <string>
#include <cassert>
#include <cstdlib>
#include "node1.h"
#include "SuperList.h"

using std::cout;
using std::endl;
using std::string;

int main()
{
cout << std::boolalpha;

//Effect:  constructor to create an empty list
//Precondition: NONE
//Postcondition: an empty list exists
std::cout << string(50, '-') << '\n' << "SuperList::SuperList()" << endl;
SuperList sl1;
cout << "sl1 = " << (sl1) << endl;
cout << "PASS" << endl;

//Effect: Determines if this object is empty
//Precondition:  NONE
//Postcondition: this SuperList object is unchanged
//Returns:  true if this SuperList is empty, false otherwise
std::cout << string(50, '-') << '\n' << "bool SuperList::isEmpty() const" << endl;
cout << "sl1 is empty : " << sl1.isEmpty() << endl;
cout << "PASS" << endl;

//Effect: Determines if this list is full
//Precondition:  NONE
//Postcondition:  this object is unchanged
//Returns:  true if it is not possible to allocate any more memory, false otherwise
std::cout << string(50, '-') << '\n' << "bool SuperList::isFull() const" << endl;
cout << "CHECK sl1 is full : " << sl1.isFull() << endl;
cout << "PASS" << endl;

//Effect: inserts newItem into front the list
//Precondition: NONE
//Postcondition: if this list is full, a ListException is to be thrown

std::cout << string(50, '-') << '\n' << "void SuperList::insertFront(string newItem)" << endl;
sl1.insertFront("middle");
sl1.insertFront("front");
cout << "sl1 size : " << sl1.lengthIs() << endl;
cout << "sl1 =  " << (sl1) << endl;
sl1.insertFront("frontmost");
cout << "sl1 size : " << sl1.lengthIs() << endl;
cout << "sl1 =  " << (sl1) << endl;
cout << "PASS" << endl;

//Effect: inserts newItem onto the rear of the list
//Precondition: NONE
//Postcondition: if this list is full, a ListException is to be thrown

std::cout << string(50, '-') << '\n' << "void SuperList::insertRear(string newItem)" << endl;
sl1.insertRear("last");
cout << "sl1 =  " << (sl1) << endl;
sl1.insertRear("lastmost");
cout << "sl1 =  " << (sl1) << endl;
cout << "PASS" << endl;

// Effect: if item is in the list, it is removed
// Precondition:  NONE
// Postcondition: a value may have been removed from this list
// Returns: true is returned if an item was removed, otherwise false is removed.
std::cout << string(50, '-') << '\n' << "bool SuperList::removeOne(string item)" << endl;
sl1.removeOne("last");
cout << "sl1 =  " << (sl1) << endl;
cout << "PASS" << endl;


// Effect: removes the first item in the list
// Precondition: list is not empty
// Postcondition: the first item in this list has been removed
// Returns: returns the string which has been removed from this list
std::cout << string(50, '-') << '\n' << "string SuperList::removeFirst()" << endl;
sl1.removeFirst();
cout << "sl1 =  " << (sl1) << endl;
cout << "PASS" << endl;

// Effect: removes the first N items in the list
// Precondition: list contains at least N items;  ‘result’ is an array with N elements
// Postcondition: the first N items in this list have been removed, and stored in the array ‘result’
std::cout << string(50, '-') << '\n' << "void SuperList::removeN(int N,  string result[])" << endl;
std::string result[2];
sl1.removeN(2, result);
cout << "sl1 =  " << (sl1) << endl;
cout << "PASS" << endl;

// Effect: provides the first item in the list
// Precondition: list is not empty
// Postcondition: the list has not been changed
// Returns: returns the string which is stored first in the list
std::cout << string(50, '-') << '\n' << "string SuperList::reportFirst() const" << endl;
sl1.insertFront("report first");
cout << "The string in the first position is : " << sl1.reportFirst() <<  endl;
cout << "PASS" << endl;

// Effect: provides the position of item in the list
// Precondition: None
// Postcondition: the list has not been changed
// Returns: returns a value between 1 and N, N being the number of values in the list
//If the item is not in the list, -1 is returned
std::cout << string(50, '-') << '\n' << "int SuperList::reportWhere(string item)  const" << endl;
cout << "sl1 =  " << (sl1) << endl;
cout << "'lastmost' is in position : " << sl1.reportWhere("lastmost") << endl;
cout << "'report first' is in position : " << sl1.reportWhere("report first") << endl;
cout << "'front' is in position : " << sl1.reportWhere("front") << endl;
cout << "PASS" << endl;

//Effect: returns the number of values stored in this list
//Precondition:  None
//Postcondition: this list object is unchanged
//Returns: the number of values in this list
std::cout << string(50, '-') << '\n' << "int SuperList::lengthIs() const" << endl;
cout << "sl1 length : " << sl1.lengthIs() << endl;
cout << "PASS" << endl;

//Effect:  determines if two lists are equal
//Precondition: NONE
//Postcondition: this list object is unchanged
//Returns:  returns true if this list contains the same elements in the same order as in obj
std::cout << string(50, '-') << '\n' << "bool SuperList::operator==(const SuperList& obj)  const" << endl;
SuperList sl2;
cout << "sl1 =  " << (sl1) << endl;
cout << "sl2 =  " << (sl2) << endl;
cout << "sl1 is equal to sl2 : " << (sl1 == sl2) << endl;
sl2.insertFront("front");
sl2.insertFront("report first");
cout << "sl2 =  " << (sl2) << endl;
cout << "sl1 is equal to sl2 : " << (sl1 == sl2) << endl;
cout << "PASS" << endl;

//Effect: returns a string containing all strings stored in this list
//Precondition:  NONE
//Postcondition:  this list object is unchanged
//Returns:  a string containing list items in format     {  string,  string,  string,   etc }
//If list is empty,  {  }   is returned
std::cout << string(50, '-') << '\n' << "friend ostream& operator<< (ostream& out, const SuperList& obj)" << endl;
cout << "PASS" << endl;
    return 0;
}
