//RandomNumberGuesser.cpp
//Implementation of derived class RandomNumberGuesser

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "RandomNumberGuesser.h"
#include "NumberGuesser.h"

int RandomNumberGuesser::getCurrentGuess()
{
	srand(time(NULL));
	
	if(last_low != low || last_high != high){	
		
		guess = (rand() % (high - low + 1)) + low;
		last_low = low;
		last_high = high;
	}
	return guess;
}

 void RandomNumberGuesser::play_game()
{
        char choice('y');
        
	while(choice != 'q'){ 

		std::cout << getCurrentGuess() << std::endl;
		std::cout << "Is the guess correct? Enter l/h/c\n";
	    	std::cin >> choice;
	
			if(guess == high && choice == 'h'){
				while(choice != 'l' && choice != 'c'){
					std::cout << "Sorry, your choice will put the next guess out of your current range. Please choose c for correct or l for lower.\n"; 
					std::cin >> choice;
				}   
                	}   
			else if(guess == low && choice == 'l'){
				while(choice != 'h' && choice != 'c'){
					std::cout << "Sorry, your choice will put the next guess out of your current range. Please choose c for correct or h for higher.\n";
					std::cin >> choice;
				}   
			}
			if(high == low){
				std::cout << "I guessed it!! Good game. Do you want to continue playing? Enter y to continue, and q to quit.\n";
                                std::cin >> choice;
                                if(choice == 'y'){
                                        reset();
					last_high = high + 1;
                                        std::cout << "OK, let's start a new game." << std::endl;
				}
			}  
			if(choice == 'h'){ 
				higher();
			}   
			else if(choice == 'l'){
				lower();
			}   
			else if(choice == 'c'){
				std::cout << "Thank you kindly. Do you want to continue playing? Enter y to continue, and q to quit.\n";
				std::cin >> choice;
				if(choice == 'y'){
					reset();
					last_high = high +1;
					std::cout << "OK, let's start a new game." << std::endl;
				}           
			}   
        		else if(choice != 'y' && choice != 'q'){
				std::cout << "Do you want to continue playing? Enter y to continue, and q to quit.\n";
				std::cin >> choice;
				if(choice == 'y'){
					reset();
					last_high = high + 1;
					std::cout << "OK, let's start a new game." << std::endl;
				}
			}
        		   
	}
}
