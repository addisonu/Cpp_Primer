//Project 2: Part B
//recurse.cpp
//Prompts user for an integer and a digit. It checks if the integer contains the digit. If it does an affirmative message is returned, if not a negative message is returned

#include <iostream>
#include <cmath>
#include <string>
#include <sstream>

bool isThere(int& number, int digit);

int main()
{
//Define variables used by isThere
    int number(0), digit(0);

//Validate user input
    std::string input("");
    bool valid(0);

    while(true){

//Prompt user for an integer followed by prompt for a digit
        std::cout << "Enter a positive integer." << std::endl;
        std::getline(std::cin, input);

//Check to make sure each character in input is a digit
        for(int n = 0; n < input.length(); n++){
            if(!isdigit(input[n])){
                valid = false;
                break;
            }
                valid = true;
        }
        if(valid){
            std::stringstream numSS(input);

            std::cout << "Enter a positive digit." << std::endl;

            std::getline(std::cin, input);
            std::stringstream digSS(input);

            if((numSS >> number) && (number >= 0) && (input.length() == 1) && (digSS >> digit)){
                        break;
                    }
        }
        std::cout << "You've entered invalid input. Re-enter a positive integer and digit.\n" << std::endl;
    }

//Create a variable that can be changed and won't affect the variable holding user's integer
    int tmp_num  = number;

    if(isThere(tmp_num, digit)){
        std::cout << "The digit " << digit << " is in the number " << number << "." << std::endl;
    }
    else{
        std::cout << "The digit " << digit << " is not in the number " << number << "." << std::endl;
    }
    return 0;
}

bool isThere(int& number, int digit)
{

    if(number%10 == digit){
        return true;
    }
    else if(number){
         return isThere((number /= 10), digit);
    }
    else{
        return false;
    }
}

