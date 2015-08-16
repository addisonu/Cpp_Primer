// DATE : 08/09/15
// FILE : APAN:08.09.15.cpp
// DESC : C++ primer exercises :

#include <iostream>
#include "../C++_Primer/Sales_item.h"


// Forward declarations
struct Sales_data;

int main()
{
/*
// Ex 2.18
    double d0(232.3), d1(3.4), *dp = &d0;

    std::cout << "dp = " << dp << "\n*dp = " << *dp << std::endl;

    dp = &d1;
    std::cout << "dp = " << dp << "\n*dp = " << *dp << std::endl;

    *dp = 2.147;
    std::cout << "d1 = " << d1 << std::endl;

// Ex 2.34
    int i = 0, &r = i;
    auto a = r;
    const int ci = i, &cr = ci;
    auto b = ci;
    auto c = cr;
    auto d = &i;
    auto e = &ci;
    const auto f = ci;
    auto &g = ci;
    const auto &j = 42;
    auto k = ci, &l = i;
    auto &m = ci, *p = &ci;

    a = 42; // int
    b = 42; // int
    c = 42; // int
    //d = 42; // error int*
    //e = 42; // error const int*
    //g = 42; // error const int&

// Ex 2.35
    const int i = 42;
    auto j = i; // int
    const auto &k = i; // const int &
    auto *p = &i; // int **
    const auto j2 = i, &k2 = i; // const in, const int &
    int *p1 = nullptr;
    p = &p1;

*/
    return 0;
}

// Ex 2.40
struct Sales_data{
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};
