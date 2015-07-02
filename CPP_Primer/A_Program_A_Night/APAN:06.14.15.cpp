// DATE : 06/14/15
// FILE : APAN:06.13.15.cpp
// DESC : Program in series of library algorithm APANs
//  1) Partition and sorting

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
    char carr[] = "char array";

// Print sequences
    print(cvec, "cvec");
    print(str, "str");
    print(cdeq, "cdeq");
    print(clarr, "clarr");
    print(carr, "carr");

// Invoke algorithms
    char val('u');

    std::is_partitioned(cvec.cbegin(), cvec.cend(), smaller);
    print(cvec, "cvec");

    std::vector<char> pass(cdeq.size()), fail(cdeq.size());
    std::partition_copy(cdeq.cbegin(), cdeq.cend(), pass.begin(), fail.begin(), smaller);
    print(pass, "pass");
    print(fail, "fail");

    std::cout << "first element <= g : " << *std::partition_point(cdeq.cbegin(), cdeq.cend(), smaller) << std::endl;

    std::stable_partition(str.begin(), str.end(), smaller);
    print(str, "str");

    std::cout << "first element <= g : " << *std::partition(str.begin(), str.end(), smaller) << std::endl;

    std::sort(std::begin(carr), std::end(carr));
    print(carr, "carr");

    std::sort(clarr.begin(), clarr.end(), bigger);
    print(clarr, "clarr");

    std::stable_sort(cvec.begin(), cvec.end());
    print(cvec, "cvec");

    std::stable_sort(str.begin(), str.end(), bigger);
    print(str, "str");

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
