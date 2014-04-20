//NumberGuesser.cpp
//Interface for NumberGuesser class

#include <iostream>
#include "NumberGuesser.h"

//Constructor definitions

NumberGuesser::NumberGuesser(int lowerBound, int upperBound): low(lowerBound), high(upperBound){}

//Member function definitions

void NumberGuesser::higher()
{
	low = midpoint;
	midpoint = (high + low)/2;
}
void NumberGuesser::lower()
{
	high = midpoint;
	midpoint = (high + low)/2;
}
void NumberGuesser::reset()
{
	low = reset_low;
	high = reset_high; 	
}
unsigned NumberGuesser::getCurrentGuess()
{
        while(choice != 'c'){
                std::cout << "Is it " << midpoint << "? (h/l/c):";
                std::cin >> choice;

		while(choice != 'h' && choice != 'l' && choice != 'c'){
                                std::cout << "Please enter 'h' for higher, 'l' for lower, or 'c' if my guess is correct." << std::endl;
                                std::cin >> choice;
		}
                if(choice == 'h'){
                        higher();
                }
                else if(choice == 'l'){
			lower();                        
                }
		else if(choice == 'c'){
                        std::cout << "You picked " << midpoint << "? Great pick." << std::endl;
		} 
	}
	return midpoint;
}
void playOneGame()
{
	char g_choice(' ');
do{
	char range(' ');
	int high = 0, low = 0;
	std::cout << "Do you want to choose a number between the default range, or set your own range? Enter 'd' to user the default range, or 'u' to specify a unique range." << std::endl;

	std::cin >> range;	

	if(range == 'd'){
		NumberGuesser n_g_game;
		n_g_game.getCurrentGuess();
		n_g_game.reset();
	}
	else if(range == 'u'){
		std::cout << "What numbers would you like to guess between? Enter the lower bound first, followed by the upper bound.\n";
		std::cin >> low >> high;
		while(low < 0 || high < 0 || high <= low){
			std::cout << "Please enter integers greater than or equal to 0, where low < high.\n";
			std::cin >> low >> high;
		}
		
		NumberGuesser n_g_game(low, high);
		n_g_game.getCurrentGuess();
		n_g_game.reset();
	}
	else{
		while(range != 'd' || range != 'u'){
			std::cout << "Please enter 'd' for the default range, or 'u' to choose a unique range.\n";
			std::cin >> range;
			}
	}
	
	std::cout << "Do you want to play again? (y/n): ";
	std::cin >> g_choice;
		
	while(g_choice != 'y' && g_choice != 'n'){
		std::cout << "Please enter 'y' if you want to play again, or 'n' if you're finished playing and want to exit the game." << std::endl;
		std::cin >> g_choice;
                        }
}while(g_choice == 'y');
}
