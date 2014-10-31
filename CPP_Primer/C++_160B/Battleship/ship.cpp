//
//  Ship.cpp
//  Battleship
//

#include "Ship.h"

//*******************************************************************************************
//Constructor
//*******************************************************************************************

Ship::Ship(point originPoint, direction o, int l) : origin(originPoint), orientation(o), length(l)
{
	for(int n = 0; n < l; n++){
		point p;
		
		if(o == HORIZONTAL){
			p.setX(originPoint.getX() + n);
			p.setY(originPoint.getY());
		}
		else if(o == VERTICAL){
			p.setX(originPoint.getX());
			p.setY(originPoint.getY() + n);
		}
		points << p;
	}
}

//*******************************************************************************************
//Copy constructor
//*******************************************************************************************

Ship::Ship(const Ship &s)
{
	*this = s;
}

//*******************************************************************************************
// Contains Point
//*******************************************************************************************

bool Ship::containsPoint(const point& p) const
{
	
    return points.contains(p);
}

//*******************************************************************************************
// Collides With
//*******************************************************************************************

bool Ship::collidesWith(const Ship& s) const
{
	for(int n = 0; n < s.points.getSize(); n++){
		if(points.contains(s.points[n])){
			return true;
		}
	}
	return false;
}

//*******************************************************************************************
// Shot Fired At Point
//*******************************************************************************************

void Ship::shotFiredAtPoint(const point& p)
{
	if(points.contains(p)){
		hits << p;
	}
}

//*******************************************************************************************
// Is Hit At Point
//*******************************************************************************************

bool Ship::isHitAtPoint(const point& p)
{
    return hits.contains(p);
}

//*******************************************************************************************
// Hit Count
//*******************************************************************************************

int Ship::hitCount() const
{
    return hits.getSize();
}

//*******************************************************************************************
// Operator =
//*******************************************************************************************

const Ship& Ship::operator=(const Ship& s)
{
	length = s.length;
	orientation = s.orientation;
	origin = s.origin;
	points = s.points;
	hits = s.hits;

	return *this;	
}


//*******************************************************************************************
//  Is Sunk
//*******************************************************************************************

bool Ship::isSunk()
{
	return points.getSize() == hits.getSize();	
}
