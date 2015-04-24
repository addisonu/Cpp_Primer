//Schaums ch3 problems
//LEFT OFF : Complete
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <time.h>

int get_sum(int val);
int main()
{
//3.1 - Modify program so that it prints a response only if n is divisble by d.
    int n(0), d(0);
    std::cout << "Enter two positive integers : " ;
    std::cin >> n >> d;
    if(!(n%d)){
        std::cout << n << " is divisible by " << d << std::endl;
    }

//3.2 - Print a minimum of 4 integers
    int n1(0), n2(0), n3(0), n4(0);
    std::cout << "Enter four integers : ";
    std::cin >> n1 >> n2 >> n3 >> n4;
    int min = n1;
    if(n2 < min)
        min = n2;
    if(n3 < min)
        min = n3;
    if(n4 < min)
        min = n4;
    std::cout << "Their minimum is " << min << std::endl;

//3.3 - Print the median of three input integers
    int tmp(0), val1(0), val2(0), val3(0);
    std::cout << "Enter three integers.\n";
    std::cin >> val1 >> val2 >> val3;

    if(val1 > val2){
        tmp = val1;
        val1 = val2;
        val2 = tmp;
    }
    if(val1 > val3){
        tmp = val1;
        val1 = val3;
        val3 = tmp;
    }
    if(val2 > val3){
        tmp = val2;
        val2 = val3;
        val3 = tmp;
    }
    std::cout << "The median value is " << val2 << std::endl;

//3.4 - Reorganize ex 3.6 to create the same effect without using a statement block
    int x, y, temp;
    std::cout << "Enter two integers : ";
    std::cin >> x >> y;
    if(x > y)
        temp = x;
    if(x > y)
        x = y;
    if(temp > x)
        y = temp;
    std::cout << x << " <= " << y << std::endl;

//3.5 - Predict the output from the program in ex 3.7 after removing the declaration on the fifth line of the program. Then run that modified program to check your predicition
    int n = 44;
    std::cout << "n = " << n << std::endl;
    {
        int n;
        std::cout << "Enter an integer: ";
        //std::cin >> n;
        std::cout << "n = " << n << std::endl;
    }
    {std::cout << "n = " << n << std::endl;
    }
    {int n;
        std::cout << "n = " << n << std::endl;
    }
    std::cout << "n = " << n << std::endl;

//3.6 - Write a program that reads the user's age and then prints "You are a child." if the age < 18, "You are an adult." if 18 <= age <= 65, and "Your are a senior citizen." if age >= 65.
    int age(0);
    std::cout << "Enter your age.\n";
    std::cin >> age;

    if(age < 18)
        std::cout << "You are a child." << std::endl;
    else if (age >= 18 && age < 65)
        std::cout << "You are an adult." << std::endl;
    else
        std::cout << "You are a senior citizen." << std::endl;

//3.7 - Write a program that reads two integers and then uses the conditional expression operator to print either "multiple" or "not" according to whether one of the integers is a multiple of the other
        int fact1(0), fact2(0);
        std::cout << "Enter two integers.\n";
        std::cin >> fact1 >> fact2;

        std::cout << ((fact1 % fact2 == 0) || (fact2 % fact1 == 0) ? "multiple" : "not") << std::endl;

//Write and run a program that simulates a simple calculator. It reads two integers and a character. If the character is a +, the sum is printed; if it is a -, the difference is printed; if it is a *, the product is printed; if it is a /, the quotient is printed; and if it is a %, the remainder is printed. Use a switch statement.
    char oper('~');
    double val1(0), val2(0);
    std::cout << "Enter two values.\n";
    std::cin >> val1 >> val2;
    std::cout << "Enter the operation you would like to perform : +, -, *, /, %\n";
    std::cin >> oper;

    switch(oper)
    {
        case '+':
        {
            std::cout << val1 + val2 << std::endl;
            break;
        }
        case '-':
        {
            std::cout << val1 - val2 << std::endl;
            break;
        }
        case '*':
        {
            std::cout << val1 * val2 << std::endl;
            break;
        }
        case '/':
        {
            std::cout << val1 / val2 << std::endl;
            break;
        }
        case '%':
        {
            std::cout << static_cast<int>(val1) % static_cast<int>(val2) << std::endl;
            break;
        }
    }

//3.9 - Write and run a program that plays the game of "Rock, paper, scissors." In this game, two players simultaneously say either "rock", "paper", or "scissors". Winner's choice dominates the other. paper > rock, rock > scissors, scissors > paper. Use enumerated types for the choices and results.
    enum tool {ROCK, PAPER, SCISSORS};
    enum outcome {WIN = true, LOSE = false};

    char choice = ('u');
    int play1(4), play2(5);
    srand(time(NULL));

//Game plays until stop
    while(choice != 'n'){
//random number makes choice for each player
        std::cout << "play1 = " << (play1 = rand() % 3) << std::endl;
        std::cout << "play2 = " << (play2 = rand() % 3) << std::endl;

        if(play1 == play2)
            std::cout << "Tie!!" << std::endl;
        else if(play1 == ROCK && play2 == PAPER)
            std::cout << "play2 wins!" << std::endl;
        else if(play1 == ROCK && play2 == SCISSORS)
            std::cout << "play1 wins!" << std::endl;
        else if(play1 == PAPER && play2 == SCISSORS)
            std::cout << "play2 wins!" << std::endl;
        else if(play1 == PAPER && play2 == ROCK)
            std::cout << "play1 wins!" << std::endl;
        else if(play1 == SCISSORS && play2 == PAPER)
            std::cout << "play1 wins!" << std::endl;
        else if(play1 == SCISSORS && play2 == ROCK)
            std::cout << "play2 wins!" << std::endl;

        std::cout << "Continue playing (y/n) :";
        std::cin >> choice;
    }
    
//3.10 - modify 3.9 by using a switch statment
//enum
    enum games{SCISSORS, PAPER, ROCK};
    enum win{WIN, LOSE};

//var for choice
    unsigned char choice('u');

//random generator
    srand(time(NULL));

//var for player1 and player2
    unsigned int play1(4), play2(5);

//outcome var
    unsigned outcome(6);

//switch statement for game outcome
//loop to continue playing
    do{

        play1 = rand() % 3;
        play2 = rand() % 3;

//solution table :
//
// case 0 - S : R
    if(play1 == SCISSORS && play2 == ROCK)
        outcome = 0;
// case 1 - S : P
    if(play1 == SCISSORS && play2 == PAPER)
        outcome = 1;
// case 2 - R : P
    if(play1 == ROCK && play2 == PAPER)
        outcome = 2;
// case 3 - R : S
    if(play1 == ROCK && play2 == SCISSORS)
        outcome = 3;
// case 4 - P : R
    if(play1 == PAPER && play2 == ROCK)
        outcome = 4;
// case 5 - P : S
    if(play1 == PAPER && play2 == SCISSORS)
        outcome = 5;
// default - tie

    switch(outcome){
        case 0:
        {
            std::cout << "play2 wins!" << std::endl;
            break;
        }
        case 1 :
        {
            std::cout << "play1 wins!" << std::endl;
            break;
        }
        case 2 :{
            std::cout << "play2 wins!" << std::endl;
            break;
        }
        case 3 :
        {
            std::cout << "play1 wins!" << std::endl;
            break;
        }
        case 4 :
        {
            std::cout << "play1 wins!" << std::endl;
            break;
        }
        case 5 :
        {
            std::cout << "play2 wins!" << std::endl;
            break;
        }
        default:
            std::cout << "Tie!!" << std::endl;
    }
        std::cout << "continue playing? (y:n) : ";
        std::cin >> choice;
    }while(choice == 'y');

//3.11 - Modify solution 3.10 by using conditional expressions, use nested switch statements
//3.12 - Write a program that solves quadratic equations. Declare coefficients as type double. Use x1 and x2 as the solutions to output of type double. Quadratic equation has form : ax^2 + bx + c = 0
    
//Create variables for calculations
    double x1(0), x2(0), a(0), b(0), c(0);
    std::cout << "Enter the coefficients for the quadratic equation; a, b, followed by c\n";
    std::cin >> a >> b >> c;

    x1 = (-b - sqrt((b * b) - (4 * a * c)))/(2 * a);
    x2 = (-b + sqrt((b * b) - (4 * a * c)))/(2 * a);
    std::cout << "root 1 = " << x1 << std::endl;
    std::cout << "root 2 = " << x2 << std::endl;

//3.13 - Write a program that reads a six-digit integer and print the sum of its six digits. Use the quotient operator/ and the remainder operator% to extract the digits from the integer.
    int val(0), sum(0);
    std::cout << "Enter a 6 digit number\n";
    std::cin >> val;

    sum += get_sum(val);
    std::cout << "sum = " << sum << std::endl;
    return 0;
}

int get_sum(int val)
{
//base case
    if(val/10 == 0)
        return val % 10;
//smaller problem
    else
        return get_sum(val/10) + val % 10;
}
