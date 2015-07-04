// DATE : 06/17/15
// FILE : APAN:06.17.15.cpp
// DESC : Program in series of library algorithm APANs
//  1) Reorder
//  2) Permutations

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <deque>
#include <array>
#include <list>
#include <forward_list>
#include <initializer_list>
#include <cmath>
#include <utility>
#include <random>

template<typename T> void print(const T &obj, std::string name);
bool bigger(const char &ele1, const char &ele2);
bool less_than(const char &ele1, const char &ele2);
bool smaller(const char &ele1);
char gen() { return 'z'; }
unsigned gen_rand(unsigned val);

int main()
{
// Define sequences
    std::vector<char> cvec{'g','e','w','g','a','r','e'};
    std::string str = "Flexible length array of characters";
    std::deque<char> cdeq(cvec.cbegin(), cvec.cend());
    cdeq.insert(cdeq.end(), str.cbegin(), str.cend());
    std::array<char, 4> clarr{{'g','d','s','a'}};
    std::list<char> clst(7, 'd');
    std::forward_list<char> cflst(cdeq.rbegin(), cdeq.rend());
char carr[] = "char array";

// Print sequences
    print(cvec, "cvec");
    print(str, "str");
    print(cdeq, "cdeq");
    print(clarr, "clarr");
    print(clst, "clst");
    print(cflst, "cflst");
    print(carr, "carr");

// Invoke algorithms
    char val('u');
    std::random_shuffle(cvec.begin(), cvec.end());
    print(cvec, "cvec");

    std::random_shuffle(str.begin(), str.end(), gen_rand);
    print(str, "str");

    std::default_random_engine eng;
    std::shuffle(cdeq.begin(), cdeq.end(), eng);
    print(cdeq, "cdeq");

    std::vector<char> alpha0{'a', 'b', 'c'}, alpha1{'b', 'a', 'c'}, alpha2{'a', 'c', 'a'}, alpha3{'p', 'r', 'e', 'v'};
    std::cout << "alpha0 and alpha1 are permutations of the same sequence : " << is_permutation(alpha0.cbegin(), alpha0.cend(), alpha1.cbegin()) << std::endl;
    std::cout << "alpha0 and alpha2 are permutations of the same sequence : " << is_permutation(alpha0.cbegin(), alpha0.cend(), alpha2.cbegin()) << std::endl;

    std::cout << "alpha0 and alpha1 are permutations of the same sequence : " << is_permutation(alpha0.cbegin(), alpha0.cend(), alpha1.cbegin(), bigger) << std::endl;
    std::cout << "alpha0 and alpha2 are permutations of the same sequence : " << is_permutation(alpha0.cbegin(), alpha0.cend(), alpha2.cbegin(), bigger) << std::endl;

// Will print all permutations of given sequence
    std::cout << "permutations of alpha0\n";
    while(std::next_permutation(alpha0.begin(), alpha0.end())){
        for(auto ele : alpha0)
            std::cout << ele;
        std::cout << std::endl;
    }
    std::cout << std::endl;

    std::cout << "permutations of alpha1\n";
    while(std::next_permutation(alpha1.begin(), alpha1.end(), less_than)){
        for(auto ele : alpha1)
            std::cout << ele;
        std::cout << std::endl;
    }
    std::cout << std::endl;

// Will print all previous permutations of given sequence
    std::cout << "previous permutations of alpha2\n";
    while(std::prev_permutation(alpha2.begin(), alpha2.end())){
        for(auto ele : alpha2)
            std::cout << ele;
        std::cout << std::endl;
    }
    std::cout << std::endl;

    std::cout << "previous permutations of alpha3\n";
    while(std::prev_permutation(alpha3.begin(), alpha3.end(), less_than)){
        for(auto ele : alpha3)
            std::cout << ele;
        std::cout << std::endl;
    }

    return 0;
}

template<typename T> void print(const T &obj, std::string name)
{
    std::cout << name << ":\n";
    for(auto val : obj)
        std::cout << val << ", ";
    std::cout << std::endl;
}

bool smaller(const char &ele1)
{
    if(ele1 > 'g')
        return true;
    return false;
}

bool bigger(const char &ele1, const char &ele2)
{
    if(ele1 > ele2)
        return true;
    else
        return false;
}

bool less_than(const char &ele1, const char &ele2)
{
    if(ele1 > ele2)
        return true;
    else
        return false;
}

unsigned gen_rand(unsigned val)
{
    static std::default_random_engine eng;
    static std::uniform_int_distribution<unsigned> dis(0, val);
    return dis(eng);
}
