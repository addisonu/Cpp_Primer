//DATE : 03/26/15
//FILE : ch4_problems.cpp
//DESC : Schaums ch4 problems
//LEFT OFF : debugging 4.14

#include <iostream>
#include <string>
#include <cmath>
#include <vector>

int main()
{
// 4.7 - Write a program that uses a for loop to compute and print the sum of a given number of squares. E.g. input = 5, output = 1^2 + 2^2 + 3^2 + 4^2 + 5^2
    int input(0), sum(0);
    std::cout << "Enter the number of square to sum.\n";
    std::cin >> input;

    for(unsigned i = 1; i <= input; ++i)
        sum += pow(i, 2);

    std::cout << "The sum of squares up to " << input << " is " << sum << std::endl;

// 4.8 - Write a pprogram that uses a while loop to compute and prin the sume of a given number of square
    int cnt(1), sum(0), input(0);
    std::cout << "How many squares would you like to sum?\n";
    std::cin >> input;

    while(cnt <= input)
        sum += pow(cnt++, 2);
    std::cout << "The sum of squares up to " << input << " is " << sum << std::endl;

// 4.9 - Write a program that uses a do..while loop to compute and print the sum of a given number of squares

    int sum(0), cnt(0), input(0);

    std::cout << "Up to what number would you like to sum the squares?\n";
    std::cin >> input;

    do{
        sum += pow(++cnt, 2);
    }while(cnt < input);
    std::cout << "The sum of squares up to " << input << " is " << sum << std::endl;
    
// 4.10 - Write a program that directly implements the quotient operator / and the remainder operator % for the division of positive integers

    int val1(0), val2(0);
    std::cout << "Enter two positive integers, i.e. greater than 0.\n";
    std::cin >> val1 >> val2;

    std::cout << val1 << "/" << val2 << " = " << val1/val2 << std::endl;
    std::cout << val1 << "%" << val2 << " = " << val1%val2 << std::endl;

//4.11 - Write a program to reverse the digits of a given positive integer
    int input(0), dig(0), cnt(1), result(0);
    std::cout << "Enter an integer.\n";
    std::cin >> input;

    while(input / cnt){
        dig = (input / cnt) % 10;
        result += dig;
        cnt *= 10;
        if(input/cnt)
            result *= 10;
    }
    std::cout << "result = " << result << std::endl;

//4.13 - Write a program to find the integer square root of a given number. That is the largest integer whose square is less than or equal to the given number

    int input(0), root(0);
    std::cout << "Enter a number to find the integer square root of.\n";
    std::cin >> input;
    root = sqrt(input);
    std::cout << "The integer square root of " << input << " " <<  root << std::endl;

// 4.14 - Implement the Euclidean algorithm for finding the gcd of two given positive integers.
    unsigned lval(0), sval(0);
    unsigned a(0), b(0), q(0), r(0);

    std::cout << "Enter two integers, entering the largest first.\n";
    std::cin >> lval >> sval;

    a = lval;
    b = sval;
    while((r = a % b)){
        a = b;
        b = r;
    };
    std::cout << "the gcd(" << lval << "," << sval << ") is " << b << std::endl;

    return 0;
}
