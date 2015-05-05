// DATE : 05/05/15
// FILE : APAN:05.05.15.cpp
// DESC : Explicit conversions of built-in and class type

#include <iostream>
#include <vector>

class A{

// CONSTRUCTORS //
public :
    A() { }
    A(int val) { a = val; }

// MEMBER FUNCTIONS //
    virtual int get_mem() = 0;

// DATA MEMBERS //
protected :
    int a = 1;
};

class B : public A{

// CONSTRUCTORS //
public :
    B() { }
    B(int val1, int val2) : A(val1), b(val2) { }

// MEMBER FUNCTIONS //
    int get_mem() { return b; }

// DATA MEMBERS //
private :
    int b = 1;
};

int main()
{
// Conversions of built-in type
    const float cf = 45.9;
    const void *cvp = &cf;

// const_cast
    void *vp = const_cast<void*>(vp);

// static_cast
    float *fp = static_cast<float*>(vp);

// Conversions of class type

// dynamic_cast
    B objB1(3, 4);
    B objB2;
    A &objA = objB2;
    A *ptA = dynamic_cast<A*>(&objB1);
    B &refB = dynamic_cast<B&>(objA);

    return 0;
}
