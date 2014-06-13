//
//  Board.h
//  Battleship
//

#ifndef Battleship__Board_H
#define Battleship__Board_H

#include <iostream>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "point.h"
#include "pointcollection.h"
#include "ship.h"

class Board
{
private:

//Starting number of ships in all fleets

int fleet_sz = 1;

//X and y upper limits for "sea" dimensions

int b_wdth = 10, b_hght = 10;

//User fleet

Ship *u_fleet[1];

//Enemy fleet

Ship *e_fleet[1];

//All shots fired

PointCollection shots;

//Generates a ship with random dimensions and position

Ship* generateShipWithLength(int l);

public:

Board();

//Method to fire a shot at enemy or user fleet and takes arguments:
//x and y coordinates of point in grid
//fleet - fleet of ships to fire at

bool fireShot(int x, int y, Ship *fleet[]);

//Returns number of ships that haven't been sunk in a fleet

int unsunkShipCount(Ship *fleet[]);

//Displays the "sea" with shots fired and user ships 

void display();

//This method checks to see if a new ship intersects with any ships in a fleet and takes arguments:
//Current ship - an index of a ship in a fleet
//pnt_ship - the new ship, who's position will be compared to the current ship
//fleet - the fleet of ships who's positions are being compared to the new ship

bool fleet_collides(int current_ship, Ship *pnt_ship, Ship *fleet[]);

//Will initiate a single game of battleship

void game();
};

#endif
