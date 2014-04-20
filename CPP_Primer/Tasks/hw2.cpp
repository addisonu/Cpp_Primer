#include <iostream>
#include <stdio.h>
#include <time.h>
#include <cstdlib>

int main()
{
	int card(0), card1(0), card2(0);//hold cards
	int hand(0);//hold running total of cards in hand
	char choice('y');//user choice for card or play again

	srand(time(NULL));//Seed rand function

while(choice == 'y'){	
	card1 = rand() % 10 + 1;
	card2 = rand() % 10 + 1;
	hand+= card1 + card2;

	std::cout << "You've been dealt your first two cards, they're " << card1 << " and " << card2
		<< ". Your hand is " << hand << ".\n";	
	do{
		std::cout << "Do you want another card? Enter 'y' for another card, or any other key to finish this game.\n";
		std::cin >> choice;
		
		if(choice == 'y'){
			card = rand() % 10 + 1;
			hand += card;
			std::cout << "Your card is: " << card << "\nYour hand is " << hand << ".\n";
		}
	}while(choice == 'y' && hand < 21); 
	
	if(hand < 21)
		std::cout << "You managed to break even this time :D" << std::endl;
	else if(hand == 21)
		std::cout << "You've won!! Good job" << std::endl;
	else
		std::cout << "BUST :P" << std::endl;
	std::cout << "Do you want to play again?\n";
	std::cin >> choice;
	hand = 0;
}
	return 0;
}
