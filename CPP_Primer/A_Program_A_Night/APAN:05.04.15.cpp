// DATE : 05/04/15
// FILE : APAN:05.04.15.cpp
// DESC : Implicit conversions of built-in and class type

#include <iostream>

// Forward declarations
class B;
struct A;
int add(int a, int b);

// Simple structs to demonstrate conversions between class types related by a conversion
struct A{
// CONSTRUCTORS //
    A() { }

// DATA MEMBERS //
    int a = 0;
};

class B{
public:
// CONSTRUCTORS //
    B() { }
    B(A obj) { b = obj.a; }

// DATA MEMBERS //
    int b = 0;
};

int main()
{
// Built-in type conversions

// Small type conversion
    int i(10);
    short s(5);
    std::cout << i + s << std::endl; // short promoted to int

// nonbool converted to bool
    if(-123)
        std::cout << "true" << std::endl; // condition converted to true

// Initializer conversions
    double d(2); // int converted to double, 2.0
    int i2(7.77); // double truncated and converted to int 7

// Mixed type expression conversions to common type
    std::cout << (1 + 2.2L + true + char(3)) << std::endl; // int converted to long double, bool promoted to int to long double, char promoted to signed int to long double

    std::cout << ((12.2) < (3.0F) ? 78UL : 4LL) << std::endl; // all types not signed long long, converted to signed long long

// Array to pointer conversion
    float farr[]{1.1, 2.2};
    float *pf = farr; // farr converted to pointer;

// Conversion to const
    int i3(2);
    const int ci(i3); // copy of i3 converted to const

// Argument conversions in function call, all arguments converted to int
    add(1, 1.1);
    add(2L, 4UL);
    add(3.3F, true);
    add('u', short(1));

// Class type conversions
    A objA;
    B objB1;
    B objB2(objA); // constructed with argument of type A
    objB1 = objA; // temp object of type B constructed from objA and stored in objB1

    return 0;
}

// Simple function to demonstrate conversions among built-in arithmetic types
int add(int a, int b)
{
    return a + b;
}
