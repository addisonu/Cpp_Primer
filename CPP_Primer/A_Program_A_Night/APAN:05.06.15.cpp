// DATE : 05/06/15
// FILE : APAN:05.06.15.cpp
// DESC : Battery of overloaded functions

#include <iostream>

// Function prototypes
int min(int val1, int val2);
int min(int val1, int val2, int val3);
int min(int val1, int val2, int val3, int val4);

int main()
{
    short val1(9);
    int val2(3);
    float val3(19.34);
    double val4(1.234);

// Call each version of min()
    std::cout << "min(val1, val2) : " << min(val1, val2) << std::endl;
    std::cout << "min(val1, val2, val3) : " << min(val1, val2, val3) << std::endl;
    std::cout << "min(val1, val2, val3, val4) : " << min(val1, val2, val3, val4) << std::endl;

    return 0;
}

int min(int val1, int val2)
{
    if(val1 <= val2)
        return val1;
    else
        return val2;
}

int min(int val1, int val2, int val3)
{
    return (val1 <= val2 ? min(val1, val3) : min(val2, val3));
}

int min(int val1, int val2, int val3, int val4)
{
    return (val1 <= val2 ? min(val1, val3, val4) : min(val2, val3, val4));
}
