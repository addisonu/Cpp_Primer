//07/12/14
//
//Project 4
//
//PhoneNumber.cpp
//Holds the class implementation for the PhoneNumber class
//
//This class organizes phone numbers that are entered by a user

#include "PhoneNumber.h"
#include <iostream>
#include <string>

//Returns true if there are double digits in the 7 digit number
bool PhoneNumber::doubleDigits() const
{
    std::string str_num = std::to_string(number);

    int n(0), dd_cnt(0);

    for(; n < str_num.length(); n++){
        for(int m = n + 1; m < str_num.length(); m++){
            if(str_num[n] == str_num[m]){
                dd_cnt++;
            }
    }
}
    return dd_cnt;
}

//Prints area code and phone number only
void PhoneNumber::printNumber(std::ostream &out) const
{
    std::cout << "Phone number : (" << areaCode << ")" << number << std::endl;
}

//Prints all phone information
void PhoneNumber::printPhoneNumberStats(std::ostream &out)
{
//Prints complete phone number
    std::cout << "Complete phone number : +" << countryCode << " (" << areaCode << ")" << number << std::endl;

//Prints phone number type
    std::cout << "Phone number type : ";
    if(type == 'H'){
        std::cout << "Home" << std::endl;
    }
    else if(type == 'C'){
        std::cout << "Cell" << std::endl;
    }
    else if(type == 'B'){
        std::cout << "Business" << std::endl;
    }

//Prints year entry was made
    std::cout << "Year entry was made : " << year << std::endl;
}
