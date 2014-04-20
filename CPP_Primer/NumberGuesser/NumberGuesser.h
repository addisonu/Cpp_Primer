//NumberGuesser.h
//Class for number guesser game

#ifndef NUMBER_GUESSER_H
#define NUMBER_GUESSER_H 

class NumberGuesser {

//Data members

	char choice = 'y';
	unsigned high = 100;
	unsigned low = 1;
	unsigned reset_high = high;
	unsigned reset_low = low;
	unsigned midpoint = (high + low)/2;
			
public:

//Constructors

	NumberGuesser() = default;
	NumberGuesser(int lowerBound, int upperBound);

//Member functions

	void higher();
	void lower();
	unsigned getCurrentGuess();
	void reset();
//Friend functions

	friend void playOneGame();
};

	void playOneGame();
#endif
