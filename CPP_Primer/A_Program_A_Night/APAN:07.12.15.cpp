// DATE : 07/12/15
// FILE : APAN:07.12.15.cpp
// DESC : Using aggregate classes

#include <iostream>
#include <string>

// Define aggregate class
struct Agg{

// DATA MEMBERS //
    int num;
    char ch;
    std::string str;

// FRIENDS //
    friend std::ostream& operator<<(std::ostream& out, const Agg &obj);
};

std::ostream& operator<<(std::ostream &out, const Agg &obj)
{
    out << "num : " << obj.num << '\n'
        << "ch : " << obj.ch << '\n'
        << "str : " << obj.str;
    return out;
}

int main()
{
// Create object of type Agg and initialize data members
    Agg a0{4, 'c', "string"};
    Agg a1{3, 'd'};

// Print Agg objects
    std::cout << a0 << std::endl;
    std::cout << a1 << std::endl;
    return 0;
}
