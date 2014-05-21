//
//  Board.cpp
//  Battleship
//

#include <iostream>
#include "point.h"
#include "pointcollection.h"
#include "ship.h"
#include "Board.h"

Ship* Board::generateShipWithLength(int ship_len)
{
	direction orientation = HORIZONTAL;
	int x_cor(0), y_cor(0), b_hght(10), b_wdth(10);

//Generates the orientation of ship with HORIZONTAL = 0, and VERTICAL = 1
	orientation = (rand()% 2) ? VERTICAL : HORIZONTAL;
	
        if(orientation == HORIZONTAL){
		x_cor = rand()% (b_wdth - ship_len + 1);
		y_cor = rand()% b_hght;
	}
	else if(orientation == VERTICAL){
		x_cor = rand()% b_wdth;
		y_cor = rand()% (b_hght - ship_len + 1);
	}
	
	point origin(x_cor, y_cor);
	Ship *pnt_e_ship = new Ship(origin, orientation, ship_len);

	return pnt_e_ship;
}

Board::Board()
{
//seed rand() for generateShipWithLength(int ship_len)
        srand(time(NULL));

//Array of ship lengths determined by requirements
	int e_ship_len[5] = {5,4,3,3,4};

        Ship *pnt_ship = (Ship*)::operator new(sizeof(Ship));
	
        for(int n = 0; n < e_fleet_sz; n++){

//counter to count ships that overlap with new ship
		int cnt(0);
//new ship generated, will be added to fleet if it doesn't collide with any fleet ships
                pnt_ship = generateShipWithLength(e_ship_len[n]);
		
                for(int m = 0; m < n; m++){
			if(e_fleet[m]->collidesWith(*pnt_ship)){
			      cnt++;
			}
                }
		if(cnt == 0){
                        e_fleet[n] =  pnt_ship;
		}
		else if(cnt != 0){
                      n--;
                }
	}
}

bool Board::fireShot(int x, int y)
{
	point shot(x, y);
//Will allow the shot to be checked for each ship still in enemy fleet
	int shot_num = unsunkShipCount();
//User must enter a unique point
        while(shots.contains(shot)){
            std::cout << "You've already fired at (" << x << ", " << y << "). Enter a new point." << std::endl;
            std::cin >> x >> y;
            shot.setX(x);
            shot.setY(y);
            std::cout << std::endl;
        }
//As soon as a user fires a shot it is recorded in shots whether or not it is a hit
        shots << shot;
//Check whether the shot hits any of the enemy ships
	for(int n = 0; n < shot_num; n++){
		e_fleet[n]->shotFiredAtPoint(shot);
		if(e_fleet[n]->isHitAtPoint(shot)){
			return true;
		}
	}
	return false;
}

int Board::unsunkShipCount()
{
//counter for number of ships currently in e_fleet
	int ships_sailing(0);
//Checks number of points hit for each ship in e_fleet
	for(int n = 0; n < e_fleet_sz; n++){
		if(!e_fleet[n]->isSunk()){
			ships_sailing++;
		}
	}
	return ships_sailing;
}

void Board::display()
{
//Arbitrary dimensions of the "sea". b_hght represents the y-axis range, b_wdth represents the x-axis range
    int b_wdth(10), b_hght(10);

	for(int y = b_hght - 1; y >= 0 ; y--){
                std::cout << y;
		for(int x = 0; x < b_wdth; x++){
                        point x_y(x, y);
			if(shots.contains(x_y) == true){
                                int cnt(0);
				for(int n = 0; n < e_fleet_sz; n++){
					if(e_fleet[n]->isHitAtPoint(x_y)){
					      cnt++;
                                        }
                                }
                                        std::cout << (cnt ? " X " : " ! ");
                        }
			else{
				std::cout << " ~ ";
			}
		}
                std::cout << std::endl;
	}
            std::cout << " ";
            for(int i = 0; i < b_wdth; i++){
                 std::cout << " " << i << " ";
             }
        std::cout << std::endl << std::endl;
}

