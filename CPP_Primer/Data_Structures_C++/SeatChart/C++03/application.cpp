//Project 1 : Part II
//08/29/14
//SeatChart.h
//Holds the main application file utilizing the SeatChart class
//NOTE: Seats range from 1 - N


#include <iostream>
#include <exception>
#include <algorithm>
#include "SeatChart.h"

using std::cout;
using std::cin;
using std::endl;
using std::getline;
using std::exception;

int main()
{
//Create SeatChart object manipulate with following menu
    SeatChart sc, sc2;

//Variable to control while loop
    bool choice(0);

    do{
        cout << "Enter the code from the following menu to execute the corresponding action." << endl
            << "0: Reserve a seat" << endl
            << "1: Release a seat" << endl
            << "2: Ask how many seats are currently available" << endl
            << "3: Clear all current reservations" << endl
            << "4: Compare two SeatChart objects for equality" << endl
            << "5: Output all current reservations" << endl;

//Variables for user input
        int num(0);
        unsigned menu(0);

        cin >> menu;
if(menu < 6){
        switch(menu)
        {
        case 0:
            cout << "Enter the seat number you would like to reserve." << endl;
            cin >> num;
            if(sc.validSeat(num) && sc.available(num)){
                sc.reserve(num);
            }
            else{
                cout << "The seat number you have entered is either not valid or already reserved." << endl;
            }
            break;
        case 1:
            cout << "Enter the seat number you would like to release." << endl;
            if(cin >> num)
            {
//Create class exception object
                SeatChartException SeatChartExc;
                try{
                    if(!sc.validSeat(0) || sc.available(0)){
                         throw SeatChartExc;
                     }
                    else{
                        sc.release(0);
                    }
                }
                catch(exception &SeatChartExc)
                {
                    cout << SeatChartExc.what() << endl;
                }
            }
            break;
        case 2:
            cout << "The number of seats currently reserved is: " << (sc.getMax() - sc.numTaken()) << endl;
            break;
        case 3:
            sc.clearAll();
            break;
        case 4:
            cout << "The two SeatChart objects are equal: " << (sc== sc2) << endl;
            break;
        case 5:
            cout << sc;
            break;
    }
}
        cout << "Would you like to continue entering options from the menu? Enter 0 to terminate and 1 to continue." << endl;
        cin >> choice;
    }while(choice);
    return 0;
}
