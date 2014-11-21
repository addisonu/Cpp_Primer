//ASSIGNMENT: Project 5
//DATE: 10/30/14
//FILE: application.cpp
//DSCR: Application that utilizes the binary tree bag class, provides interface for user to create and use a bag object

#include <iostream>
#include <string>
#include <cstdlib>
#include <map>
#include "bintree.h"
#include "bag6.h"

//Using declarations
using std::cout;
using std::cin;
using std::string;
using std::endl;
using std::getline;

//Define enumerated type to hold menu options
enum  menu {insert, removed, count, add, combine, freq, output, list, null};

int main()
{
//Map to link enum with string representation
std::map<std::string, menu> menu_map;

//Load menu string pairs into map
menu_map["insert"] = insert;
menu_map["removed"] = removed;
menu_map["count"] = count;
menu_map["add"] = add;
menu_map["combine"] = combine ;
menu_map["freq"] = freq;
menu_map["output"] = output ;
menu_map["list"] = list;
menu_map["null"] = null;

//Create bag objects and variables to hold user input
    std::string  input;
    main_savitch_10::bag<int> bag1;

//Hold menu choices
    menu menu_choice = output;

//User can perform actions indefinitely
do{
//Menu of commands
    cout << "\nThe following menu lists the commands this program can execute. To choose a menu option enter the command name in lowercase.\n\n"
        << "INSERT  : insert value into a bag object\n"
        << "REMOVED : remove value from a bag object\n"
        << "COUNT   : output the number of values in a bag object\n"
        << "ADD     : add the contents of one bag object to another bag object\n"
        << "COMBINE : combine a bag object with another to produce a new bag object\n"
        << "FREQ    : output the number of occurrences of a specified value in the bag object\n"
        << "OUTPUT  : output the contents of a bag object in a tree pattern\n"
        << "LIST    : list the contents of a bag object\n\n";
//Read menu selection
        getline(cin, input);
        menu_choice = menu_map[input];

//Switch statement to execute menu_choice
       switch(menu_choice){

//INSERT  : insert value into a bag object
            case insert:
            {
                cout << "Enter the number to add to the bag.\n";
                getline(cin, input);
                bag1.insert(atoi(input.c_str()));
            }
            break;

//REMOVE  : remove value from a bag object
            case removed:
            {
                 cout << "Enter the number to remove from the bag.\n";
                 getline(cin, input);
                 bag1.erase(atoi(input.c_str()));
            }
            break;

//COUNT   : output the number of values in a bag object
            case count:
            {
                cout << "The number of items in the bag is " << bag1.size() << "." << endl;
            }
            break;

//ADD     : add the contents of one bag object to another bag object
            case add:
            {
                cout << "What values would you like to add to the second bag? Separate each value by a space.\n";
                main_savitch_10::bag<int> bag2;
                getline(cin, input);

//Variables to track positions in string
                size_t spos = 0, epos = 0, end = (input.find_last_of(" ") == input.size() - 1) ? input.find_last_of(" ", input.size() - 2) : input.find_last_of(" ");

//Continue until last non-white space character in string
                while(spos < end && epos < end){
                    epos = input.find(" ", spos);
                    bag2.insert(atoi((input.substr(spos, epos - spos)).c_str()));
                    spos = epos + 1;
                }
                    bag2.insert(atoi((input.substr(end)).c_str()));
                bag1 += bag2;
            }
            break;

//COMBINE : combine a bag object with another to produce a new bag object
            case combine:
            {
                cout << "What values would you like to add to the second bag? Separate each value by a space.\n";

                getline(cin, input);
                main_savitch_10::bag<int> bag2;

//Variables to track positions in string
                size_t spos = 0, epos = 0, end = (input.find_last_of(" ") == input.size() - 1) ? input.find_last_of(" ", input.size() - 2) : input.find_last_of(" ");

//Continue until last non-white space character in string
                while(spos < end && epos < end){
                    epos = input.find(" ", spos);
                    bag2.insert(atoi((input.substr(spos, epos - spos)).c_str()));
                    spos = epos + 1;
                }
                bag2.insert(atoi((input.substr(end)).c_str()));

//New bag to hold combined contents of arguments
                main_savitch_10::bag<int> bag3;
                bag3 = bag1 + bag2;
                cout << bag3 << endl;
            }
            break;

//FREQ    : output the number of occurrences of a specified value in the bag object
            case freq:
            {
                cout << "What value would you like to find the frequency of?\n";
                getline(cin, input);
                cout << "The bag has " << bag1.count(atoi(input.c_str())) << " occurrences of the value " << input << "." << endl;
            }
            break;

//PRINT   : output the contents of a bag object in a tree pattern
            case output:
            {
                cout << "Bag contents : \n" <<  bag1 << endl;
            }
            break;

//LIST   : list the contents of a bag object
            case list:
            {
                cout << "Bag contents : \n" << endl;

//Create iterator for bag object and loop control variable
                typename main_savitch_10::bag<int>::iterator it = bag1.begin();
                unsigned i(0);

                while(i != bag1.size()){
                    cout << *(it++) << ", ";
                    ++i;
                }
            }
            break;

//NO SELECTION : user has not entered a selection from menu
            default:
            {
                cout << "Your selection isn't an option from the menu." << endl;
            }
        }
//Prompt user to continue/terminate program
        cout << "Do you want to continue the program? Enter 'n' to terminate the program or 'y' to continue.\n";
        std::getline(cin, input);
    }while(input != "n");
    return 0;
}
