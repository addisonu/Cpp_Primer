//07/26/14
//Project 6
//
//PlaneFlight.h
//Class definition of PlaneFlight

#ifndef PLANE_FLIGHT_H
#define PLANE_FLIGHT_H

#include <iostream>

const int SIZE = 10;

class PlaneFlight{

public:
	PlaneFlight();

        PlaneFlight(int cap);
        
        PlaneFlight (const PlaneFlight& obj);
        ~PlaneFlight();
        const PlaneFlight& operator=(const PlaneFlight& rightside);

	bool isFull() const;
    // Effect:  determines if all plane seats are full
    // Postcondition:  this PlaneFlight objects is unchanged
    // Returns: true if all seats are full, false otherwise

  bool isEmpty () const;
    // Effect:  determines if all plane seats are empty
    // Postcondition:  this PlaneFlight objects is unchanged
    // Returns: true if all seats are empty, false otherwise


  bool seatVacant(int seatNo) const;
     // Effect:  determines if seatNo is an available seat
     // Precondition:   seatNo is a valid seat number
     // Postcondition:  this PlaneFlight object is unchanged

    void reserveSeat(int seatNo);
     // Effect: reserves the seat numbered seatNo
     // Precondition:  seat is vacant
     // Postcondition:  seat #seatNo is now filled

    void cancelSeat(int seatNo);
      //Effect: unreserves the seat numbered seatNo
      // Precondition:  seat had been reserved
     // Postcondition:  seat #seatNo is now available

   bool validSeatNum(int seatNo)  const;
      //Effect:  determines if seatNo is a valid number for this plane
      // Postcondition:  this PlaneFlight object is unchanged
      //Returns: true if seatNo is a seat on this plane, false otherwise

private:
	  int* seats;    //plane seats (0- empty, 1 - full)
	  int count;     //number of reservations made
protected:
          int capacity;  //Keeps track of number of seats on the plane
//Friend declarations//
friend std::ostream& operator<<(std::ostream& out, const PlaneFlight &obj);
};

std::ostream& operator<<(std::ostream& out, const PlaneFlight &obj);

class JetBlue : public PlaneFlight{

public:

//Constructors//
    JetBlue() { }

// constructor which initializes a plane with ¿capacity¿ seats
    JetBlue(int cap) : PlaneFlight(cap) { }

//Member functions//

//Effect:  determines the number of empty seats remaining
//Postcondition:  this PlaneFlight object is unchanged
//Returns:  the number of empty seats in the plane
    int seatsLeft() const;

//Effect:  finds the front-most available seat
//Precondition: the plane is not full
//Returns:  the number of the  seat
    int furthestFront() const;

//Effect:  finds the rear-most available seat
//Precondition: the plane is not full
//Returns:  the number of the seat
    int furthestRear() const;

};
#endif
