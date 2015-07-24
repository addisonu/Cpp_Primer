// DATE : 07/24/15
// FILE : APAN:07.24.15.cpp
// DESC : Define and use rvalue references

#include <iostream>
#include <string>

int main()
{
// rvalue reference to expression that requires a conversion
    std::string &&r0 = std::string("rvalue");
    std::cout << "r0 : " << r0 << std::endl;

// rvalue reference to literal
    char &&r1 = 'u';
    std::cout << "r1 : " << r1 << std::endl;

// rvalue reference to rvalue result
    int ival(8);
    double dval(9.4);
    double &&r2 = ival + dval;
    std::cout << "r2 : " << r2 << std::endl;

return 0;
}
