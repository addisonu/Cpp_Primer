// DATE : 06/27/15
// FILE : APAN:06.27.15.cpp
// DESC : Numeric to string conversions

#include <iostream>
#include <string>

int main()
{
// Numeric to string
    std::cout << "Numeric to string :" << std::endl;
    std::string str;
    std::cout << (str = std::to_string(4.3)) << std::endl;
    std::cout << std::to_string(7) << std::endl;
    std::cout << std::to_string(10L) << std::endl;
    std::cout << std::to_string(8UL) << std::endl;
    std::cout << std::to_string(6LL) << std::endl;
    std::cout << std::to_string(7.32F) << std::endl;
    std::cout << std::to_string(34.7) << std::endl;
    std::cout << std::to_string(8.47L) << std::endl;

// String to numeric
    std::cout << "\nString to numeric :" << std::endl;
    std::cout << std::stoi("7") << std::endl;
    std::cout << std::stol("10") << std::endl;
    std::cout << std::stoul("8") << std::endl;
    std::cout << std::stoll("6") << std::endl;
    std::cout << std::stof("7.32") << std::endl;
    std::cout << std::stod("34.7") << std::endl;
    std::cout << std::stold("8.47") << std::endl;

    return 0;
}
