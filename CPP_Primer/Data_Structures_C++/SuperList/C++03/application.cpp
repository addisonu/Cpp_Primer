//Project 3
//10/01/14
//application.cpp
//Allows users to use utilities from SuperList class

#include <iostream>
#include <string>
#include <cstdlib>
#include <cassert>
#include <iterator>
#include <vector>
#include "SuperList.h"
#include "SLexpt.h"

using std::cout;
using std::cin;
using std::getline;
using std::endl;

int main()
{
    SuperList cust, cust2;

//Load data into cust2 object that will be used to test overloaded equality operator
    std::string acust[] = {"S Forman", "J Lippman", "M Brown", "N Uchida", "M Mustafa", "R Wu", "S Davis", "A Addington"};

    std::string *beg = acust;
    std::string *end = acust + 8;

    while(beg != end){
        cust2.insertRear(*beg);
        ++beg;
    }
//Variable that will let user terminate or continue program
    char choice('u');

    do{
        cout
            << "Choose an item from the menu to execute.\n"
            << "\t0 : Add a customer name to the end of list.\n"
            << "\t1 : Add a PRIORITY customer name to the front of list.\n"
            << "\t2 : Print out the list of names.\n"
            << "\t3 : Remove the first customer name from the list.\n"
            << "\t4 : Remove a customer name from the list.\n"
            << "\t5 : Remove the first N customer names from the list, and print them.\n"
            << "\t6 : Print out the name of the first customer on the list.\n"
            << "\t7 : Print out the position of a particular customer.\n"
            << "\t8 : Output a message stating if list is empty.\n"
            << "\t9 : Output the number of names on the list.\n"
            << "\t10 : Output a message stating if two lists are equal or not.\n"
            << endl;

//Variables to manage user selections: input will be used to hold responses to member functions, menu will hold command from menu
        std::string input("");
        size_t menu(-1);

        std::getline(cin, input);
        menu = atoi(input.substr(0, input.find_first_of(" ")).c_str());

        switch(menu)
        {
//Add a customer name to the end of list
            case 0:
                {
                    cout << "What customer name would you like to add to the end of the list?\n";
                    std::getline(cin, input);
                    cust.insertRear(input);
                }
                break;
//Add a PRIORITY customer name to the front of list
            case 1:
                {
                    cout << "What customer name would you like to add to the front of the list?\n";
                    std::getline(cin, input);
                    cust.insertFront(input);
                }
                break;
//Print out the list of names
            case 2:
                {
                    cout << (cust) << endl;
                }
                break;
//Remove the first customer name from the list
            case 3:
                {
                    if(cust.lengthIs()){
                        cust.removeFirst();
                    }
                }
                break;
//Remove a customer name from the list
            case 4:
                {
                    cout << "What customer name would you like to remove from the list?\n";
                    std::getline(cin, input);
                    cust.removeOne(input);
                }
                break;
//Remove the first N customer names from the list, and print them
            case 5:
                {
                    cout << "How many customer names would you like to remove from the list?\n";
                    int N(0);
                    std::getline(cin, input);
                    N = atoi(input.c_str());

                    if(cust.lengthIs() >= N){
                        std::string *result = new std::string[N];
                        cust.removeN(N, result);
                    }
                }
                break;
//Print out the name of the first customer on the list
            case 6:
                {
                    if(cust.lengthIs()){
                        cout << (cust.reportFirst()) << endl;
                    }
                }
                break;
//Print out the position of a particular customer
            case 7:
                {
                    cout << "Which customer name do you want the list position for?\n";
                    std::getline(cin, input);
                    cout << (cust.reportWhere(input)) << endl;
                }
                break;
//Output a message stating if list is empty
            case 8:
                {
                    cout << "The list is" << (cust.isEmpty() ? " empty." : " not empty.") << endl;
                }
                break;
//Output the number of names on the list
            case 9:
            {
                cout << "The number of customers on the list is " << cust.lengthIs() << "." << endl;
            }
                break;
//Output a message stating if two lists are equal or not
            case 10:
            {
                cout << "The two lists customer1 and customer2 are " << ((cust == cust2) ? "equal." : "not equal.") << endl;
            }
                break;
//Catch invalid menu selections
            default:
            {
                cout << "You've entered a value not on the menu.\n" << endl;
                    cin.clear();
                    std::getline(cin, input);
            }
                break;
        }
        cout << "Do you want to continue? To choose another item from the menu enter 'y'. To end the program enter any other character.\n";
        std::getline(cin, input);
        choice = input[0];
    }while(choice == 'y');

    return 0;
}
