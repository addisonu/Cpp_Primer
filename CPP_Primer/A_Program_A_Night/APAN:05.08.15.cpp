// DATE : 05/08/15
// FILE : APAN:05.08.15.cpp
// DESC : Generate random numbers with library rand and random-number engines

#include <iostream>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <random>

int main()
{
// vectors to hold random numbers
    std::vector<unsigned> rvec, evec;

// setup rand and random-number engines
    srand(time(NULL));
    static std::default_random_engine e;
    static std::uniform_int_distribution<unsigned> u(1, 10);

// populate rvec with random numbers generated from rand
    for(std::vector<unsigned>::size_type i = 0; i != 10; ++i){

// Generate number from 1 - 10 inclusive
        if(i < 5)
            rvec.push_back(rand() % 10 + 1);

// Generate numbers within unsigned int range
        else
            rvec.push_back(rand());
    }
// populate evec with random numbers generated from e
    for(std::vector<unsigned>::size_type i = 0; i != 10; ++i){

// Generate number from 1 - 10 inclusive
        if(i < 5)
            evec.push_back(u(e));

// Generate numbers within unsigned int range
        else
            evec.push_back(e());
    }
// Print elements in rvec
    std::cout << "rvec : " << std::endl;
    for(auto val : rvec)
        std::cout << val << " ";

    std::cout << std::endl << std::endl;

// Print elements in evec
    std::cout << "evec : " << std::endl;
    for(auto val : evec)
        std::cout << val << " ";

    std::cout << std::endl;
    return 0;
}
