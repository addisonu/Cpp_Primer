// DATE : 05/01/15
// FILE : APAN:05.01.15.cpp
// DESC : Implement the Euclidean theorem using recursion

#include <iostream>
#include <cmath>

unsigned gcd_recurse(int a, int b);
int main()
{
    std::cout << gcd_recurse(-532, 112) << std::endl;
    return 0;
}

unsigned gcd_recurse(int a, int b)
{
    int r = abs(a % b);
    if(!r)
        return b;
    else
        return gcd_recurse(b, r);
}


