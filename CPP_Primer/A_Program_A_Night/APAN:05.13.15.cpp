// DATE : 05/13/15
// FILE : APAN:05.13.15.cpp
// DESC : Classes related by inheritance with members accessed via polymorphism
//  1) Class A is abstract base class
//  2) Class B is base class
//  3) Class C is derived class of A and B

#include <iostream>

// Class definitions

class A{
public :

// CONSTRUCTORS //
    A() = default;
    A(int val) : a(val) { }

// COPY CONTROL //
    A(const A&) = default;
    A& operator=(const A&) = default;
    ~A() = default;

// MEMBER FUNCTIONS //
    virtual void set_val(int *vals, std::size_t sz) = 0;

protected :

// DATA MEMBERS //
    int a = 0;
};

class B{
public :

// CONSTRUCTORS //
    B() = default;
    B(int val) : b(val) { }

// COPY CONTROL //
    B(const B&) = default;
    B& operator=(const B&) = default;
    ~B() = default;

// MEMBER FUNCTIONS //
    int get_val() { return b; }
    void set_b(int val) { b = val; }

protected :

// DATA MEMBERS //
    int b = 0;
};

class C : public A, public B{
public :

// CONSTRUCTORS //
    C() = default;
    C(int val1, int val2, int val3) : A(val1), B(val2), c(val3) { }

// COPY CONTROL //
    C(const C&) = default;
    C& operator=(const C&) = default;
    ~C() = default;

// MEMBER FUNCTIONS //
    int* get_val(int *vals)
    {
        vals[0] = a;
        vals[1] = b;
        vals[2] = c;
        return vals;
    }

    void set_val(int* vals, std::size_t sz)
    {
        if(sz >= 3){
            a = *vals;
            b = vals[1];
            c = vals[2];
        }
        else if(sz == 2){
            a = *vals;
            b = vals[1];
        }
        else if(sz == 1){
            a = *vals;
        }
        else
            std::cout << "argument array is empty." << std::endl;
    }

    void set_a(int val) { a = val; }
    void set_c(int val) { c = val; }

private :

// DATA MEMBERS //
    int c = 0;

// FRIENDS //
    friend std::ostream& operator<<(std::ostream &out, const C &obj);
};

std::ostream& operator<<(std::ostream &out, const C &obj)
{
    std::cout << obj.a << " " << obj.b << " " << obj.c;
    return out;
}

int main()
{
// Object of type B b
    B b;

// Object of type C c
    C c0;
    C c1(1,2,3);

// Object of type A& a0 and A* a1
    A &a0 = c0;
    A *a1 = &c1;

// Use objects of type A to set values of c0 and c1
    constexpr std::size_t sz1(6), sz2(2);
    int vals[sz1]{6, 7, 9, 4, 6, 11};

    a0.set_val(vals, sz1);
    a1->set_val(vals + 3, sz2);

// Print values of c0 and c1
    std::cout << c0 << std::endl;
    std::cout << c1 << std::endl;

    return 0;
}
