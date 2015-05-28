// DATE : 05/26/15
// FILE : APAN:05.26.15.cpp
// DESC : Pass lambda as predicate to library algorithm

#include <iostream>
#include <numeric>
#include <algorithm>
#include <vector>
#include <string>

unsigned total(std::string str);

int main()
{
// Container objects to operator on
    std::vector<std::string> svec = {"ABCDEFG", "BCDEFGH", "CDEFGHI", "fhjsdfs"};
    std::vector<double> dvec{1.1,2.2,3.3,4.4};
    std::string str("Input string");

// stable sort will sort strings in ascending order according to the sum of the decimal values of each char
    stable_sort(svec.begin(), svec.end(), [ ] (std::string str_arg1,  std::string str_arg2) -> bool { return total(str_arg1) < total(str_arg2); });
    for(auto val : svec)
        std::cout << val << std::endl;

// find_if returns strings ending in 's'
    auto found = find_if(svec.cbegin(), svec.cend(), [] (std::string str_arg) -> bool { return *(--str_arg.cend()) == 's'; });
    std::cout << "found = ";
    for(auto val : *found)
         std::cout << val;
    std::cout << std::endl;

    return 0;
}

unsigned total(std::string str)
{
    unsigned sum(0);
    for(auto ele : str){
        sum += ele - 65;
    }
    return sum;
}
