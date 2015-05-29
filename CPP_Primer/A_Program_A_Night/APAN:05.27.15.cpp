// DATE : 05/27/15
// FILE : APAN:05.27.15.cpp
// DESC : Classes and functions with default arguments

#include <iostream>
#include <vector>
#include <string>

// Class with member functions with default arguments
class DefClass{

public :

// TYPE MEMBERS //
    using type = std::string;

// MEMBER FUNCTIONS //
    DefClass() { str = "Default class string"; }
    DefClass(int i, std::string str_arg = "Default constructor string") { str = str_arg; }
    std::string get_str() { return str; }
    void set_str(std::string str_arg) { str = str_arg; }

private :

// DATA MEMBERS //
    type str;
};

// Function with default arguments
std::ostream& print(std::ostream& out, std::string str = "Default string");

int main()
{
    DefClass d0;
    print(std::cout, d0.get_str());

    DefClass d1(1, "Constructor string");
    print(std::cout, d1.get_str());

    DefClass d2(7);
    print(std::cout, d2.get_str());

    print(std::cout, "Argument string");
    return 0;
}

std::ostream& print(std::ostream& out, std::string str)
{
    std::cout << str << std::endl;
    return out;
}
