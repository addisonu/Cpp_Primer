//b_main.cpp
//Test board class

#include <iostream>
#include "point.h"
#include "pointcollection.h"
#include "ship.h"
#include "board.h"

int main()
{
        Board game;
        int x(0), y(0);

//Play a game
        while(game.unsunkShipCount()){
        
              int ships_sailing = game.unsunkShipCount();
              std::cout << "The enemy fleet has " << ships_sailing << " ships remaining." << std::endl;
                
                   for(int n = 0; n < ships_sailing; n++){
                        std::cout << "Enter the x and y coordinates for the shot you want to fire. Enter an integer for x, followed by a single space and the integer for y.\n" << std::endl;
                        std::cin >> x >> y;
                        game.fireShot(x, y);
                  }
              std::cin.clear();
              game.display();
        }
	
        return 0;
}
