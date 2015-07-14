// DATE : 07/07/15
// FILE : APAN:07.07.15.cpp
// DESC : Copy and swap idiom
// NOTE :
//  1) Copy constructor invokes operator=
//  2) OR operator= invokes copy constructor in parameter initialization for copy and swap idiom
//  3) NOT both #1 and #2

#include <iostream>
#include <string>

class Obj;
void swap(Obj &lhs, Obj &rhs);
class Obj{

public:

// CONSTRUCTORS //
    Obj() { }
    Obj(char a_arg, char b_arg) : a(a_arg), b(b_arg) { }
    Obj(const Obj &cpy)
    {
        a = cpy.a;
        b = cpy.b;
    }

// MEMBER FUNCTIONS //
    Obj& operator=(Obj rhs)
    {
        swap(*this, rhs);
        return *this;
    }

private:

// DATA MEMBERS //
    char a = ' ';
    char b = ' ';

// FRIENDS //
    friend void swap(Obj &lhs, Obj &rhs);
    friend std::ostream& operator<<(std::ostream &out, const Obj &obj);
};

inline void swap(Obj &lhs, Obj &rhs)
{
    using std::swap;
    swap(lhs.a, rhs.a);
    swap(lhs.b, rhs.b);
}

std::ostream& operator<<(std::ostream &out, const Obj &obj)
{
    std::cout << "a : " << obj.a << std::endl;
    std::cout << "b : " << obj.b << std::endl;
    return out;
}

int main()
{
    Obj o0;
    Obj o1('u', 'n');
    Obj o2(o1);
    o0 = o2;

    std::cout << o0;
    std::cout << o1;
    std::cout << o2;

    return 0;
}
