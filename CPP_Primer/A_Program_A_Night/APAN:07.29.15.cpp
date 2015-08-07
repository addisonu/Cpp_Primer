// DATE : 07/29/15
// FILE : APAN:07.29.15.cpp
// DESC : Treat callable objects with the same call signature as functions using library type function

#include <iostream>
#include <string>
#include <functional>
#include <vector>

// Create objects to store in function objects
// Class def
struct Func0{
    Func0() { }
    int operator()(int a, int b) { return a + b; }
};

int Func1(int a, int b)
{
    return a + b;
}

int main()
{
// Lambda
    auto Func2 = [] (int a, int b) -> int { return a + b; };

// Simplify function type
    using func_type = int(int, int);

// Store callable objects in function objects
    std::cout << "Call function as stand alone :\n";
    std::function<func_type> f0 = Func0();
    std::cout << f0(9, 7) << std::endl;

    std::function<func_type> f1(Func1);
    std::cout << f1(4, 6) << std::endl;

    std::function<func_type> f2(Func2);
    std::cout << f2(4, 7) << std::endl;

// Store in container holding functions of type T
    std::vector<std::function<func_type>> tbl;
    tbl.push_back(f0);
    tbl.push_back(f1);
    tbl.push_back(f2);

    std::cout << "Call function from tbl :\n";
    int val1(4), val2(8);
    for(std::function<func_type> func : tbl)
        std::cout << func(4, 8) << std::endl;

    return 0;
}
