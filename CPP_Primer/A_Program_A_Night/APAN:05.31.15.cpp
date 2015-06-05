// DATE : 05/31/15
// FILE : APAN:05.31.15.cpp
// DESC : Contexts in which const qualifier can apply

#include <iostream>

// Class with const member function

class Cclass{

public :

// MEMBER FUNCTIONS //
    Cclass() { }
    double add() const { return a + b; }

private :

// DATA MEMBERS //
    int a = 2;
    double b = 9.4;
};

const double add(const double &lhs, const double &rhs);

int main()
{
// const objects
    constexpr unsigned sz(6);
    const char carr[sz] = "Hello";
    const char *pcarr = carr;
    std::cout << "carr : " << carr << std::endl;
    std::cout << "pcarr : " << pcarr << std::endl;

    double result = add(7.8, 1.4);
    std::cout << "add(7.8, 1.4) = " << result << std::endl;

    Cclass ccl;
    std::cout << "ccl.add() = " << ccl.add() << std::endl;

    return 0;
}

// const function with const parameters and const return type
const double add(const double &lhs, const double &rhs)
{
    return lhs + rhs;
}
