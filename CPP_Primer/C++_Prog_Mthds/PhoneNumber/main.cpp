//07/12/14
//
//Project 4
//
//main.cpp
//Tests the PhoneNumber class

#include "PhoneNumber.h"
#include <iostream>
#include <string>
#include <sstream>
#include <cctype>
#include <cstring>
#include <new>

int main()
{

//User prompts

//Variables to validate user input
    std::string input("");

//Prompts user for number of entries user will make
    int num_entry(0);

    while(true){
        std::cout << "How many phone numbers would you like to enter?\n";
        std::getline(std::cin, input);
        std::stringstream numSS(input);

        if(numSS >> num_entry && num_entry > 0 && num_entry <= 25){
            break;
        }
        std::cout << "You've entered invalid input." << std::endl;
    }

//Array to hold all phone entries
    PhoneNumber *pnums = new PhoneNumber[num_entry];

for(int n = 0; n < num_entry; n++){
    std::cout << "Entry #" << n + 1 << ": " << std::endl;

//Prompt user for country code
    int ccode(0);

    while(true){

        std::cout << "Enter a two digit country code.\n";
        std::getline(std::cin, input);
        std::stringstream ccodeSS(input);

        if((input.length() == 2) && ccodeSS >> ccode && ccode > 9 && ccode <= 99){
            pnums[n].setCountry(ccode);
            break;
        }
        else if((input.length() == 1) && ccodeSS >> ccode && ccode > 0 && ccode < 10){
            pnums[n].setCountry(ccode);
            break;
        }
        std::cout << "You've entered invalid input." << std::endl;
    }

//Prompts user for area code
    int acode(0);

    while(true){

       std::cout << "Enter a three digit area code.\n";
       std::getline(std::cin, input);
       std::stringstream acodeSS(input);

       if((input.length() == 3) && (acodeSS >> acode) && acode > 99 && acode <= 999){
            pnums[n].setArea(acode);
            break;
       }
   std::cout << "You've entered invalid input." << std::endl;
    }

//Prompt user for a phone number
    int phone(0);

    while(true){

        std::cout << "Enter a seven digit phone number.\n";
        std::getline(std::cin, input);
        std::stringstream phoneSS(input);

        if((input.length() == 7) && (phoneSS >> phone) && phone > 1000000 && phone <= 9999999){
            pnums[n].setNumber(phone);
            break;
        }
        std::cout << "You've entered invalid input." << std::endl;
    }

//Prompts user for the type of phone number
    char num_type = {0};

    while(true){

        std::cout << "Enter a character for the type of the phone number: 'H' for home, 'C' for cellphone, and 'B' for business.\n";

        std::getline(std::cin, input);

        if((input.length() == 1) && (input == "H" || input == "C" || input == "B")){
            num_type = input[0];
            pnums[n].setType(num_type);
            break;
        }
        std::cout << "You've entered invalid input." << std::endl;
    }

//Prompts user for year of phone entry
    int year(0), current_year(2014);

    while(true){
        std::cout << "Enter the year the entry was made.\n";
        std::getline(std::cin, input);
        std::stringstream yearSS(input);

        if((input.length() == 4) && (yearSS >> year) && year >= 1900 && year <= current_year){
            pnums[n].setYear(year);
            break;
        }
        std::cout << "You've entered invalid input." << std::endl;
    }
    std::cout << std::endl;

    pnums[n].printNumber(std::cout);
    pnums[n].printPhoneNumberStats(std::cout);

    if(pnums[n].doubleDigits()){
        std::cout << "This phone number has repeated digits." << std::endl;
    }
    else{
        std::cout << "This phone number is made up of unique digits." << std::endl;
    }
    std::cout << std::endl;
}
    delete[] pnums;
    return 0;
}
