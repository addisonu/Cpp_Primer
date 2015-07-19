// DATE : 07/17/15
// FILE : APAN:07.17.15.cpp
// DESC : iostream manipulators

#include <iostream>
#include <string>
#include <sstream>

int main()
{
    std::cout << std::boolalpha << (1 == 1) << "\n" << (1 == 0) << std::endl; //Print words true or false
    std::cout << std::noboolalpha << (1 == 1) << "\n" << (1 == 0) << std::endl;

    int val(453);
    std::cout << std::showbase; //Print base of number
    std::cout << std::dec << val << std::endl; //Integral values in dec
    std::cout << std::hex << val << std::endl; // Integral values in hex
    std::cout << std::oct << val << std::endl; //Integral values in oct
    std::cout << std::dec;
    std::cout << std::noshowbase;

    double dval(434);
    std::cout << std::showpoint; //Print decimal for any floating pointer number regardless of fractional value
    std::cout << dval << std::endl;
    std::cout << std::noshowpoint;
    std::cout << dval << std::endl;

    std::cout << std::showpos; //Print + for positive numbers
    std::cout << dval << std::endl;
    std::cout << std::noshowpos;

    std::cout << std::uppercase; //Print 0X in hex E in scientific
    std::cout << 0X4D << std::endl;
    std::cout << 0.0077E-3 << std::endl;
    std::cout << std::nouppercase;

    std::cout << std::left; //add fill to left of value
    std::cout.width(7);
    std::cout << dval << std::endl;
    std::cout << std::right; //add fill to right of value
    std::cout.width(8);
    std::cout << dval << std::endl;
    std::cout << std::internal; //add fill between sign and value
    std::cout.width(9);
    std::cout << std::showpos;
    std::cout << dval << std::endl;
    std::cout << std::noshowpos;

    std::cout << std::scientific; //Print floating point in scientific
    std::cout << 0.0077 << std::endl;

    std::cout << std::hexfloat; //Print floating point in hex
    std::cout << 0.0077 << std::endl;
    std::cout << std::defaultfloat; //Print floating point in dec

    std::cout << std::unitbuf; //Flush buffer after each output op
    std::cout << "All ";
    std::cout << "Good ";
    std::cout << "Boys ";
    std::cout << "Do ";
    std::cout << "Fine ";
    std::cout << std::nounitbuf; //Restore default buffer flushing

    std::stringstream ss("One two three four five");
    std::string input, output;
    ss >> std::skipws;
    while(ss >> input)
        output += input;

    std::cout << '\n' << output << std::endl;
    std::cout << std::noskipws; //Don't skip whitespace in input

    std::cout << "Hello github" << std::flush; //Flush ostream buffer
    std::cout << "Hello github" << std::ends; //Insert null and flush ostream buffer
    std::cout << "Hello github" << std::endl; //Insert newline and flush ostream buffer

    return 0;
}
