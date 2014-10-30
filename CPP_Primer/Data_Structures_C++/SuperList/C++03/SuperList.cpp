//Project 3
//10/01/14
//SuperList.cpp
//Class implementation for linked list container that uses the node class

#include <iostream>
#include <string>
#include <cstdlib>
#include <cassert>
#include "node1.h"
#include "SuperList.h"
#include "SLexpt.h"

//Effect:  constructor to create an empty list
//Precondition: NONE
//Postcondition: an empty list exists

SuperList::SuperList(){ head_ptr = NULL;}

//Effect: Determines if this object is empty
//Precondition:  NONE
//Postcondition: this SuperList object is unchanged
//Returns:  true if this SuperList is empty, false otherwise

bool SuperList::isEmpty() const
{
    return !list_length(head_ptr);
}

//Effect: Determines if this list is full
//Precondition:  NONE
//Postcondition:  this object is unchanged
//Returns:  true if it is not possible to allocate any more memory, false otherwise

bool SuperList::isFull() const
{
    node* test;

//If full, call a node class member function that will throw bad_alloc, catch the exception then throw ListException and call its member function what() to display an error message
    try{
        try{

            test = new node();
        }
        catch(std::bad_alloc){

            ListException err;
            throw err;
        }
    }
    catch(std::exception &err){
        err.what();
        return true;
    }
    delete test;
    return false;
}

//Effect: inserts newItem into front the list
//Precondition: NONE
//Postcondition: if this list is full, a ListException is to be thrown

void SuperList::insertFront(std::string newitem)
{
    list_head_insert(head_ptr, newitem);
}

//Effect: inserts newItem onto the rear of the list
//Precondition: NONE
//Postcondition: if this list is full, a ListException is to be thrown

void SuperList::insertRear(std::string newitem)
{
    addToEnd(head_ptr, newitem);
}

//Effect: if item is in the list, it is removed
//Precondition:  NONE
//Postcondition: a value may have been removed from this list
//Returns: true is returned if an item was removed, otherwise false is removed

bool SuperList::removeOne(std::string item)
{
    size_t len = list_length(head_ptr);
    if(len > 1){
        size_t item_pos = reportWhere(item);

        if(item_pos != -1){

//Get position of item to remove, use to get pointer to preceding element since list_remove takes pointer to previous node
            list_remove(list_locate(head_ptr, (item_pos - 1)));
            if(!list_locate(head_ptr, item_pos))
                    return true;
        }
    }
    else if(list_length(head_ptr) == 1){
        list_head_remove(head_ptr);
        if(!head_ptr)
            return true;
    }
    return false;
}

//Effect: removes the first item in the list
//Precondition: list is not empty
//Postcondition: the first item in this list has been removed
//Returns: returns the string which has been removed from this list

std::string SuperList::removeFirst()
{
        std::string str = head_ptr->data();
        list_head_remove(head_ptr);

        return str;
}

//Effect: removes the first N items in the list
//Precondition: list contains at least N items;  ‘result’ is an array with N elements
//Postcondition: the first N items in this list have been removed, and stored in the array ‘result’
//void SuperList::removeN( int N,  string result[])

void SuperList::removeN(int N, std::string result[])
{
//Copy SuperList elements to result
    for(size_t i = 1; i <= N; ++i){
        result[i - 1] = list_locate(head_ptr, i)->data();
    }

    if(list_length(head_ptr) == 1){
        list_head_remove(head_ptr);
    }
    else if(list_length(head_ptr) > 1){

//Remove 2 to N elements from SuperList first since list_remove takes pointer to previous node
            for(size_t j = 1; j < N; ++j){
                list_remove(list_locate(head_ptr, j));
            }
//Remove first node of SuperList object
            list_head_remove(head_ptr);
    }
}

//Effect: provides the first item in the list
//Precondition: list is not empty
//Postcondition: the list has not been changed
//Returns: returns the string which is stored first in the list

std::string SuperList::reportFirst() const
{
    return head_ptr->data();
}

//Effect: provides the position of item in the list
//Precondition: None
//Postcondition: the list has not been changed
//Returns: returns a value between 1 and N, N being the number of values in the list
//If the item is not in the list, -1 is returned

int SuperList::reportWhere(std::string item) const
{
    size_t i = 1;
    size_t len = list_length(head_ptr);

//Check all SuperList elements for equality with item
    for(; i <= len; ++i){
        if(list_locate(head_ptr, i)->data() == item){
            return i;
        }
    }
    return -1;
}

//Effect: returns the number of values stored in this list
//Precondition:  None
//Postcondition: this list object is unchanged
//Returns: the number of values in this lis

int SuperList::lengthIs() const
{
    return list_length(head_ptr);
}

//Effect:  determines if two lists are equal
//Precondition: NONE
//Postcondition: this list object is unchanged
//Returns:  returns true if this list contains the same elements in the same order as in obj

bool SuperList::operator==(const SuperList &rhs) const
{
    size_t len = list_length(head_ptr);

    if(len == list_length(rhs.head_ptr)){

//Compare all elements in both SuperList objects
        for(size_t i = 1; i <= len; ++i){
            if(list_locate(head_ptr, i)->data() != list_locate(rhs.head_ptr, i)->data()){
                return false;
            }
        }
        return true;
    }
    return false;
}

//Effect: returns a string containing all strings stored in this list
//Precondition:  NONE
//Postcondition:  this list object is unchanged
//Returns:  a string containing list items in format     {  string,  string,  string,   etc }
//If list is empty,  {  }   is returned

std::ostream& operator<<(std::ostream &out, const SuperList &obj)
{
    std::cout << "{";
    if(obj.head_ptr != NULL){
        size_t len = obj.lengthIs();
        if(len > 0){

//Use node function to get pointer to element to print by fetching data()
            for(size_t i = 1; i <= len; ++i){
                std::cout << (list_locate(obj.head_ptr, i)->data()) << (i < len ? ", " : "");
            }
        }
    }
        std::cout << "}";

    return out;
}
