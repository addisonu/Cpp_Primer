//
//  Board.h
//  Battleship
//

#ifndef Battleship__Board_H
#define Battleship__Board_H

#include <iostream>
#include "point.h"
#include "pointcollection.h"
#include "ship.h"

class Board
{
private:

int e_fleet_sz = 5;
Ship *e_fleet[5];
PointCollection shots;
Ship* generateShipWithLength(int l);

public:

Board();
bool fireShot(int x, int y);
int unsunkShipCount();
void display();
};

#endif
