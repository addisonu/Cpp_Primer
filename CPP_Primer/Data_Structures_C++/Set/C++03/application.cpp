//Project 2 : Part I
//09/05/14
//application.cpp
//Application that utilizes the Set class

#include <iostream>
#include <algorithm>
#include <stdexcept>
#include "Set.h"

using std::cout;
using std::endl;
using std::cin;
using std::ostream;

typedef double value_type;
typedef std::size_t size_type;
static const size_type CAPACITY = 15;

int main()
{
//Create two empty sets, set1 and set2, for user to manipulate
Set set1, set2;
for(int i = 0; i < CAPACITY; i++){
    set2.insert(i);
}
//Run program until user terminates
    char choice('n');

    do{
//Variables to hold menu input and value_type objects
        unsigned menu(77);
        value_type val1(0), val2(0);

        cout << "\nEnter the corresponding number from the menu to execute the command. Any values entered to complete a command must be of integral type.\n\n"
        << "0 : Add value to set 1\n"
        << "1 : Add value to set 2\n"
        << "2 : Remove value from set 1\n"
        << "3 : Remove value from set 2\n"
        << "4 : Search for a specific value in set 1 and set 2\n"
        << "5 : Check if set 1 and set 2 are empty\n"
        << "6 : Check if set 1 and set 2 are full\n"
        << "7 : Check if set 1 contains set 2\n"
        << "8 : Take the union of set 1 and set 2\n"
        << "9 : Take the intersection of set 1 and set 2\n"
        << "10 : Assign set 1 to set 2\n"
        << "11 : Compare set 1 and set 2 for equality\n"
        <<  endl;

        cin >> menu;

        switch(menu){
//Add value to set 1
            case 0:
                {
                    cout << "Enter the value you want to insert into set 1.\n";
                    cin >> val1;
                    set1.insert(val1);
                    cout << "set 1 = " << (set1) << endl;
                    cout << "set 2 = " << (set2) << endl;
                }
                break;
//Add value to set 2
            case 1:
                {
                    cout << "Enter the value you want to insert into set 2.\n";
                    cin >> val2;
                    set2.insert(val2);
                    cout << "set 1 = " << (set1) << endl;
                    cout << "set 2 = " << (set2) << endl;
                }
                break;
//Remove value from set 1
            case 2:
                {
                     cout << "Enter the value you want to remove from set 1.\n";
                    cin >> val1;
                    set1.remove(val1);
                    cout << "set 1 = " << (set1) << endl;
                    cout << "set 2 = " << (set2) << endl;
                }
                break;
//Remove value from set 2
            case 3:
                {
                     cout << "Enter the value you want to remove from set 2.\n";
                     cin >> val2;
                     set2.remove(val2);
                     cout << "set 1 = " << (set1) << endl;
                     cout << "set 2 = " << (set2) << endl;
                }
                break;
//Search set 1 and set 2 for a passed value
            case 4:
                {
                     cout << "Enter the value you would like to search set 1 and set 2 for.\n";
                     cin >> val1;
                     if(set1.contains(val1)){
                        cout << "Set 1 contains " << val1 << "." << endl;
                     }
                     else{
                        cout << "Set 1 doesn't contain " << val1 << "." << endl;
                     }
                     if(set2.contains(val1)){
                        cout << "Set 2 contains " << val1 << "." << endl;
                     }
                     else{
                        cout << "Set 2 doesn't contain " << val1 << "." << endl;
                     }
                }
                break;
//Check if set 1 or set 2 is empty
            case 5:
                {
                    if(set1.isEmpty()){
                        cout << "Set 1 is empty." << endl;
                    }
                    else{
                        cout << "Set 1 isn't empty." << endl;
                    }
                    if(set2.isEmpty()){
                        cout << "Set 2 is empty." << endl;
                    }
                    else{
                        cout << "Set 2 isn't empty." << endl;
                    }
                }
                break;
//Check if set 1 or set 2 is full
            case 6:
                {
                    if(set1.isFull()){
                        cout << "Set 1 is full." << endl;
                    }
                    else{
                        cout << "Set 1 isn't full" << endl;
                    }
                    if(set2.isFull()){
                        cout << "Set 2 is full." << endl;
                    }
                    else{
                        cout << "Set 2 isn't full" << endl;
                    }
                }
                break;
//Check if set 2 contains set 1
            case 7:
                {
                    if(set2.subset(set1)){
                     cout << "Set 1 is contained in set 2." << endl;
                    }
                    else{
                        cout << "Set 1 isn't contained in set 2." << endl;
                    }
                }
                break;
//Take the union of set 1 and set 2
            case 8:
                {
                     cout << "Union of set 1 and set 2  = " << (set1.aUnion(set2)) << endl;
                }
                break;
//Take the intersection of set 1 and set 2
            case 9:
                {
                     cout << "Intersection of set 1 and set 2 = " << (set1.intersection(set2)) << endl;
                }
                break;
//Assign set 1 to set 2
            case 10:
                {
                     set2 = set1;
                     cout << "set 1 = " << (set1) << endl;
                     cout << "set 2 = " << (set2) << endl;
                }
                break;
//Compare set 1 and set 2 for equality
            case 11:
                {
                    if(set1 == set2){
                        cout << "Set 1 is equal to set 2." << endl;
                    }
                    else
                    {
                        cout << "Set 1 isn't equal to set 2." << endl;
                    }
                }
                break;
//Print error message
            default:
                {
                    cout << "You've made a selection not on the menu. Enter a choice from the menu." << endl;
                }
        }
        cout << "\nDo you want to continue? Enter 'y' to continue and any other character to terminate the program.\n";
        cin >> choice;

    }while(choice == 'y');

    return 0;
}
