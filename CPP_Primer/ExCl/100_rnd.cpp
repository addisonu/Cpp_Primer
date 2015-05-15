// DATE : 05/14/15
// FILE : 100_rnd.cpp
// DESC : Write a program to generate 100 random integers between 1 and 100. It should generate exactly the same numbers each time you run it

#include <iostream>
#include <random>
#include <vector>

int main()
{
// Declare random-number engines
    std::default_random_engine e;
    std::uniform_int_distribution<unsigned> u(1, 100);

    std::vector<unsigned> uvec;

// Load numbers in uvec
    for(std::vector<unsigned>::size_type i = 0; i != 100; ++i){
        uvec.push_back(u(e));
    }

// Print elements in uvec
    for(auto val : uvec)
        std::cout << val << ", ";
    std::cout << std::endl;

    return 0;
}
