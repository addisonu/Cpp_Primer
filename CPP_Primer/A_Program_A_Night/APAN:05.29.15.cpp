// DATE : 05/29/15
// FILE : APAN:05.29.15.cpp
// DESC : static objects, functions, and class member functions

#include <iostream>
#include <vector>

// Class definition
class Stat{

public :

// TYPE MEMBERS //
    typedef char val;

// MEMBER FUNCTIONS //
    Stat() { }
    Stat(std::initializer_list<val> il) : vvect(il) { }
    std::vector<val>& get_vvect() { return vvect; }
    static val get_ch() { return ch; }
    static void set_ch(val cval) { ch = cval; }

private :

// DATA MEMBERS //
    std::vector<val> vvect;
    static val ch; // declare data member ch

// FRIENDS //
    friend std::ostream& operator<<(std::ostream& out, Stat obj);
};

// Static function
static void add_ele(std::vector<Stat::val> &container)
{
    std::cout << "The current value in ch is : " << Stat::get_ch() << std::endl;
    std::string input;
    std::cout << "Enter a char\n";
    std::getline(std::cin, input);
    Stat::set_ch(input[0]);
    container.push_back(Stat::get_ch());
}

std::ostream& operator<<(std::ostream& out, Stat obj)
{
    for(char ele : obj.vvect)
        std::cout << ele << " ";
    return out;
}

Stat::val Stat::ch = 'u'; // Define Stat class static data member ch

int main()
{
    std::string input;
    Stat obj({'a', 'A', 'b', 'B'});
    do{
        add_ele(obj.get_vvect());
        std::cout << "Do you want to add another element to the object? (y/n) : ";
        std::getline(std::cin, input);
    }while(input[0] == 'y');
    std::cout << obj << std::endl; // Print elements in obj.vvect

    return 0;
}
