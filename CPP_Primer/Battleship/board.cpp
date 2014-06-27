//
//  Board.cpp
//  Battleship
//

#include <iostream>
#include <string>
#include <sstream>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "point.h"
#include "pointcollection.h"
#include "ship.h"
#include "Board.h"

Ship* Board::generateShipWithLength(int ship_len)
{
	direction orientation = HORIZONTAL;
	int x_cor(0), y_cor(0);

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
//Greet user
        std::cout << "\n\t\t\t\t\t\t!! Welcome to battleship (~_~) !!\n" << std::endl;

//seed rand() for generateShipWithLength(int ship_len)
        srand(time(NULL));
        Ship *pnt_ship = (Ship*)::operator new(sizeof(Ship));

//Generate user fleet with specified ships in specified locations

        std::cout << "It's time to create your fleet. You will need to deploy " << fleet_sz << " ships."  << std::endl;
        for(int u = 0; u < fleet_sz; u++){

            std::cout << "What is the origin point for ship #" << u << "? Enter an integer for the x coordinate followed by an integer for the y coordinate." << std::endl;

            int u_x(0), u_y(0), u_len(0);
            char u_choice(0);
            direction u_orient;

//Generic variables to get input with getline function
           std::string input = "";

           while(true){
               std::getline(std::cin, input);
               std::cin.clear();
               std::string inputx = input.substr(0, 1);
               std::string inputy = input.substr(2, 1);

//Streams to validate user input for ship coordinates
               std::stringstream xSS(inputx);
               std::stringstream ySS(inputy);
   
               if((xSS >> u_x) && (ySS >> u_y) && (u_x >= 0 && u_x < b_wdth) && (u_y >= 0 && u_y < b_hght)){
                   break;
               }
               std::cout << "You've entered invalid values for x and y. Re-enter the x and y cooridates for your ship's position, by entering an integer for the x coordinate followed by an integer for the y coordinate." << std::endl;
          }
            point u_origin(u_x, u_y);
    
            std::cout << "What is the orientation for your ship? Enter 'h' for horizontal and 'v' for vertical.\n";

    while(true){

        std::getline(std::cin, input);
        std::cin.clear();
        u_choice = input[0];

        if(u_choice == 'h' || u_choice == 'v'){
            break;
        }
        std::cout << "You've entered an invalid value for your ship's orientation. Enter 'h' for horizontal and 'v' for vertical." << std::endl;
        }
            u_orient = (u_choice == 'h') ? HORIZONTAL : VERTICAL;

            std::cout << "What is the length of your ship? Enter an integer from 1 to 5\n";

        while(true){
         
            std::getline(std::cin, input);
            std::cin.clear();

//Stream to validate user input for ship length
            std::stringstream lenSS(input);
            if(lenSS >> u_len && (u_len < 6) && (u_len > 0)){
                break;
            }
                std::cout << "You've entered a ship length that is not in the range 1 - 5. Please re-enter a ship length within the specified range.\n";
        }
            pnt_ship = new Ship(u_origin, u_orient, u_len);

//Check to see if new user ship collides with any ship currently deployed in user fleet
            if(!fleet_collides(u, pnt_ship, u_fleet)){
                u_fleet[u] =  pnt_ship;
            }
            else{
                std::cout << "The ship you've tried to deploy collides with one or more ships already in your fleet. Enter new information for your ship." << std::endl;
                u--;
            }
        }

//Generate enemy fleet w/ random ships randomly placed

//Array of ship lengths determined by requirements
	int e_ship_len[5] = {5,4,3,3,2};

        for(int n = 0; n < fleet_sz; n++){

//new ship generated, will be added to fleet if it doesn't collide with any fleet ships
                pnt_ship = generateShipWithLength(e_ship_len[n]);

                if(!fleet_collides(n, pnt_ship, u_fleet)){
                    if(!fleet_collides(n, pnt_ship, e_fleet)){
                         e_fleet[n] =  pnt_ship;
                    }
                    else{
                        n--;
                    }
                }
                else{
                    n--;
                }
	}
        display();
}

