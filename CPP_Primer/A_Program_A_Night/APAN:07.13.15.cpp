// DATE : 07/13/15
// FILE : APAN:07.13.15.cpp
// DESC : Using literal classes

#include <iostream>
#include <string>

// Define literal class0, i.e aggregate class with all data members of literal type

struct Lit0{

// DATA MEMBERS //
   int num;
   char ch;
   double db;
};

std::ostream& operator<<(std::ostream &out, const Lit0 &obj)
{
    out << "num : " << obj.num << '\n'
        << "ch : " << obj.ch << '\n'
        << "db : " << obj.db;
    return out;
}

// Define literal class1, i.e. nonaggregate class with : one constexpr constructor, all literal type data members, any in-class initializers of type constexpre, and default destructor

struct Lit1{

// COPY CONTROL //
    Lit1() = default;
    constexpr Lit1(int num_arg, char ch_arg, double db_arg) : num(num_arg), ch(ch_arg), db(db_arg) { }
    ~Lit1() = default;

// DATA MEMBERS //
    int num;
    char ch;
    double db = 2.41;

// FRIENDS //
    friend std::ostream& operator<<(std::ostream& out, const Lit1 &obj);
};

std::ostream& operator<<(std::ostream &out, const Lit1 &obj)
{
    out << "num : " << obj.num << '\n'
        << "ch : " << obj.ch << '\n'
        << "db : " << obj.db;
    return out;
}

int main()
{
// Create objects of type Lit0 and Lit1
    Lit0 lt00;
    Lit0 lt01{4, '3'};
    Lit1 lt10;
    Lit1 lt11(8, 'd', 3.41);

// Print Lit0 and Lit1 objects
    std::cout << lt00 << std::endl;
    std::cout << lt01 << std::endl;
    std::cout << lt10 << std::endl;
    std::cout << lt11 << std::endl;

    return 0;
}
