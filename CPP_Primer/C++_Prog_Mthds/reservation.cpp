//Project 3
//reservation.cpp
//
//Keeps track of 25 seats on an airplane. Given a seat number, the program will allow the user to execute a number of commands for the seat:
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
#include <new>
#include <cstring>

bool isFull(bool seats[], int plane_size);
bool isEmpty (bool seats[], int plane_size);
int seatsLeft(bool seats[], int plane_size);
bool validSeatNum(int plane_size, int seatNo);
bool seatVacant(bool seats[], int seatNo);
void reserveSeat(bool seats[], int seatNo);
void cancelSeat(bool seats[],  int seatNo);
int furthestFront(bool seats[], int plane_size);
int furthestRear(bool seats[], int plane_size);
bool getSeatNo(int& value);

int main()
{
//Variables for the above functions
    const int plane_size = 25;
    bool * seats = new (std::nothrow) bool[plane_size];
    int value(0);

// Variable to hold user choice to end or continue program
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

//String to validate user input
    std::string input("");

//Loops until user enters valid input
    while(true){
        std::cout << "Enter a command from the menu.\n";
        std::getline(std::cin, input);
        std::cout << std::endl;
//Checks to make sure input is a number on the menu
        if((input.length() == 1) && (atoi(input.c_str()) >= 0  && atoi(input.c_str()) <= 7)){
            choice = atoi(input.c_str());
            break;
        }
        std::cout << "You've entered invalid input." << std::endl;
    }

//Statement to execute user choice
    switch(choice)
    {
        case 1:
            if(isFull(seats, plane_size)){
                std::cout << "All seats are full." << std::endl;
            }
            else{
                std::cout << "There are empty seats left." << std::endl;
            }
            break;

        case 2:
            if(isEmpty(seats, plane_size)){
                std::cout << "All seats are empty." << std::endl;
            }
            else{
                std::cout << "There are seats that are reserved." << std::endl;
            }
            break;

        case 3:
            getSeatNo(value);

            if(validSeatNum(plane_size, value) && seatVacant(seats, value)){
                reserveSeat(seats, value);

                std::cout << "\nSeat #" << value << " has been reserved." << std::endl;
            }
            else{
                std::cout << "\nNo seat has been reserved." << std::endl;
            }
            break;

        case 4:
            if(!isFull(seats, plane_size)){
                std::cout << "\nThe furthest front seat, seat #" << furthestFront(seats, plane_size)  << " has been reserved." << std::endl;
                reserveSeat(seats, furthestFront(seats, plane_size));
            }
            else{
            std::cout << "\nNo seat has been reserved." << std::endl;
            }
            break;

        case 5:
            if(!isFull(seats, plane_size)){
                std::cout << "\nThe furthest rear seat, seat #" << furthestRear(seats, plane_size) << " has been reserved." << std::endl;
                reserveSeat(seats, furthestRear(seats, plane_size));
            }
            else{
            std::cout << "\nNo seat has been reserved." << std::endl;
            }
            break;

        case 6:
            getSeatNo(value);

            if(validSeatNum(plane_size, value) && !seatVacant(seats, value)){
                cancelSeat(seats, value);

            std::cout << "\nThe seat #" << value << " has been canceled." << std::endl;
            }
            else{
            std::cout << "\nNo seat has been canceled." << std::endl;
            }
            break;

        case 7:
            for(int n = 0; n < plane_size; n++){
                std::cout << "Seat #" << n << " is: "
                << (seats[n] == true ? "reserved" : "empty") << std::endl;
            }
            break;
    }

}
    return 0;
}

bool getSeatNo(int& value)
{

//Input string to validate user entry
    std::string input("");

    std::cout << "Enter a seat number." << std::endl;
    std::getline(std::cin, input);

//Convert input string to c-style string
    char * seatNo = new (std::nothrow) char[input.length()];
    std::strcpy(seatNo, input.c_str());

//Variable to validate input is a number
    bool validate(0);

//Will check if each element of seatNo is a digit
    for(int n = 0; n < input.length(); n++){
        if(!isdigit(seatNo[n])){
            validate = false;
            break;
        }
            validate = true;
    }

//Convert all digit c-style string to integer
    if(validate){
        value = atoi(seatNo);
    }

//Return true if value is a number and false otherwise
    return validate;
}

//Determines the number of empty seats remaining on the plane and returns this number

int seatsLeft(bool seats[], int plane_size){

//Seat counter at function level scope
    int seat_cnt(0);

    for(int n = 0; n < plane_size; n++){
        if(seats[n] == false){
            seat_cnt++;
        }
    }
    return seat_cnt;
}

//Determines if all plane seats are full, returns true if all seats are full, false otherwise

bool isFull(bool seats[], int plane_size)
{
    return seatsLeft(seats, plane_size) == 0;

}

//Determines if all plane seats are empty, returns true if all seats are empty, false otherwise

bool isEmpty (bool seats[], int plane_size)
{
    return seatsLeft(seats, plane_size) == plane_size;
}

//Determines if seatNo is a valid number for this plane, returns true if seatNo is a seat on this plane, false otherwise

bool validSeatNum( int plane_size, int seatNo)
{
    return seatNo < plane_size;
}

//Determines if seatNo is an available seat, returns true if it is available, false otherwise

bool seatVacant(bool seats[], int seatNo)
{
     return !seats[seatNo];
}

//Assuming the preconditions: seat number is valid and seat is vacant, reserves passed seat number

void reserveSeat(bool seats[], int seatNo){

         seats[seatNo] = true;
}

//Assuming the preconditions: seat number is valid and seat is reserved, unreserves the passed seat number

void cancelSeat(bool seats[],  int seatNo)
{
        seats[seatNo] = false;
}

//Finds the front-most available seat, returns the number of the seat

int furthestFront(bool seats[], int plane_size)
{
//Variable at function scope to hold seat number
    int seatNo(-1);

//Checks each seat starting from the front of the plane searching for the first empty seat
    for(int n = 0; n < plane_size; n++){
        if(seats[n] == false){
            seatNo = n;
            break;
        }
    }
    return seatNo;
}

//Finds the rear-most available seat, returns the number of the seat

int furthestRear(bool seats[], int plane_size)
{
//Variable at function scope to hold seat number
    int seatNo(-1);

//Checks each seat starting from the back of the plane searching for the first empty seat
    for(int n = plane_size - 1; n >= 0; n--){
        if(seats[n] == false){
            seatNo = n;
            break;
        }
    }
    return seatNo;
}
