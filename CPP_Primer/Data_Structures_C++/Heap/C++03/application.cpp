//DATE: 11/23/14
//ASSIGNMENT: Project 6
//FILE: application.cpp
//DESC: Using classes Heap and Patient schedule the use of operating rooms O1 and O2.

#include <iostream>
#include <string>
#include <algorithm>
#include <stdexcept>
#include "heap.h"
#include "patient.h"

int main()
{
//Priority queues, OR1 and OR2 each for 7 operations slots per day
    Heap<Patient> OR1(7);
    Heap<Patient> OR2(7);

//Variables to hold patient information
    std::string pname, pmalady, spriority;
    int ppriority;

//While loop executes while OR1 and OR2 are not full
    while(!OR1.IsFull() || !OR2.IsFull()){

//Prompt for the next request
        std::cout << "Enter the next patient to be scheduled for an operation. Enter the patient name, malady, and priority. Press return after each piece of information.\n";

//Push patient into queue
        std::getline(std::cin, pname);
        std::getline(std::cin, pmalady);
        std::getline(std::cin, spriority);
        ppriority = atoi(spriority.c_str());

        Patient doe(pname, pmalady, ppriority);

//Push to OR1 if !IsFull() or push to OR2 if OR1 IsFull() and OR2 !IsFull()
        try{
            if(!OR1.IsFull())
                OR1.add(doe);

            else
                OR2.add(doe);
        }
        catch(const fullpq &e){
            std::cerr << e.what() << std::endl;
            break;
        }
    }
//Print out list of patients in OR1
    Patient doe;

    std::cout << "\nPatients scheduled for OR1:\n\n";

    while(!OR1.IsEmpty()){
        OR1.remove(doe);
        std::cout << doe << std::endl;
    }
//Print out list of patients in OR2

    std::cout << "\nPatients scheduled for OR2:\n\n";

    while(!OR2.IsEmpty()){
        OR2.remove(doe);
        std::cout << doe << std::endl;
    }
    return 0;
}
