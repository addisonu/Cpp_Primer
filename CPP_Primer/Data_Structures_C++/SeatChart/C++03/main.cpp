//Project 1 : Part I
//08/29/14
//SeatChart.h
//Unit test for class SeatChart
//NOTE: Seats range from 1 - N

#include <iostream>
#include <exception>
#include <algorithm>
#include "SeatChart.h"

using std::cout;
using std::cin;
using std::getline;
using std::exception;
using std::endl;

int main()
{
cout << "1. Create two SeatChart objects using different constructors" << endl;
SeatChart sc1;
SeatChart sc2(7);

cout << "2. Print out contents of sc1 and sc2" << endl;
cout << "SeatChart #1" << endl;
cout << sc1;
cout << "SeatChart #2" << endl;
cout << sc2;

cout << "3. Test assignment operator on sc1 and sc2" << endl;
sc1 = sc2;
cout << sc2;

cout << "4. Test out copy constructor" << endl;
SeatChart sc3(sc1);
cout << "SeatChart #3" << endl;
cout << sc3;

cout << "5. Test out reserving and unreserving a seat" << endl;
sc1.reserve(0);
cout << sc1;

SeatChartException SeatChartExc;
try{
    sc2.release(0);
    if(!sc2.validSeat(0) || sc2.available(0)){
        throw SeatChartExc;
    }
}
catch(exception &SeatChartExc)
{
    cout << SeatChartExc.what() << endl;
}

cout << "6. Test out available" << endl;
cout << "sc1 seat 0 is available: " << sc1.available(0) << endl;
cout << "sc2 seat 0 is available: " << sc2.available(0) << endl;

cout << "7. Test out isFull" << endl;
for(int n = 0; n < sc3.getMax(); n++){
    sc3.reserve(n);
}
cout << "sc2 is full: " << sc2.isFull() << endl;
cout << "sc3 is full: " << sc3.isFull() << endl;

cout << "8. Test out numTaken" << endl;
cout << "sc2 has number of seats: " << sc2.getMax() << endl;
cout << "sc2 has number of seats taken: " << sc2.numTaken() << endl;
cout << "sc3 has number of seats: " << sc3.getMax() << endl;
cout << "sc3 has number of seats taken: " << sc3.numTaken() << endl;

cout << "9. Test clearAll" << endl;
cout << "sc3 has number of seats taken: " << sc3.numTaken() << endl;
sc3.clearAll();
cout << "sc3 has number of seats taken: " << sc3.numTaken() << endl;
cout << "sc1 = sc3: " << (sc1 == sc3) << endl;
cout << "sc3 = sc2: " << (sc3 == sc2) << endl;

return 0;
}
