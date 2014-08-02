//07/12/14
//
//Project 4
//
//PhoneNumber.h
//Holds the class definition for the PhoneNumber class

#ifndef PHONENUMBER_H
#define PHONENUMBER_H

#include <iostream>

class PhoneNumber{

private:

//2 digit country code
    int countryCode = 43;

//3 digit area code
    int areaCode = 800;

//7 digit phone number
    int number = 8675309;

//'H', 'C', or 'B', for home, cell or business line
    char type = {'H'};

//Year that the entry was made
    int year = 1981;

public:

//Constructors
    PhoneNumber() = default;

    PhoneNumber(int ccode, int acode, int num, char num_type, int num_year) : countryCode(ccode), areaCode(acode), number(num), type(num_type), year(num_year) { }

    PhoneNumber(int num, char num_type = 'H') : number(num), type(num_type) { }

    PhoneNumber(int acode, int num, char num_type = 'C') : areaCode(acode), number(num), type(num_type) { }

//All setter methods set a private data member
    void setCountry(int ccode)
        {countryCode  = ccode;}

    void setArea(int acode)
        {areaCode = acode;}

    void setNumber(int num)
        {number = num;}

    void setType(char num_type)
        {type = num_type;}

    void setYear(int yr)
        {year = yr;}

//All getter methods return a private data member
    int getCountry() const
        {return countryCode;}

    int getArea() const
        {return areaCode;}

    int getNumber() const
        {return number;}

    int getType() const
        {return type;}

    int getYear() const
        {return year;}

    bool doubleDigits() const;
    void printNumber(std::ostream &out) const;
    void printPhoneNumberStats(std::ostream &out);
};

#endif
