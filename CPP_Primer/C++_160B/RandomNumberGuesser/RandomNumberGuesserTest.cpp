//RandomNumberGuesserTest.cpp
//Test RandomNumberGuesser class

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "NumberGuesser.h"
#include "RandomNumberGuesser.h"

void play_game(RandomNumberGuesser game);
int main()

{
	RandomNumberGuesser game(1, 10);
	game.play_game();

	return 0;
}
