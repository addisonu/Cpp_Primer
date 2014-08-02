//07/15/14
//
//Project 5 : Part A
//triplet.h
//Header file for triplet class which provides a "triplet" object of three integers  and applicable operations

#include <iostream>
#include <string>
#include <sstream>
#include <locale>
#include <cstring>
#include "triplet.h"

Triplet operator*(const Triplet &operand, const Triplet &operand2);
Triplet getTriplet();

int main()
{
    Triplet trip1(7);
    Triplet trip2(7,7,7);
    Triplet trip3(89, 67, 35);

    std::cout << "trip1: " << (trip1)  << std::endl;
    std::cout << "trip2: " << (trip2)  << std::endl;
    std::cout << "trip3: " << (trip3)  << std::endl;

//Validate user input
    std::string input("");
    int val1(0), val2(0), val3(0);

    while(true){
        std::cout << "Enter one integer to create a triplet object with three duplicate values." << std::endl;

        std::getline(std::cin, input);

//Check to see if there are any spaces in input, to make sure only one integer was entered
        if(input.find_first_of(' ') == std::string::npos){
            std::stringstream inputSS(input);

//Valdate input is integer
        bool validate = false;
        for(int n = 0; n < input.length(); n++){
            if(!isdigit(input[n])){
                validate = false;
                break;
            }
                validate = true;
        }
            if(inputSS >> val1 && validate){
                Triplet trip4(val1);

                std::cout << "trip4: " << (trip4)  << std::endl;
                std::cout << "trip4[2]: " << trip4.getThird() << std::endl;
                std::cout << "trip4[2]: " << trip4[2] << std::endl;
                std::cout << "trip3 + trip4: " << (trip3 + trip4) << std::endl;
                std::cout << "trip4 > trip3? " << (trip4 > trip3)  << std::endl;
                std::cout << "trip4 * trip1? " << (trip4 * trip1)  << std::endl;
                break;
            }
        }
            std::cout << "You've entered invalid input;" << std::endl;
    }
    std::cout << getTriplet() << std::endl;
    std::cout << getTriplet() << std::endl;

//Test member and non-member functions
    std::cout << "trip1[0]: " << trip1.getFirst() << std::endl;
    std::cout << "trip1[0]: " << trip1[0] << std::endl;
    std::cout << "trip2[1]: " << trip2.getSecond() << std::endl;
    std::cout << "trip2[1]: " << trip2[1] << std::endl;

    std::cout << "trip3 - trip2: " << (trip3 - trip2) << std::endl;
    std::cout << "trip1 == trip2? " << (trip1 == trip2) << std::endl;
    std::cout << "++trip1: " << ++trip1 << std::endl << std::endl;
    std::cout << "trip1++: " << trip1++ << std::endl << std::endl;
    std::cout << "trip1 == trip2? " << (trip1 == trip2) << std::endl;
    std::cout << "trip2 == trip3? " << (trip2 == trip3) << std::endl;

    std::cout << "Enter three integers to change the values of trip1.\n";
    std::cin >> trip1;
    std::cout << "trip1: " << (trip1)  << std::endl;
    return 0;
}

Triplet getTriplet()
{
    std::string input("");
    int val1(0), val2(0), val3(0);

    while(true){
        std::cout << "Enter three integers separated by spaces to create a triplet object with the three entered values." << std::endl;

        std::getline(std::cin, input);

//Check that there are two spaces, to make sure there are three inputs
        size_t fst = input.find_first_of(' ');
        size_t snd = input.find_first_of(' ', fst + 1);
        size_t trd = input.find_first_of(' ', snd + 1);

        if((fst != std::string::npos) && (snd != std::string::npos) && (trd == std::string::npos)){

//Valdate input is integer
    bool validate = false;

    for(int n = 0; n < input.length(); n++){
        if(!isdigit(input[n]) && input[n] != ' '){
            validate = false;
            break;
        }
        validate = true;
    }

//Load valid input into variables to pass to Triplet constructor
            std::stringstream input1SS(input.substr(0, fst));
            std::stringstream input2SS(input.substr(fst + 1, snd - fst - 1));
            std::stringstream input3SS(input.substr(snd + 1, input.length() - snd - 1));
            if(validate && (input1SS >> val1) && (input2SS >> val2) && (input3SS >> val3)){
                Triplet trip5(val1, val2, val3);
                return trip5;
            }
        }
        std::cout << "You've entered invalid input;" << std::endl;
    }
}
