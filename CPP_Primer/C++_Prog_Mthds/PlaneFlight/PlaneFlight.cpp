//07/26/14
//Project 6
//
//PlaneFlight.cpp
//Class implementation of PlaneFlight

#include <iostream>
#include "PlaneFlight.h"

PlaneFlight::PlaneFlight() {
     seats = new int[SIZE];
     capacity = SIZE;
	 count = 0;
	                  // initialize all seats to empty
	 for (int num = 0; num < SIZE; num++)
		 seats[num] = 0;
}

PlaneFlight::PlaneFlight(int cap) : capacity(cap)
{
    seats = new int[capacity];
        count = 0;

// initialize all seats to empty
    for (int num = 0; num < SIZE; num++){
        seats[num] = 0;
    }
}

PlaneFlight::PlaneFlight(const PlaneFlight &rightside): count(rightside.count), capacity(rightside.capacity)
{
    seats = new int[capacity];

    for(int n = 0; n < capacity; n++){
        seats[n] = rightside.seats[n];
    }
    *this = rightside;
}

PlaneFlight::~PlaneFlight()
{
    delete [] seats;
}

const PlaneFlight& PlaneFlight::operator=(const PlaneFlight& rightside)
{
//Check for self-assignment
    if(this == &rightside){
        return *this;
    }

//Deallocate memory belonging to this
        delete[] seats;

//Copy the primative value
    count = rightside.count;
    capacity = rightside.capacity;

//Allocate memory to this
    seats = new int[rightside.capacity];

//Check that rightside has a value
    if(rightside.seats){
        for(int n = 0; n < capacity; n++){
            seats[n] = rightside.seats[n];
        }
    }
    else{
        seats = 0;
    }
    return rightside;
}

bool PlaneFlight::isFull() const{
     //Effect:  determines if all plane seats are full
     //Postcondition:  this PlaneFlight objects is unchanged
     //Returns: true if all seats are full, false otherwise

     return count == SIZE;
}

bool PlaneFlight::isEmpty () const{
     //Effect:  determines if all plane seats are empty
     //Postcondition:  this PlaneFlight objects is unchanged
     //Returns: true if all seats are empty, false otherwise

     return count == 0;
}


bool PlaneFlight::seatVacant(int seatNo) const{
     // Effect:  determines if seatNo is an available seat
     // Precondition:   seatNo is a valid seat number
     // Postcondition:  this PlaneFlight object is unchanged 

	  return seats[seatNo] == 0;
}


void PlaneFlight::reserveSeat(int seatNo)  {
     // Effect: reserves the seat numbered seatNo
     // Precondition:  seat number is valid and seat is vacant
     // Postcondition:  seat #seatNo is now filled

	  seats[seatNo] = 1;
	  count++;
}

void PlaneFlight::cancelSeat(int seatNo){
      //Effect: unreserves the seat numbered seatNo
     // Precondition:  seat number is valid and had been reserved
     // Postcondition:  seat #seatNo is now available 

        seats[seatNo] = 0;
	  count--;
}

bool PlaneFlight::validSeatNum(int seatNo)  const  {
     // Effect:  determines if seatNo is a valid number for this plane
     // Postcondition:  this PlaneFlight object is unchanged
     // Returns: true if seatNo is a seat on this plane, false otherwise
   
	  return seatNo >= 0 && seatNo < SIZE;
}

std::ostream& operator<<(std::ostream &out, const PlaneFlight &obj)
{
    out << "Number of reservations : " << obj.count << std::endl;

    for(int n = 0; n < obj.capacity; n++){
        out << "Seat #" << n << " : ";
        out << (!(obj.seatVacant(n)) ? "reserved" : "vacant") << std::endl;
    }
    return out;
}

int JetBlue::seatsLeft() const
{
    int seat_cnt(0);

    for(int n = 0; n < capacity; n++){
        if(seatVacant(n)){
            seat_cnt++;
        }
    }
    return seat_cnt;
}

int JetBlue::furthestFront() const
{
    int seatNo(0);

    for(; seatNo < capacity; seatNo++){
        if(seatVacant(seatNo)){
                return seatNo;
            }
    }
    return seatNo;
}

int JetBlue::furthestRear() const
{
    int seatNo(capacity - 1);

    for(; seatNo >= 0; seatNo--){
        if(seatVacant(seatNo)){
            return seatNo;
        }
    }
    return seatNo;
}
