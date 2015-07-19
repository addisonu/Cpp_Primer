// DATE : 07/19/15
// FILE : APAN:07.19.15.cpp
// DESC : Moving backwards through a sequence with reverse iterators

#include <iostream>
#include <string>
#include <vector>

int main()
{
    std::vector<int> ivec{3, 32, 12, 4, 43, 7};
    std::string str("Concurrent access to the same stream.");

    std::vector<int>::const_reverse_iterator rvbeg = ivec.rbegin();
    std::vector<int>::const_reverse_iterator rvend = ivec.rend();

    for(; rvbeg != rvend; ++rvbeg)
        std::cout << *rvbeg << " ";
    std::cout << std::endl;

    auto rsbeg = str.crbegin();
    decltype(str.crbegin()) rsend = str.crend();

    while(rsbeg != rsend)
        std::cout << *rsbeg++;
    std::cout << std::endl;

    return 0;
}
