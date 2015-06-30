// DATE : 06/13/15
// FILE : APAN:06.13.15.cpp
// DESC : Program in series of library algorithm APANs
//  1) Write algorithms part II

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
    std::iter_swap(ivec.begin(), --ivec.end());
    print(ivec, "ivec");

    std::swap_ranges(str.begin(), str.end(), cdeq.begin());
    print(str, "str");
    print(cdeq, "cdeq");

    char old_val('d'), new_val('n');
    std::replace(clst.begin(), clst.end(), old_val, new_val);
    print(clst, "clst");

    std::replace_if(clarr.begin(), clarr.end(), smaller, new_val);
    print(clarr, "clarr");

    std::vector<char> cpy(20);
    std::copy_backward(ivec.cbegin(), ivec.cend(), cpy.end());
    print(cpy, "cpy");

    std::vector<char> cpy1(cdeq.size());
    std::move_backward(cdeq.cbegin(), cdeq.cend(), cpy1.end());
    print(cpy1, "cpy1");

    std::sort(str.begin(), str.end());
    std::inplace_merge(str.begin(), str.begin() + str.size() / 4 , str.end());
    print(str, "str");

    std::sort(ivec.begin(), ivec.end());
    print(ivec, "ivec");
    std::inplace_merge(ivec.begin(), ivec.end() - ivec.size() / 2, ivec.end(), bigger);
    print(ivec, "ivec");

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
    if(ele1 > 'g')
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
