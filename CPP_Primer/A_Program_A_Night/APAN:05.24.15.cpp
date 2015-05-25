// DATE : 05/24/15
// FILE : APAN:05.24.15.cpp
// DESC : Initialize varying number of parameters of same type via initializer_list

#include <iostream>
#include <initializer_list>

void print_str(std::initializer_list<std::string> sli);

int main()
{
// Initializer list for argument
    std::initializer_list<std::string> days{"Sunday","Monday","Tuesday","Wednesday","Thrusday","Friday","Saturday"};

// Function call with var
    print_str(days);

// Function call with temporary initializer list
    print_str({"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"});

    return 0;
}

void print_str(std::initializer_list<std::string> sli)
{
    std::cout << "Elements in list : " << sli.size() << std::endl;
    for(const auto &str : sli)
        std::cout << str << " ";
    std::cout << std::endl;
}
