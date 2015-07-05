// DATE : 06/19/15
// FILE : APAN:06.19.15.cpp
// DESC : Program in series of algorithm APANs
//  1) Numeric

#include <iostream>
#include <numeric>
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
bool less_than(const int &ele1, const int &ele2);
template <typename T> T diff(const T &val1, const T &val2);
template <typename T> T mod(const T &val1, const T &val2);

int main()
{
// Sequence creation
    std::vector<int> ilvec = initialize<int>();
    std::vector<int> ivec(ilvec.cbegin(), ilvec.cend());

    constexpr int arr_sz(11);
    ilvec = initialize<int>(arr_sz);
    std::array<int, arr_sz> ilarr({1,2,3,4,5,6,7,8,9,50,61});

    ilvec = initialize<int>();
    std::list<int> ilst(ilvec.cbegin(), ilvec.cend());

    ilvec = initialize<int>();
    std::forward_list<int> iflst(ilvec.cbegin(), ilvec.cend());

    ilvec = initialize<int>();
    std::deque<int> ideq(ilvec.cbegin(), ilvec.cend());

    int iarr[]{1, 2, 3, 6, 5, 4, 3, 44, 5, 232, 45, 76, 654, 96, 687, 4, 65, 89,343, 23};

// Print
    print(ivec, "ivec");
    print(ilarr, "ilarr");
    print(ilst, "ilst");
    print(iflst, "iflst");
    print(ideq, "ideq");
    print(iarr, "iarr");

// Use algorithms
    int val1 = 85, val2 = 54;
    std::cout << "sum = " << std::accumulate(ivec.cbegin(), ivec.cend(), 0) << std::endl;
    std::cout << "difference = " << std::accumulate(ideq.cbegin(), ideq.cend(), 10, diff<int>) << std::endl;
    std::cout << "inner product = " << std::inner_product(ilarr.cbegin(), ilarr.cend(),ilst.cbegin(), 0) << std::endl;
    std::cout << "custom inner product = " << std::inner_product(iflst.cbegin(), iflst.cend(), std::begin(iarr), 777, mod<int>, diff<int>) << std::endl;

    std::vector<int> cpy(ilst.size()), cpy1(ivec.size());
    std::partial_sum(ilst.cbegin(), ilst.cend(), cpy.begin());
    print(cpy, "cpy");

    std::partial_sum(ivec.cbegin(), ivec.cend(), cpy1.begin(), diff<int>);
    print(cpy1, "cpy1");

    std::vector<int> cpy2(arr_sz), cpy3(20);
    std::adjacent_difference(ilarr.cbegin(), ilarr.cend(), cpy2.begin());
    print(cpy2, "cpy2");

    std::adjacent_difference(std::begin(iarr), std::end(iarr), cpy3.begin(), mod<int>);
    print(cpy3, "cpy3");

    print(iflst, "iflst");
    std::iota(iflst.begin(), iflst.end(), val1);
    print(iflst, "iflst");

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

bool less_than(const int &ele1, const int &ele2)
{
    if(ele1 < ele2)
        return true;
    else
        return false;
}

template <typename T> T diff(const T &val1, const T &val2)
{
    return std::abs(val1 - val2);
}

template <typename T> T mod(const T &val1, const T &val2)
{
    return val1 % val2;
}
