// DATE : 06/16/15
// FILE : APAN:06.16.15.cpp
// DESC : Program in series of library algorithm APANs
//  1) Reorder

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
bool smaller(const char &ele1);
char gen() { return 'z'; }

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
    std::remove(cvec.begin(), cvec.end(), val);
    print(cvec, "cvec");

    std::remove_if(str.begin(), str.end(), smaller);
    print(str, "str");

    std::vector<char> cpy(cdeq.size());
    std::remove_copy(cdeq.cbegin(), cdeq.cend(), cpy.begin(), val);
    print(cpy, "cpy");

    std::vector<char> cpy1(clarr.size());
    std::remove_copy_if(clarr.cbegin(), clarr.cend(), cpy1.begin(), smaller);
    print(cpy1, "cpy1");

    std::unique(cflst.begin(), cflst.end());
    print(cflst, "cflst");

    std::unique(cflst.begin(), cflst.end(), bigger);
    print(cflst, "cflst");

    std::vector<char> cpy2(clst.size());
    std::unique_copy(clst.cbegin(), clst.cend(), cpy2.begin());
    print(cpy2, "cpy2");

// Not implemented by compiler
    //std::vector<char> cpy3(clst.size());
    //std::unique_copy_if(clst.cbegin(), clst.cend(), cpy3.begin(), bigger);
    //print(cpy3, "cpy3");

    std::rotate(cvec.begin(), cvec.begin() + cvec.size() / 2, cvec.end());
    print(cvec, "cvec");

    std::string cpy4;
    std::rotate_copy(str.cbegin(), str.cbegin() + str.size() / 2, str.cend(), cpy4.begin());
    print(cpy4, "cpy4");

    std::reverse(str.begin(), str.end());
    print(str, "str");

    std::deque<char> cpy5(cdeq.size());
    std::reverse_copy(cdeq.cbegin(), cdeq.cend(), cpy5.begin());
    print(cpy5, "cpy5");

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
