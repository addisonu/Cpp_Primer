//Project 2 : Part I
//Ursula Addison
//09/05/14
//Set.h
//Class definition for the Set class which models an unordered data structure

#ifndef SEATCHART_H
#define SEATCHART_H

#include <iostream>
#include <algorithm>

class Set {

//Aliases//

    typedef double value_type;
    typedef std::size_t size_type;
    static const size_type CAPACITY = 15;

//Data members//

//Two variables to track which elements of fixed size set are set or empty rescpectively
    size_type set_vals;
    size_type unset_vals;

//Holds all elements of set
    value_type data[CAPACITY];

    public:

//Constructors//

//Constructor to create a set which can store 15 value_type elements
    Set()
{
    set_vals = 0;
    unset_vals = CAPACITY;

    for(int i = 0; i < CAPACITY; i++){
//LEFT here fixing insert
    }
}
//Constructor creates a distinct copy of this Set object
    Set(const Set &obj);

    //~Set(){ delete [] data;}
//Member functions//

//Determines if this set is empty
    bool isEmpty() const { return !set_vals; }

//Determines if this set is full
    bool isFull() const { return set_vals == CAPACITY; }

//Inserts newItem into the set
    void insert(const value_type &newItem);

//If item is in the Set, it is removed
    bool remove(const value_type &item);

//Determines if a value is contained in the set
    bool contains(const value_type &item) const;

//Determines if one set is a subset of another
    bool subset(const Set &aSet) const;

//Creates a Set that is a union of this Set and another
    Set aUnion(const Set &aSet) const;

//Creates a set that is the intersection of this Set and another
    Set intersection(const Set &aSet) const;

//Determines if two sets are equal
    bool operator==(const Set &aSet) const;

//Overloaded assignment operator
    Set operator=(Set obj);

//Friend declarations//

//Outputs the elements of this Set in format { val1, val2, ...}
    friend std::ostream& operator<<(std::ostream &out, const Set &obj);
    friend void swap(Set &set1, Set &set2);
};

std::ostream& operator<<(std::ostream &out, const Set &obj);
void swap(Set &set1, Set &set2);
#endif
