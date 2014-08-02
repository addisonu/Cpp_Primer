//07/26/14
//Project 6
//
//application
//Keeps track of SIZE number of seats on an airplane. Given a seat number, the program will allow the user to execute a number of commands for the seat and create a JetBlue reservation:
//
//* check if all seats are full
//* check if all seats are empty
//* reserve a particular seat by number, if available*
//* reserve a seat furthest to the front
//* reserve a seat furthest to the rear
//* cancel a particular seat reservation*
//* print out all information on all seats
//
//NOTE: Reserved seat is true, empty seat is false

#include <iostream>
#include <cctype>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include "PlaneFlight.h"

int validate_num();

int main()
{
//Create JetBlue instance

int size(0);

while(true){
    std::cout << "Enter the size for JetBlue." << std::endl;
    size = validate_num();
    if(size > 0){
        break;
    }
    std::cout << "Enter an integer greater than 0." << std::endl;
}
    JetBlue res(size);

//Variable to hold seatNo
    int value(0);

//Variable to hold user choice to end or continue program
    int choice(-1);

//Will continue while user wants to enter commands
while(choice != 0){

//Menu of options user can select with corresponding number

    std::cout << std::endl <<
"0  : To quit enter 0\n"
"1  : Check if all seats are full\n"
"2  : Check if all seats are empty\n"
"3  : Reserve a particular seat by number, if available*\n"
"4  : Reserve a seat furthest to the front\n"
"5  : Reserve a seat furthest to the rear\n"
"6  : Cancel a particular seat reservation\n"
"7  : Print out all information on all seats\n"
    << std::endl;

while(true){
    choice = validate_num();
    if(choice >= 0 && choice < 8){
        break;
    }
    std::cout << "You've entered invalid input." << std::endl;
}

//Statement to execute user choice
    switch(choice)
    {
        case 1:
            if(res.isFull()){
                std::cout << "All seats are full." << std::endl;
            }
            else{
                std::cout << "There are empty seats left." << std::endl;
            }
            break;

        case 2:
            if(res.isEmpty()){
                std::cout << "All seats are empty." << std::endl;
            }
            else{
                std::cout << "There are seats that are reserved." << std::endl;
            }
            break;

        case 3:
            value = validate_num();
            while(!(res.validSeatNum(value) && res.seatVacant(value))){

                std::cout << "You've entered invalide input. Either the entered seatNo doesn't exist or the seat is already reserved." << std::endl;
                value = validate_num();
            }
            res.reserveSeat(value);
                std::cout << "\nSeat #" << value << " has been reserved." << std::endl;

            break;

        case 4:
            if(!res.isFull()){
                value = validate_num();
                while(!res.validSeatNum(value)){
                    std::cout << "You've entered an invalid seatNo." << std::endl;
                    value = validate_num();
                }
                std::cout << "\nThe furthest front seat, seat #" << res.furthestFront()  << " has been reserved." << std::endl;

                res.reserveSeat(res.furthestFront());
            }
            else{
            std::cout << "\nThe plane is full, no seat has been reserved." << std::endl;
            }
            break;

        case 5:
            if(!res.isFull()){
                value = validate_num();
                while(true){
                    if(res.validSeatNum(value)){
                        std::cout << "\nThe furthest rear seat, seat #" << res.furthestRear() << " has been reserved." << std::endl;
                        res.reserveSeat(res.furthestRear());
                        break;
                    }
                    std::cout << "You've entered invalid input." << std::endl;
                    value = validate_num();
                
                    }
            }
            else{
                std::cout << "\nThe plane is full, no seat has been reserved." << std::endl;
            }
            break;

        case 6:
            
            if(!res.isEmpty()){
                value = validate_num();
                while(!res.validSeatNum(value) || res.seatVacant(value)){

                    std::cout << "You've entered an invalid seatNo, enter another number. Either the seat you've entered doesn't exist, or it hasn't been reserved.";
                    value = validate_num();
                }
            
                res.cancelSeat(value);
                std::cout << "\nThe seat #" << value << " has been canceled." << std::endl;
            }
            else{
                std::cout << "The plane is empty, there are no reservations to cancel." << std::endl;
            }
           break;

        case 7:
           std::cout << res;
           break;
    }
}
    return 0;
}

int validate_num()
{
//Var to validate input
    std::string input(" ");
    int num_input(0);

    while(true){
        std::cout << "Enter an integer to be validated." << std::endl;
        std::getline(std::cin, input);

//Check if input contains only digits
        bool validate(0);

        for(int n = 0; n < input.length(); n++){
            if(!isdigit(input[n])){
                validate = false;
                break;
            }
            validate = true;
        }
        std::stringstream numSS(input);

        if(validate && (numSS >> num_input)){
            break;
        }
        std::cout << "You've entered invalid input." << std::endl;
}
    return num_input;
}
