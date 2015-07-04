// DATE : 06/18/15
// FILE : APAN:06.18.15.cpp
// DESC : Program in series of library algorithm APANs
//  1) Set-like operations

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
    print(carr, "carr");

// Sort sequence prior to processing w/ algorithms
    std::sort(cvec.begin(), cvec.end());
    std::sort(str.begin(), str.end());
    std::sort(cdeq.begin(), cdeq.end());
    std::sort(clarr.begin(), clarr.end());
    std::sort(std::begin(carr), std::end(carr));

// Invoke algorithms

    char val('u');
    std::cout << std::boolalpha;
    std::cout << "cvec is a superset of cdeq : " << includes(cvec.cbegin(), cvec.cend(), cdeq.cbegin(), cdeq.cend()) << std::endl;
    std::cout << "cdeq is a superset of str : " << std::includes(cdeq.cbegin(), cdeq.cend(), str.cbegin(), str.cend(), less_than) << std::endl;

    std::vector<char> sunion(cvec.size() + cdeq.size());
    std::set_union(cvec.cbegin(), cvec.cend(), cdeq.cbegin(), cdeq.cend(), sunion.begin());
    print(sunion, "sunion");

    std::set_union(cvec.cbegin(), cvec.cend(), cdeq.cbegin(), cdeq.cend(), sunion.begin(), less_than);
    print(sunion, "sunion");

    std::vector<char> sintersect(str.size() + clarr.size());
    std::set_intersection(str.cbegin(), str.cend(), clarr.cbegin(), clarr.cend(), sintersect.begin());
    print(sintersect, "sintersect");

    std::set_intersection(str.cbegin(), str.cend(), clarr.cbegin(), clarr.cend(), sintersect.begin(), less_than);
    print(sintersect, "sintersect");

    std::vector<char> diff(clarr.size());
    std::set_difference(clarr.cbegin(), clarr.cend(), std::begin(carr), std::end(carr), diff.begin());
    print(diff, "diff");

    set_difference(clarr.cbegin(), clarr.cend(), std::begin(carr), std::end(carr), diff.begin(), less_than);
    print(diff, "diff");

    std::vector<char> sym(cvec.size() + str.size());
    std::set_symmetric_difference(cvec.cbegin(), cvec.cend(), str.cbegin(), str.cend(), sym.begin());
    print(sym, "sym");

    std::set_symmetric_difference(cvec.cbegin(), cvec.cend(), str.cbegin(), str.cend(), sym.begin(), less_than);
    print(sym, "sym");

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
