//Project 1 : Part B
//digits.cpp
//
//Separates an integer into its digits and prints the square and cube of each digit on a new line

#include <iostream>
#include <string>
#include <sstream>
#include <cmath>

void digit_powers(int num[]);

int main()
{
//String that will take unformatted user input
    std::string input(""), tmp_input("");

//Variable to test if user input is valid
    bool valid(false);

//Will hold validated user input
    int num_arr[5] = {0, 0, 0, 0, 0};
    int num(0);

//User can input multiple values
    std::cout << "How many numbers would you like to process?" << std::endl;

//Will track how many numbers user will enter
    int requests(0);

//Loop will exit after user enters appropriate number of entries to process
    while(true){
        std::getline(std::cin, input);
        std::cin.clear();
        std::stringstream inputSS(input);

        if((inputSS >> requests) && (requests > 0)){
                break;
        }
        std::cout << "You've entered invalid data. Please enter an integer for the number of entries you would like to process."     << std::endl;
    }

    for(int m = 0; m < requests; m++){

//Prompts user for 5 digit integer
        std::cout << "\nEnter a five digit integer." << std::endl;

//Validate user input
        std::getline(std::cin, input);
        std::cin.clear();
        std::cout << std::endl;

        do{
            std::stringstream inputSS(input);
            if((inputSS >> num) && (num >= 10000) && (num <= 99999)){
                valid = true;

//Load digits into array
                for(int n = 0; n < 5; n++){
                    tmp_input = input.substr(n, 1);
                    std::stringstream inputSS(tmp_input);
                    inputSS >> num_arr[n];
                }
            }
            else{
                valid = false;
                std::cout << "You're entry was invalid. Enter an integer between 10,000 - 99,999." << std::endl;

//Allow user to re-enter integer
                std::getline(std::cin, input);
                std::cin.clear();
                std::cout << std::endl;
            }
        } while(!valid);

//Echo user entry
        std::cout << "You entered " << num << "\n" << std::endl;

        digit_powers(num_arr);
    }
    return 0;
}

void digit_powers(int num[])
{
//Process each element of the array by generatingt the square and cube of each digit ofinteger entered by user

    for(int n = 0; n < 5; n++){
        std::cout << "The digit is " << num[n]
        << ". Its square is " << pow(num[n], 2)
        << ". Its cube is " << pow(num[n], 3)
        << "." << std::endl;
    }
}
