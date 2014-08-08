//Project 7 : Part A
//FILE : Defines the implementation for the abstract base class LendItem
//DESC : LendItem.cpp

#include <iostream>
#include <string>
#include "LendItem.h"

int LendItem::LI_size = 0;
LendItem::LendItem()
{
    title = "Null title";
    mediumType = 'N';
    borrowed = false;
    borrowNumber = 0;
}

LendItem::LendItem(std::string tle, char med) : title(tle), mediumType(med)
{
    borrowed = false;
    borrowNumber = 0;
}

void LendItem::setTitle(std::string manu)
{
    title = manu;
}

void LendItem::setMedium(char med)
{
    mediumType = med;
}

void LendItem::setBNumber(int bNumber)
{
    borrowNumber = bNumber;
}
void LendItem::setBorrowed(bool bstatus)
{
    borrowed = bstatus;
}

bool LendItem::getBorrowed() const
{
    return borrowed;
}

std::string LendItem::getTitle()
{
    return title;
}

char LendItem::getMedium()
{
    return mediumType;
}

int LendItem::getBNumber()
{
    return borrowNumber;
}

std::ostream& operator <<(std::ostream &out, const LendItem &obj)
{
    if(obj.getBorrowed()){
        out << obj.title << " " << obj.borrowed << " " << obj.borrowNumber;
    }
    else{
        out << obj.title << " " << obj.borrowed;
    }
    return out;
}
