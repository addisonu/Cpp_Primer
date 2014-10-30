//Project 1 : Part I
//08/29/14
//SeatChart.h
//Holds the class definition for SeatChart, a class that can be used to manage plane seats
//NOTE: Seats range from 1 - N

#ifndef SEATCHART_H
#define SEATCHART_H

#include <iostream>
#include <exception>
#include <algorithm>

class SeatChart {

//Private members
    int max_sz;
    bool *seats;

public:

//Constructors and Destructor//

//Default constructor initializes class object w/ 10 empty seats
    SeatChart();

//Initializes class object with max number of seats
    SeatChart(int max);
    SeatChart(const SeatChart &obj);
    ~SeatChart();

//Member functions//

//Assign contents of passed object to this object
    SeatChart& operator=(const SeatChart obj);

//Reserves passed seat number
    void reserve(int num);

//Unreserve seat number if valid num and reserved, else SeatChartException is thrown
    void release(int num);

//Checks if seat num is available and returns true if num is available and false otherwise
    bool available(int num) const;

//Checks if all seats are full, returns true if all seats are full and false otherwise
    bool isFull() const;

//Returns the number of seats in this object
    int getMax() const;

//Returns number of seats in this object that are reserved
    int numTaken() const;

//Empties all seats
    void clearAll();

//Checks if a passed seat number is valid
    bool validSeat(int num) const;

//Checks if two SeatChart objects are equal, returns true if they are equal and false otherwise
    bool operator==(const SeatChart &obj) const;

//Returns string representation of this SeatChart object
    friend std::ostream& operator<<(std::ostream &out, const SeatChart &obj);
    friend void swap(SeatChart &sc1, SeatChart &sc2);
};

class SeatChartException: public std::exception{
    virtual const char *what() const throw()
    {
        return "The seat number entered was invalid or already available";
    }
};
    std::ostream& operator<<(std::ostream &out, const SeatChart &obj);
    void swap(SeatChart &sc1, SeatChart &sc2);
#endif
