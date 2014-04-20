/*
*Algorithm for number picker:

*Requirements:

*Create functions:
	- void playOne Game() - will complete guessing game
	- boolean shouldPlayAgain(char choice) - prompt user to play again, read in character, return true if 'y' and false otherwise
	- char getUserResponseToGuess(int guess) - prompt user with phrase "is it <guess>? (h/l/c): ", it should return a char = h, l, or, c
	- int getMidpoint(int low, int high) - accepts two integers and returns their midpoint, if the middle is two integers, choose the lowest

*Flow: 
*- Prompt user for int input from 1 - 100, (no input required)
*- Begin loop to hold getUserResponseToGuess()
	- Call function getUserResponseToGuess()
		- prompt user with "is it <guess>? (h/l/c): ",
			- to get the value for <guess> call getMidpoint() function
				- will return the midpoint based on input from program
		- take user input in the form of char = l, h, or, c
		- if h or l, call getMidpoint(), else end loop and call boolean shouldPlayAgain()
			- shouldPlayAgain() will print Great! Do you want to play again? (y/n): and will take a char input from user, if input = 'y' will return true, if != 'y' will return false
				- if return true, restart loop else end program

*Functions:
*- void playOne Game() - 
	- bout "Guess a number between 1 and 100
	- int high(100), low(1)
	- begin loop
		- call getMidpoint()
		- call getUserResponseToGuess()

*- boolean shouldPlayAgain(char choice) - 
	- cout prompt "Great! Do you want to play again? (y/n)
	- cin char 'y' or other
		- if 'y' --> return true
		- if ! 'y' --> return false
		
*- char getUserResponseToGuess(int guess) -
	- cout "Is it <guess>? (h/l/c):
	- cin char h, l, or, c
		- if l --> high = guess
			- call getMidpoint()
		- else if h --> low = guess
			- call getMidpoint()
		- else c, call shouldPlayAgain()

*- int getMidpoint(int low, int high) - 
	- initialize int low = 1 and int high = 100
	- compute midpoint = (high + low)/2, use integer division i.e. truncate
	- return int guess = midpoint

*/
#include <iostream>

void playOneGame();
bool shouldPlayAgain();
char getUserResponseToGuess(int guess);
int getMidpoint(int low, int high);

int main()
{
	playOneGame();
	
	return 0;	
}

void playOneGame(){
	int high(100), low(1);

        do{
                getUserResponseToGuess(getMidpoint(low, high));
        }while(shouldPlayAgain());
}

bool shouldPlayAgain(){
	bool play(false);
	char choice(' ');

	std::cout << "Great!! Do you want to play again? (y/n):";
	std::cin >> choice;
		if(choice == 'y'){
			play = true;
		}
		else{
			play = false;
		}
	return play;
}

char getUserResponseToGuess(int guess){
	char hint(' ');
	int high(100), low(1);
	while(hint != 'c'){
		std::cout << "Is it " << guess << " ? (h/l/c):";
		std::cin >> hint;
		if(hint == 'l'){
			high = guess;
			guess = getMidpoint(low, high);	
		}
		else if(hint == 'h'){
			low = guess;
			guess = getMidpoint(low, high);
		}
	}
	return hint;
}
int getMidpoint(int low, int high){
	int midpoint(0);
	midpoint = (high + low)/2;

	return midpoint;
}	
