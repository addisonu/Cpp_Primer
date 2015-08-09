// DATE : 08/03/15
// FILE : APAN:08.03.15.cpp
// DESC : Use class conversion operator to explicitly convert from a class type

#include <iostream>
#include <string>

// Define class with conversion operator member
class Con{

public :
    Con() { }
    Con(int ival_arg, double dval_arg) : ival(ival_arg), dval(dval_arg){ }
    operator int() const { return ival; }
    operator double() const { return dval; }

private :
    int ival = 0;
    double dval = 0;

friend std::ostream& operator<<(std::ostream &out, const Con obj);
};

std::ostream& operator<<(std::ostream &out, const Con obj)
{
    out << "ival : " << obj.ival
    << "dval : " << obj.dval;

    return out;
}

int main()
{
// Convert double to object of type Con
    Con obj0(7, 7.777);
    std::cout << obj0 << std::endl;

// Convert Con object to type int
    int i = obj0;
    std::cout << "i : " << i << std::endl;

// Convert Con object to type double
    double d = obj0;
    std::cout << "d : " << d << std::endl;

    return 0;
}
