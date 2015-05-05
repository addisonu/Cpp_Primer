// DATE : 05/04/15
// FILE : APAN:05.04.15.cpp
// DESC : Implicit conversions of built-in and class type

#include <iostream>

// Simple structs to demonstrate conversions between class types related by a conversion
class B;
struct A;

struct A{
// CONSTRUCTORS //
    A();
    A(B obj);

// DATA MEMBERS //
private:
    int a = 0;
};

class B{
public:
// CONSTRUCTORS //
    B();
    B(A obj);

// DATA MEMBERS //
private:
    int b = 0;
};


int main()
{
// Built-in type conversions
    int i(10);
    short s(5);
    double d(0.5);
    short

// Small type conversion
    std::cout << i + s << std::endl; // short promoted to int
    return 0;
}

// Simple function to demonstrate conversions among built-in arithmetic types
int add(int a, int b)
{
    return a + b;
}
