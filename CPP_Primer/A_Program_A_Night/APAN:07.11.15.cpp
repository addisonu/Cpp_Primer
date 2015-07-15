// DATE : 07/11/15
// FILE : APAN:07.11.15.cpp
// DESC : using assert preprocessor macro

#include <iostream>
#include <cassert>
#include <string>

void print(std::string str);

int main()
{
    std::cout << "Enter a string.\n";
    std::string str;
    std::getline(std::cin, str);

    assert(str.size()); // will be executed if NDEBUG not defined

// Will be executed if NDEBUG defined
#ifdef NDEBUG
    std::cerr << __func__ << " : str.size = " << str.size() << (str.size() ? "\nString will be printed." : "\nString will not be printed.") << std::endl;
#endif

    print(str);

    return 0;
}

void print(std::string str)
{
    for(auto ele : str)
        std::cout << ele;
    std::cout << std::endl;
}
