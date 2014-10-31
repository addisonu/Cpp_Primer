//RandomNumberGuesser.h
//Derived class of NumberGuesser class
//Makes a guess at user's number by generating a random number in the range

#ifndef RANDOM_NUMBER_GUESSER_H
#define RANDOM_NUMBER_GUESSER_H

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "NumberGuesser.h"

class RandomNumberGuesser : public NumberGuesser {
	private:
	
	int last_low = 0;
	int last_high = 100;
	int guess = 0;

	public:
		
	RandomNumberGuesser(int low, int high) : NumberGuesser(low, high){}
	
//will overide base class' version
	int getCurrentGuess();

//will play a game
	void play_game();
	
};
#endif
