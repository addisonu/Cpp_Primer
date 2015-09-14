// DATE : 08/13/15
// FILE : APAN:08.13.15.cpp
// DESC : Cpp exercises 9.5

#include <iostream>
#include <vector>

int main()
{
// Ex 9.5
    std::vector<int> v0; //default initialized and empty
    std::vector<int> v1{1, 2, 3}; // list initialized
    std::vector<int> v2(v1); // direct initialized copy of v1
    std::vector<int> v3(v1.cbegin(), v1.cend()); // iterator range initializer
    std::vector<int> v4(10); // 10 value initialized elements
    std::vector<int> v5(10, 7); //10 copies of 7
    return 0;
}
