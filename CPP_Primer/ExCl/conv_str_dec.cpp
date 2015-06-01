// DATE : 05/31/15
// FILE : conv_str_dec.cpp
// DESC : Write a program that can read in a list of words and convert each word into an integer, and a separate program that convert integers into words. The program should work with words up to 10 characters in length. It should generate integers in the range 0 to N^10, where N is the number of characters in the alphabet you are using. If N=26, then your maximum value would be 26^10 = 141167095653376.

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

long str_to_dec(std::string str);
std::string dec_to_str(std::vector<unsigned> vec);

int main()
{
// Read in words and pass as arg to conversion function
    std::string input;
    std::size_t cnt(0);

    std::cout << "Enter the words to converted to a decimal product.\n";
    while(true){
        std::getline(std::cin, input);
        if(input.size())
            std::cout << "string #" << ++cnt << " product :  " << str_to_dec(input) << std::endl;
        else
            break;
    }
    unsigned digit(0);
    std::vector<unsigned> uvec;

// Read in numbers to convert to char
    std::cout << "Enter each single or double digit to be converted to a char, each separated by white space.\n";
    while(true){
            std::getline(std::cin, input);
            std::stringstream ss(input);
            if(input.size()){
                ss >> digit;
                uvec.push_back(digit);
            }
            else
                break;
    }
    std::cout << dec_to_str(uvec) << std::endl;

    return 0;
}

long str_to_dec(std::string str)
{
    long dec(1);
    if(str.size() && str.size() <= 10){
        for(auto ch : str)
            dec *= tolower(ch) - 96;
    }
    else
        std::cerr << "Word must be between 1 and 10 char" << std::endl;

    return dec;
}

// Each char of the integer must be entered as a single or double digit positive integer, a = 1, b = 2 , ... , z = 26
std::string dec_to_str(std::vector<unsigned> vec)
{
    std::string word;
    std::string input;
    unsigned ch('u');

        for(auto ch : vec)
        word += ch + 96;

    return word;
}
