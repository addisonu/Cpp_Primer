//DATE: 11/28/14
//ASSIGNMENT: Project 7
//FILE: application.cpp
//DESC: Application which can be used by Square Chair Pizza to store Customer info. This application will store all Customer objects in a hash table.

#include <iostream>
#include <string>
#include "table2.h"

int main()
{
//Variables for user input
    std::string choice("n"), name, address;
    unsigned menu(3);
    long phone(0);
    table<Customer> tb;

    do{

//Menu of actions user can choose
        std::cout << "\nThe following options can be selected. Enter the number corresponding to the option you would like to execute.\n\n"
            << "0 : A new Customer can be entered (provide the Customer name, phone number and address)\n"
            << "1 : Retrieve an existing Customer’s record (provide the Customer's phone number)\n"
            << "2 : Delete a Customer (provide the Customer's phone number)\n\n";

//Get user menu choice
        std::getline(std::cin, choice);
        menu = atoi(choice.substr(0, 1).c_str());

        switch(menu){
// case 0 : A new Customer can be entered
            case 0:
                {
//Get arguments for Customer object
                    std::stringstream ss(choice);

                    std::cout << "Enter Customer name\n";
                    std::getline(std::cin, choice);
                    name = choice;

                    std::cout << "Enter Customer address\n";
                    std::getline(std::cin, choice);
                    address = choice;

                    std::cout << "Enter Customer phone\n";
                    std::getline(std::cin, choice);
                    ss << choice;
                    ss >> phone;

                    Customer cst(name, address, phone);
                    tb.insert(cst);
                }
                break;
// case 1 : Retrieve an existing Customer’s record
            case 1:
                {
                    std::cout << "Enter the phone number of the Customer record you would like to retrieve.\n";
                    std::getline(std::cin, choice);
                    std::stringstream ss(choice);
                    ss >> phone;

                    bool found(0);
                    Customer cst;
                    tb.find(phone, found, cst);

                    if(found)
                        std::cout << cst << std::endl;
                    else
                        std::cout << "There is no record for the phone number that you entered." << std::endl;
                }
                break;
// case 2 : Delete a Customer
            case 2:
                {
                    std::cout << "Enter the phone number of the Customer record you would like to delete.\n";
                    std::getline(std::cin, choice);
                    std::stringstream ss(choice);
                    ss >> phone;

                    tb.remove(phone);
                }
                break;
//Catch invalid menu selections
            default:
            {
                std::cout << "You've entered a value not on the menu.\n" << std::endl;
//Clear stdin for next input
                std::cin.clear();
            }
        }
        std::cout << "Would you like to continue the program? Enter 'y' to continue and 'n' to terminate.\n";
        std::getline(std::cin, choice);
    }while(choice == "y");
    return 0;
}
