//Project 7 : Part A
//FILE : DVD.cpp
//DESC : Implementation of devired class DVD of base class LendItem

#include <iostream>
#include <string>
#include "LendItem.h"
#include "DVD.h"

DVD::DVD()
{
    mediumType = 'D';
    rating = "Null Rating";
    screenType = 'N';
}

DVD::DVD(std::string tle, std::string rtng, char stype) : LendItem(tle, 'D'), rating(rtng), screenType(stype) { }

void DVD::setRating(std::string rate)
{
    rating = rate;
}

void DVD::setScreen(char type)
{
    screenType = type;
}

std::string DVD::getRate()
{
    return rating;
}

char DVD::getType()
{
    return screenType;
}

void DVD::printAll(std::ostream &out, LendItem ** arr)
{
    std::cout << " - DVDs currently owned by the Marina - " << std::endl;
    for(int n = 0; n < LI_size; n++){
        if(arr[n]->getMedium() == 'D'){
        std::cout << *arr[n] << std::endl;
        }
    }
}
