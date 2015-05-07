// DATE : 05/07/15
// FILE : APAN:05.07.15.cpp
// DESC : Battery of overloaded functions :
//  1) called with function pointer
//  2) function pointer as parameter type
//  3) return type of pointer to function

#include <iostream>

// Function prototypes
int min(int val1, int val2);
int min(int val1, int val2, int val3);
int min(int val1, int val2, int val3, int val4);
int min(int *val_arr, int min3(int val2, int val3, int val4)); // min taking 3 arguments is parameter
int (*min_id(int min2(int val1, int val2)))(int val1, int val2); // min taking 2 arguments is parameter and return type

int main()
{
// var to be passed as function arguments
    int val1(9), val2(3), val3(19), val4(1);
    int val_arr[]{val1, val2, val3, val4};

// Pointer to each overloaded function
    int (*min2)(int val1, int val2) = min;
    int (*min3)(int val1, int val2, int val3) = min;
    int (*min4)(int val1, int val2, int val3, int val4) = &min;
    using Func = auto (int (*)(int, int)) -> int (*)(int, int); // alias to simplify function pointer declaration
    Func (*min5) = min_id;

// Call each version of min()
    std::cout << "min(val1, val2) : " << min2(val1, val2) << std::endl;
    std::cout << "min(val1, val2, val3) : " << min3(val1, val2, val3) << std::endl;
    std::cout << "min(val1, val2, val3, val4) : " << min4(val1, val2, val3, val4) << std::endl;
    std::cout << "min(val1, min(val2, val3, val4)) : " << min(val_arr, min3) << std::endl;
    std::cout << "min_id(int min2(int val1, int val2)) : " << (min5(min2)(val1, val3)) << std::endl; // call min5 and pass arguments to function that is returned

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

int min(int *val_arr, int min3(int val1, int val2, int val3))
{
    return min(*val_arr, min3(val_arr[1], val_arr[2], val_arr[3]));
}

int (*min_id(int min2(int val1, int val2)))(int val1, int val2)
{
    return min2;
}
