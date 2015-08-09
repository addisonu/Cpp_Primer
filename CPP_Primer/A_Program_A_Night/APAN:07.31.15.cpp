// DATE : 07/31/15
// FILE : APAN:07.31.15.cpp
// DESC : Using virtual functions

#include <iostream>
#include <string>

// Define base class
class B{

public :
    B() = default;
    B(int a_arg) : a(a_arg) { }
    B(const B &) = default;
    ~B() = default;
    virtual int square() { return a * a; }
    virtual int twice() { return a * 2; }

protected :
    int a = 0;
};

class D : public B{

public :
    D() = default;
    D(int a_arg, int b_arg) : B(a_arg), b(b_arg) { }
    D(const D &) = default;
    ~D() = default;
    int square() override { return B::square() +  b * b; }
    int twice() override { return (a + b) * 2; }

private :
    int b = 0;
};

int main()
{
// Create objects of type B and D
    B b0;
    B b1(7);
    D d0;
    D d1(8, 9);

    B *b2 = &b0, *b4 = &d0;
    B &b3 = b1, &b5 = d1;

    std::cout << "b0.twice() : " << b2->twice() << std::endl;
    std::cout << "d0.twice() : " << d0.twice() << std::endl;
    std::cout << "b1.square() : " << b3.square() << std::endl;
    std::cout << "d1.square() : " << d1.square() << std::endl;
    std::cout << "base class twice() : " << b4->B::twice() << std::endl;
    std::cout << "base class square() : " << b4->B::square() << std::endl;

    return 0;
}
