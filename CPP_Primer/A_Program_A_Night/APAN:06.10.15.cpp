// DATE : 06/10/15
// FILE : APAN:06.10.15.cpp
// DESC : Program in series of library algorithm APANs
//  1) Write without read algorithms

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
template <typename T> T initialize(std::size_t sz = 1);
bool bigger(const int &ele1, const int &ele2);
bool smaller(char &ele1);
char gen() { return 'z'; }

int main()
{
// Define sequences
    std::vector<char> ivec{'g','e','w','g','a','r','e'};
    std::string str = "Flexible length array of characters";
    std::deque<char> cdeq(ivec.cbegin(), ivec.cend());
    cdeq.insert(cdeq.end(), str.cbegin(), str.cend());
    std::array<char, 4> clarr{{'g','d','s','a'}};
    std::list<char> clst(7, 'd');
    std::forward_list<char> cflst(cdeq.rbegin(), cdeq.rend());
    char carr[] = "char array";

// Print sequences
    print(ivec, "ivec");
    print(str, "str");
    print(cdeq, "cdeq");
    print(clarr, "clarr");
    print(clst, "clst");
    print(cflst, "cflst");
    print(carr, "carr");

// Invoke algorithms
    char val('u');
    std::fill(ivec.begin(), ivec.end(), val); // assigns val to each val in input sequence
    print(ivec, "ivec");

    std::fill_n(str.begin(), 3, val); // returns iterator following last element written
    print(str, "str");

    std::generate(cdeq.begin(), cdeq.begin() + 3, [val] () -> char { return val; });//initialize<char>); // assigns generated vales to input sequence
    print(cdeq, "cdeq");

    std::generate_n(clarr.begin(), clarr.size() / 2, gen); // returns iterator following last element written
    print(clarr, "clarr");

    std::vector<char> cpy(ivec.size());
    copy(ivec.cbegin(), ivec.cend(), cpy.begin());
    print(cpy, "cpy");

    copy_if(cflst.begin(), cflst.end(), cpy.begin(), smaller);
    print(cpy, "cpy");

    copy_n(clst.begin(), 7, cpy.begin());
    print(cpy, "cpy");

    move(ivec.cbegin(), ivec.cend(), cpy.begin()); //
    print(cpy, "cpy");

    return 0;
}

template<typename T> void print(const T &obj, std::string name)
{
    std::cout << name << ":\n";
    for(auto val : obj)
        std::cout << val << ", ";
    std::cout << std::endl;
}

template <typename T> T initialize(std::size_t sz)
{
    static std::default_random_engine e;
    static std::uniform_int_distribution<T> u(0, 255);
    return u(e);
}

bool smaller(char &ele1)
{
    if(ele1)
        return true;
    return false;
}

bool bigger(const int &ele1, const int &ele2)
{
    if(ele1 > ele2)
        return true;
    else
        return false;
}
