// DATE : 07/09/15
// FILE : APAN:07.09.15.cpp
// DESC : Use of pair type

#include <iostream>
#include <string>
#include <utility>

int main()
{
// Create pair objects
    std::pair<std::string, int> p0;
    std::pair<std::string, int> p1("string1", 1);
    std::pair<std::string, int> p2 = {"string2", 2};
    std::pair<std::string, int> p3 = std::make_pair("string3", 3);

// Print pairs
    std::cout << "p0.first = " << p0.first << " p0.second = " << p0.second << std::endl;
    std::cout << "p1.first = " << p1.first << " p1.second = " << p1.second << std::endl;
    std::cout << "p2.first = " << p2.first << " p2.second = " << p2.second << std::endl;
    std::cout << "p3.first = " << p3.first << " p3.second = " << p3.second << std::endl;

// Use pair operations
    std::cout << std::boolalpha;
    std::cout << "p1.first > p2.first : " << (p1.first > p2.first) << std::endl;
    std::cout << "p1.first < p2.first : " << (p1.first < p2.first) << std::endl;
    std::cout << "p2.second == p3.second " << (p2.second == p3.second) << std::endl;
    std::cout << "p1 != p3 : " << (p1 != p3) << std::endl;

    return 0;
}
