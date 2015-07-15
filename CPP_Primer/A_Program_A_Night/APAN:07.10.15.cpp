// DATE : 07/10/15
// FILE : APAN:07.10.15.cpp
// DESC : Legal identifiers

#include <iostream>
#include <string>

const int CONST_VAL = 19;

int main()
{
// Objects demonstrating legal identifier names
    int integer(0);
    double _double(4);
    char Char('u');
    wchar_t _wChar_T('t');
    float F100at(5.5);
    std::string STRING("STRING");

// Print contents of objects
    std::cout << "CONST_VAL = " << CONST_VAL << std::endl;
    std::cout << "integer = " << integer << std::endl;
    std::cout << "_double = " << _double << std::endl;
    std::cout << "Char = " << Char << std::endl;
    std::cout << "_wChar_T = " << _wChar_T << std::endl;
    std::cout << "F100at = " << F100at << std::endl;
    std::cout << "STRING = " << STRING << std::endl;

    return 0;
}
