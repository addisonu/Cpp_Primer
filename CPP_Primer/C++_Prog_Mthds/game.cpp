//Project 2: Part A
//game.cpp
//
//Generates a three digit random number which a user may guess. It will keep track of the number guesses that occur for the user to guess the correct number and output a message based on the number of guesses. The highest and lowest guesses will be printed.

#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <time.h>
#include <climits>

void secretNum(int &answer);
bool checkGuess(int guess, int answer);
void guessResponse(int guess, int answer);
void countResponse(int count);

int main()
{
//Variable to hold number of games
    const int games(10);

//Variables used in the above functions
    int answer(0), count(0), guess(0), lowest(INT_MAX), highest(0);

//The game will repeat 10 times
for(int n = 0; n < games; n++){

//Reset variables for next game
    answer = count = guess = 0;

//string to validate user input
    std::string input("");

//Set secret number for game
    secretNum(answer);

//Continues until user guesses correct answer
    while(!checkGuess(guess, answer)){

//validate user input and make sure cin is emptied
    while(true){

        std::cout << "Guess a number between 100 and 999." << std::endl;

        std::getline(std::cin,input);
        std::stringstream inputSS(input);

        if((inputSS >> guess) && (guess > 99) && (guess < 1000)){
            break;
        }
        std::cout << "You've entered invalid input. Enter an integer between 100 - 999.\n";
    }
        count++;

        if(checkGuess(guess, answer)){

            countResponse(count);
        }
        else{
            guessResponse(guess, answer);
        }
    }

//Track the highest and lowest number of guesses
    lowest = (lowest > count) ? count : lowest;
    highest = (highest < count) ? count : highest;

    if(count == 1){
        std::cout << "You were able to guess the secret number after " << count << " try." << std::endl;
    }
    else{
        std::cout << "You were able to guess the secret number in " << count << " tries." << std::endl;
    }
}
    std::cout << "Highest count of guesses to find the secret number: " << highest << std::endl;
    std::cout << "Lowest count of guesses to find the secret number: " << lowest << std::endl;
    return 0;
}

//Generates a three digit random number
void secretNum(int &answer)
{
    srand(time(NULL));
    answer = rand()%900 + 100;
}

//Will check if user has guessed secret number and return true/false
bool checkGuess(int guess, int answer)
{
    return guess == answer;
}

//Prints message based on how many trys were required for user to guess secret number
void countResponse(int count)
{
    if(count < 10){
        std::cout << "You must know the secret." << std::endl;
    }
    else if(count == 10){
        std::cout << "You got lucky." << std::endl;
    }
    else{
        std::cout << "You should be able to do better than that." << std::endl;
        }
}

//Compares the user input to secret number and prints prompt "Higher" or "Lower"
void guessResponse(int guess, int answer)
{
    if(guess < answer){
        std::cout << "Higher!!" << std::endl;
    }
    else if(guess > answer){
        std::cout << "Lower!!" << std::endl;
    }
}
