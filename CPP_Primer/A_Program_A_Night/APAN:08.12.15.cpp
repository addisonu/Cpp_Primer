// DATE : 08/12/15
// FILE : APAN:08.12.15.cpp
// DESC : Cpp primer exercises 9.4

#include <vector>
#include <iostream>

bool value_found(std::vector<int>::iterator beg, std::vector<int>::iterator end    , int val);
std::vector<int>::iterator value_found_it(std::vector<int>::iterator beg, std::vector<int>::iterator end , int val);

int main()
{
// Ex 9.4
    int val(8);
    std::vector<int> ivec{1, 4, 3, 4, 5, 22, 6, 9, 4, 3};
    std::cout << std::boolalpha;
    std::cout << "Is the val in ivec? " << value_found(ivec.begin(), ivec.end(), val) << std::endl;
    auto result = value_found_it(ivec.begin(), ivec.end(), val);
    std::cout << "Is the val in ivec? " << (result == ivec.end() ? "false" : "true") << std::endl;
        return 0;
}

bool value_found(std::vector<int>::iterator beg, std::vector<int>::iterator end, int val)
{
    while(beg != end){
        if(*beg == val)
            return true;
        ++beg;
    }
    return false;
}

std::vector<int>::iterator value_found_it(std::vector<int>::iterator beg, std::vector<int>::iterator end, int val)
{
    while(beg != end){
        if(*beg == val)
            return beg;
        ++beg;
    }
    return end;
}
