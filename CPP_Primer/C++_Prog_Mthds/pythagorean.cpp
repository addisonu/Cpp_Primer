//Project 1: Part A
//pythagorean.cpp
//
//Accept three integers and determine whether they satisfy the pythagorean thm


#include <iostream>
#include <string>
#include <cmath>
#include <sstream>
#include <algorithm>

bool pythagorean(int num[]);

int main()
{
//hold user input
    int num[3] = {0, 0, 0};

//string used to take raw unvalidated input
    std::string input("");

//Variable to hold user choice to continue or terminate program
    char choice = {0};

//Loop to process three integers from user
   do{

//Will allow user to enter 3 integers
        for(int n = 0; n < 3; n++){

//Will validate user input
        while(true){
            std::cout << "Enter an integer greater than zero." << std::endl;

//Take user input as string and clear flags if cin fails
            std::cin.clear();
            std::getline(std::cin, input);
            std::stringstream inputSS(input);

            if((inputSS >> num[n]) && (num[n] > 0)){
                break;
            }
            std::cout << "You've entered invalid input. Please enter an integer greater than 0." << std::endl;
        }
        std::cout << "You've entered " << num[n] << "." << std::endl;
        }
//Invoke pythagorean function and report outcome to user
        std::cout << "\nThe numbers you entered are ";

        if(pythagorean(num)){
            std::cout << "the sides of a right triangle.\n" << std::endl;
        }
        else{
            std::cout << "not the sides of a right triangle.\n" << std::endl;
        }

        std::cout << "Would you like to enter another set of numbers or exit the program? Enter 'Y' to continue using the program, or 'N' to end the program.\n";

//Validate user input to exit or continue program
        while(true){

             std::cin.clear();
             std::getline(std::cin, input);

             std::cout << std::endl;

             if((input.length() == 1) && (input[0] == 'Y' || input[0] == 'N')){
                choice = input[0];
                break;
             }
             std::cout << "You've entered invalid input. Please enter 'Y' to continue, or 'N' to exit the program.\n" << std::endl;
       }
    } while(choice == 'Y');

    return 0;
}

bool pythagorean(int num[])
{
//Sort numbers so last is greatest
    std::sort(num, num + 3);

    return pow(num[0], 2) + pow(num[1], 2) == pow(num[2], 2);
}
