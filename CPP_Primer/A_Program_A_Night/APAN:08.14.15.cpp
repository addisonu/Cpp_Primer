// DATE : 09/14/15
// FILE : APAN:08.14.15.cpp
// DESC : Cpp primer exercises 9.14

#include <iostream>
#include <vector>
#include <list>

int main()
{
// Ex 9.14
    std::list<char *> c_lst{"This", "is", "a", "list", "of", "strings"};
    std::vector<std::string> svec(c_lst.cbegin(), c_lst.cend());

    for(std::string str : svec)
        std::cout << str << std::endl;

// Ex 9.15
    std::vector<int> v0{1, 2, 3}, v1{2, 3, 4};
    std::cout << std::boolalpha;
    std::cout << (v0 == v1) << std::endl;

// Ex 9.16
    std::list<int> ilst{1, 2, 3};
    std::vector<int> v2(ilst.cbegin(), ilst.cend());
    std::cout << (v0 == v2) << std::endl;

    return 0;
}
