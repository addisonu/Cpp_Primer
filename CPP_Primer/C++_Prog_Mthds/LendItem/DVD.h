//Project 7 : Part A
//FILE : DVD.h
//DESC : Defines the derived class of LendItems,the DVD class

#ifndef DVD_H
#define DVD_H

#include <iostream>
#include <string>
#include "LendItem.h"

class DVD : public LendItem{

//Data members//

//'W' or 'F'
    char screenType;
    std::string rating;

    public:

//Constructors//
    DVD();
    DVD(std::string, std::string rating, char stype);

//Member Functions//
    void setRating(std::string rate = "PG");
    void setScreen(char type);
    std::string getRate();
    char getType();
    void printAll(std::ostream &out, LendItem ** arr);
};

#endif
