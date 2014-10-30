//Project 1 : Part I
//08/29/14
//SeatChart.cpp
//Holds the class implementation for SeatChart, a class that can be used to manage plane seats
//NOTE: Seats range from 1 - N

#include <iostream>
#include <exception>
#include <algorithm>
#include "SeatChart.h"

using std::ostream;
using std::cout;
using std::endl;

SeatChart::SeatChart()
{
    max_sz = 10;
    seats = new bool[max_sz];

//Sets all seats to empty
    for(int n = 0; n < max_sz; n++){
        seats[n] = false;
    }
}

SeatChart::SeatChart(int max): max_sz(max)
{
    seats = new bool[max_sz];

//Sets all seats to empty
    for(int n = 0; n < max_sz; n++){
        seats[n] = false;
    }
}

SeatChart& SeatChart::operator=(SeatChart obj)
{
//Check to see if this is the same as the passed object
    swap(*this, obj);
    return *this;
}

SeatChart::SeatChart(const SeatChart &obj)
{
//Memberwise copy
    max_sz = obj.max_sz;
    seats = new bool[obj.max_sz];

//Deep copy passed object array elements into this object
    std::copy(obj.seats, (obj.seats + obj.max_sz), seats);
}

SeatChart::~SeatChart()
{
    delete[] seats;
}

void SeatChart::reserve(int num)
{
    seats[num] = true;
}

void SeatChart::release(int num)
{
    if(validSeat(num) && seats[num] == true){
        seats[num] = false;
    }
}

bool SeatChart::available(int num) const
{
    return !seats[num];
}

bool SeatChart::isFull() const
{
//Checks which seats are empty
    for(int n = 0; n < max_sz; n++){
        if(seats[n] == false){
            return false;
        }
    }
    return true;
}

int SeatChart::getMax() const
{
    return max_sz;
}

int SeatChart::numTaken() const
{
//Counter for the number of reserved seats
    int cnt(0);

//Iterate through all seats counting those that are reserved
    for(int n = 0; n < max_sz; n++){
        if(seats[n] == true){
            cnt++;
        }
    }
    return cnt;
}

void SeatChart::clearAll()
{
//Set all seats to empty
    for(int n = 0; n < max_sz; n++){
        if(seats[n] != false){
            seats[n] = false;
        }
    }
}

bool SeatChart::validSeat(int num) const
{
    return (num >= 0) && (num < max_sz);
}

bool SeatChart::operator==(const SeatChart &obj) const
{
//Check if this object is the same as passed object
    if(this == &obj){
        return true;
    }

//Check if elements of this and passed object are the same
    if(max_sz == obj.max_sz){
        for(int n = 0; n < max_sz; n++){
            if(seats[n] != obj.seats[n]){
                return false;
            }
        }
    }
    return true;
}

ostream& operator<<(ostream &out, const SeatChart &obj)
{
    for(int n = 0; n < obj.max_sz; n++){
        cout << obj.seats[n] << endl;
    }
    return out;
}

inline
void swap(SeatChart &sc1, SeatChart &sc2)
{
    using std::swap;
    swap(sc1.max_sz, sc2.max_sz);
    swap(sc1.seats, sc2.seats);
}
