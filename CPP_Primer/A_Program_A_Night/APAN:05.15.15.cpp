// DATE : 05/15/15
// FILE : APAN:05.15.15.cpp
// DESC : Use scope levels : global scope, namespace scope, class scope, block scope

#include <iostream>
#include <vector>

// var with global scope
double global(8.4);

namespace Ode_name{

// Nested namespace that defines alias
    inline namespace Ode_in_name{
        using Ode_in_name_type = double;
    }
    Ode_in_name_type add(int val1, int val2) { return val1 + val2; }
}

// class definition
class Ode{
public:
    typedef double Ode_type;
    Ode() = default;
    Ode_type get_mem() { return o; }
    void set_mem(Ode_type val) { o = val; }
private :
    Ode_type o = 43.2;
};

int main()
{
// local var
    Ode::Ode_type global(56.5); // use class scope to get base type

// create object of type Ode od
    Ode od;

    od.set_mem(::global); // Explicitly specify hidden global with global scope operator
    std::cout << od.get_mem() << std::endl;
    od.set_mem(global);
    std::cout << od.get_mem() << std::endl;

    if(global){
        Ode::Ode_type dval(8.32); // block scope var
        od.set_mem(dval);
    }
    std::cout << od.get_mem() << std::endl;

    std::cout << (Ode_name::add(global, ::global)) << std::endl; // Call function from Ode_name namespace
    return 0;
}