bool Board::fireShot(int x, int y, Ship *fleet[])
{
//Creates a point object, in the invent that the user needs to re-enter a point after the function has been invoked
	point shot(x, y);

//Will fire a shot and check if the shot hit any sailing ship in enemy fleet
//User must enter a unique point
        while(shots.contains(shot)){
            if(fleet == e_fleet){
            std::cout << "(" << x << ", " << y << ") has already been fired at. Enter a new point.\n";
            
//Generic variables to validate user input
            std::string input = "";

            while(true){
                    
                std::getline(std::cin, input);
                std::cin.clear();

                std::string inputx = input.substr(0, 1);
                std::string inputy = input.substr(input.find_first_of(" "), 1);

                std::stringstream xSS(inputx);
                std::stringstream ySS(inputy);

                if((xSS >> x) && (ySS >> y) && (x >= 0 && x < b_wdth) && (y >= 0 && y < b_hght)){
                    shot.setX(x);
                    shot.setY(y);

                    break;
                }
                std::cout << "Your shot is outside of the battle region. Choose an x coordinate between 0 and " << b_wdth << " . And a y coordinate between 0 and " << b_hght << " ." << std::endl;
            }
        }
            else{
                shot.setX(rand()%10);
                shot.setY(rand()%10);
            }
            std::cout << std::endl;
        }
//As soon as a user fires a shot it is recorded in shots whether or not it is a hit
        shots << shot;
//Check whether the shot hits any of the enemy ships
	for(int n = 0; n < fleet_sz; n++){
        if(!fleet[n]->isSunk()){
		fleet[n]->shotFiredAtPoint(shot);
		if(fleet[n]->isHitAtPoint(shot)){
			return true;
		}
        }
	}
	return false;
}

int Board::unsunkShipCount(Ship *fleet[])
{
//counter for number of ships currently in fleet
	int ships_sailing(0);
//Checks number of points hit for each ship in fleet
	for(int n = 0; n < fleet_sz; n++){
		if(!fleet[n]->isSunk()){
			ships_sailing++;
		}
	}
	return ships_sailing;
}

void Board::display()
{
//Arbitrary dimensions of the "sea". b_hght represents the y-axis range, b_wdth represents the x-axis range
   // int b_wdth(10), b_hght(10);

	for(int y = b_hght - 1; y >= 0 ; y--){
//This statement will print y-axis values the length of the left side of the grid
                std::cout << y;
		for(int x = 0; x < b_wdth; x++){
                        point x_y(x, y);
//Check if a point has been fired at, to filter to only points that shots were fired at and ships have been hit at
			if(shots.contains(x_y) == true){
//A counter for the enemy fleet and user fleet, can be used to count anything for respective fleet
                                int e_cnt(0), u_cnt(0);
				for(int n = 0; n < fleet_sz; n++){
					if(e_fleet[n]->isHitAtPoint(x_y)){
					      e_cnt++;
                                        }
                                        if(u_fleet[n]->isHitAtPoint(x_y)){
                                              u_cnt++;
                                        }
                                }
//"X" will denote a successful hit on an enemy ship, "U" will denote a successful hit on an user ship
//"!" represents a shot that didn't hit a ship
                                if(e_cnt != 0){std::cout << " X ";}
                                else if (u_cnt != 0){std::cout << " U ";}
                                else{std::cout <<  " ! ";}
                        }
			else{
//Counter that will be used to display points of a user ship
                            int dsply_cnt(0);
                            for(int m = 0; m < fleet_sz; m++){
                                if(u_fleet[m]->containsPoint(x_y)){
                                    dsply_cnt++;
                                }
                            }
//"@" denotes a point of a user ship and "~" represents a point that hasn't been fired at
                            std::cout << ((dsply_cnt == 1) ? " @ " : " ~ ");
			}
		}
                std::cout << std::endl;
	}
//This code will print x-axis values along the length of the bottom of the grid
            std::cout << " ";
            for(int i = 0; i < b_wdth; i++){
                 std::cout << " " << i << " ";
             }
        std::cout << '\n' << std::endl;
}

bool Board::fleet_collides(int current_ship, Ship *pnt_ship, Ship *fleet[])
{
//Increments each time an intersection is found between the two ships being compared
    int cnt(0);

//Compares the points in a given ship to the points of each ship in a fleet
    for(int m = 0; m < current_ship; m++){
        if(fleet[m]->collidesWith(*pnt_ship)){
            cnt++;
        }
    }
//If the given ship has no points in common with any of the ships in the fleet, it is added to the fleet
    if(cnt == 0){
        return false;
    }
    return true;
}

