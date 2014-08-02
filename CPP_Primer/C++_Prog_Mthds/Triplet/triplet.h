//07/15/14
//
//Project 5 : Part A
//triplet.h
//Header file for triplet class which provides a "triple" object of three integer type and applicable operations

#ifndef TRIPLET_H
#define TRIPLET_H

#include <iostream>

class Triplet{

//storage of the 3 triplet values
    int data[3];

public:

//Constructors//

    Triplet() : data(){ }
    Triplet(int value);
    Triplet(int val1, int val2, int val3);

//Other member functions//

    int getFirst() const {return data[0];}
    int getSecond() const {return data[1];}
    int getThird() const {return data[2];}

//Overloaded operators//

//Returns sum of this object and operand
    const Triplet operator+(const Triplet &operand) const;

//Returns difference of this object and operand
    const Triplet operator-(const Triplet &operand) const;

// Post increment of this Triplet; all ints are incremented
     Triplet operator++(int);

//Pre increment of this Triplet; all ints are incremented
     Triplet operator++();

//Returns true if this object is equal to operand
    bool operator==(const Triplet &operand) const;

//Returns true if all three ints in this object are greater than ints in Triplet 'operand'
    bool operator>(const Triplet &operand) const;

//Returns the indexed value (0, 1, 2 legal indices)
    const int& operator[](int index) const;

//Friends//

//Reads a triplet object
    friend std::istream &operator>>(std::istream &in, Triplet &robject);

//Writes a triplet object
    friend std::ostream &operator<<(std::ostream &out, const Triplet &robject);
};

//Standard declaration of friend functions
    std::istream &operator>>(std::istream &in, Triplet &robject);
    std::ostream &operator<<(std::ostream &out, const Triplet &robject);

#endif
