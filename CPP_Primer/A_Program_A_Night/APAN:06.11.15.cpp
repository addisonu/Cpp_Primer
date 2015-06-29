// DATE : 06/11/15
// FILE : APAN:06.11.15.cpp
// DESC : Program in series of algorithm APANs

#include <iostream>
#include <utility>
#include <random>
#include <algorithm>
#include <vector>
#include <string>
#include <list>
#include <forward_list>
#include <deque>
#include <array>
#include <initializer_list>

template <typename T> void print(T &obj, std::string name);
template <typename T> std::vector<T> initialize(std::size_t sz = 20);
bool bigger(const int &ele1, const int &ele2);
bool smaller(const int &ele1, const int &ele2);

int main()
{
// Sequence creation
    std::vector<int> ilvec = initialize<int>();
    std::vector<int> ivec(ilvec.cbegin(), ilvec.cend());

    constexpr int arr_sz(11);
    ilvec = initialize<int>(arr_sz);
    std::array<int, arr_sz> ilarr({1,2,3,4,5,6,7,8,9,50,61});

    std::string str("not an int");

    ilvec = initialize<int>();
    std::list<int> ilst(ilvec.cbegin(), ilvec.cend());

    ilvec = initialize<int>();
    std::forward_list<int> iflst(ilvec.cbegin(), ilvec.cend());

    ilvec = initialize<int>();
    std::deque<int> ideq(ilvec.cbegin(), ilvec.cend());

// Print
    print(ivec, "ivec");
    print(ilarr, "ilarr");
    print(str, "str");
    print(ilst, "ilst");
    print(iflst, "iflst");
    print(ideq, "ideq");

// Use algorithms
    int val = 85;
    std::cout << "ilarr upper_bound : " << *std::upper_bound(ilarr.cbegin(), ilarr.cend(), val) << std::endl; // returns iterator to first element val <=
    std::cout << "ivec upper_bound : "<< *std::upper_bound(ivec.cbegin(), ivec.cend(), val, [] (int ele1, int ele2){ return ele1 < ele2; }) << std::endl;
    std::cout << "ilst lower_bound : " << *std::lower_bound(ilst.cbegin(), ilst.cend(), val, bigger) << std::endl; // returns iterator to first element val >=
    iflst.sort();
    std::cout << "iflst lower_bound : " << *std::lower_bound(iflst.cbegin(), iflst.cend(), val, smaller) << std::endl;
    std::pair<std::deque<int>::const_iterator, std::deque<int>::const_iterator> result(std::equal_range(ideq.cbegin(), ideq.cend(), val)); // returns pair of iterators equal to lower_bound and upper_bound respectively
    std::cout << "ideq equal_range : " << *result.first << " " << *result.second << std::endl;
    std::pair<std::vector<int>::iterator, std::vector<int>::iterator> result2(std::equal_range(ivec.begin(), ivec.end(), val, smaller));
    std::cout << "ivec equal_range : " << *result2.first << " " << *result2.second << std::endl;
    val = 208;
    std::cout << "iflst binary_search : " << std::binary_search(iflst.cbegin(), iflst.cend(), val, smaller) << std::endl; // returns true if val is contained in sequence, false otherwise
    val = 61;
    std::cout << "ilarr binary_search : " << std::binary_search(ilarr.cbegin(), ilarr.cend(), val) << std::endl;

    return 0;
}

template <typename T> void print(T &obj, std::string name)
{
    std::cout << name << " :\n";
    for(auto val : obj)
        std::cout << val << ", ";
    std::cout << '\n' << std::endl;
}

template <typename T> std::vector<T> initialize(std::size_t sz)
{
    static std::default_random_engine e;
    static std::uniform_int_distribution<T> u(0, 1000);
    std::vector<T> ilvec;
    for(std::size_t i = 0; i != sz; ++i)
        ilvec.push_back(u(e));
    return ilvec;
}

bool smaller(const int &ele1, const int &ele2)
{
    if(ele1 < ele2)
        return true;
    else
        return false;
}

bool bigger(const int &ele1, const int &ele2)
{
    if(ele1 > ele2)
        return true;
    else
        return false;
}