void Board::game()
{
//Plays the game as long as the user has ships remaining
    int u_ships_sailing;
    int e_ships_sailing;

    while((u_ships_sailing = unsunkShipCount(u_fleet)) && (e_ships_sailing = unsunkShipCount(e_fleet))){

//Calculates the number of ships the enemy fleet has remaining
        int e_ships_sailing = unsunkShipCount(e_fleet);
        std::cout << "The enemy fleet has " << e_ships_sailing << " ships remaining." << std::endl;

//Allows the user to fire a shot from each ship in the their fleet
        int x(0), y(0);
        point fired(0, 0);
        bool misfire(0);

        for(int n = 0; n < u_ships_sailing; n++){
            std::cout << "Enter the x and y coordinates for the shot you want to fire. Enter an integer for x, followed by a single space and the integer for y.\n" << std::endl;

//Generic variables to validate user input
            std::string input = "";

            while(true){
            
                std::getline(std::cin, input);
                std::cin.clear();

                std::string inputx = input.substr(0, 1);
                std::string inputy = input.substr(input.find_first_of(" "), 1);

                std::stringstream xSS(inputx);
                std::stringstream ySS(inputy);

                    if((xSS >> x) && (ySS >> y) && (x >= 0 && x < b_wdth) && (y >= 0 && y < b_hght)){
                        break;
                    }
                std::cout << "You've entered invalid values for x and y. Re-enter the x and y cooridates for your ship's position, by entering an integer for the x coordinate followed by an integer for the y coordinate." << std::endl;
            }
        }
//Checks if user has fired at a ship in their own fleet
            fired.setX(x);
            fired.setY(y);
            int cnt(0);
            misfire = 0;

            do {
            for(int s = 0; s < fleet_sz; s++){
                if(u_fleet[s]->containsPoint(fired)){
                    cnt++;
                }
            }
                if(cnt == 1){
                    misfire = true;

                    std::cout << "You've fired at your own fleet, mate!! Fire at the enemy!! Enter a new shot.\n";
                    
//Generic variables to validate user input 
                std::string input = "";

                while(true){
                    std::getline(std::cin, input);
                    std::cin.clear();

                    std::string inputx = input.substr(0, 1);
                    std::string inputy = input.substr(input.find_first_of(" "), 1);

                    std::stringstream xSS(inputx);
                    std::stringstream ySS(inputy);

                    if((xSS >> x) && (ySS >> y) && (x >= 0 && x < b_wdth) && (y >= 0 && y < b_hght)){
                    break;
                    }
                }
                    fired.setX(x);
                    fired.setY(y);
                }
                else{
                    misfire = false;
                }
                cnt = 0;

            } while(misfire);

            fireShot(x, y, e_fleet);

//Clears the stream if user accidentally enters more shots than the number of ships remaining in their fleet
                std::cin.clear();
                std::cin.ignore(1000, EOF);
//Update number of ships in enemy fleet after a round of shots fired by user
        e_ships_sailing = unsunkShipCount(e_fleet);

        for(int m = 0; m < e_ships_sailing; m++){
            std::cout << "The enemy's preparing to fire!! Get DOWN!!!\n" << std::endl;

//Generate random point for enemy fleet to shoot at
            fired.setX(x = rand()%10);
            fired.setY(y = rand()%10);
            misfire = 0;
            int cnt(0);

//Prevent enemy from firing at own fleet
            do {
                for(int s = 0; s < fleet_sz; s++){
                    if(e_fleet[s]->containsPoint(fired)){
                        cnt++;
                    }
                }
                if(cnt == 1){
                    misfire = true;

                    fired.setX(x = rand()%10);
                    fired.setY(y = rand()%10);
                }
                else if(cnt == 0){
                        misfire = false;
                }
                cnt = 0;

            } while(misfire);

            fireShot(x, y, u_fleet);
        }
//Will display the "sea" after the round of shots fired in the above code
        display();
    }
    std::cout << "Great game mate!! " << ((u_ships_sailing) ? "You've won!! Your obviously El Capitan ;)" : "You lost. How convenient. I needed a couple of deck swabbers.") << std::endl;
}
