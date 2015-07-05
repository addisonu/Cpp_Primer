// DATE : 06/19/15
// FILE : APAN:06.19.15.cpp
// DESC : Program in series of algorithm APANs
//  1) Min and Max values

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
bool less_than(const int &ele1, const int &ele2);

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

    int iarr[]{1, 2, 3, 6, 5, 4};

// Print
    print(ivec, "ivec");
    print(ilarr, "ilarr");
    print(ilst, "ilst");
    print(iflst, "iflst");
    print(ideq, "ideq");

// Use algorithms
    int val1 = 85, val2 = 54;

// Following algorithms operate on values
    std::cout << "min = " << std::min(val1, val2) << std::endl; // val1 and val2 must have exactly the same type, return val is ref to const of the value
    std::cout << "min = " << std::min(val1, val2, less_than) << std::endl;
    std::cout<< "min = " << std::min({4, 3, 77, 5, 6}) << std::endl;
    std::cout << "min = " << std::min({4, 3, 89, 4, 5}, less_than) << std::endl;
    std::cout << "max = " << std::max(val1, val2) << std::endl;

    std::cout << "max = " << std::max(val1, val2, less_than) << std::endl;
    std::cout << "max = " << std::max({3, 5, 45, 33, 993, 32}) << std::endl;
    std::cout << "max = " << std::max({3, 6, 44, 6, 4455, 34}, less_than) << std::endl;

// Following algorithms operate on sequences
    std::pair<int, int> result;
    result = std::minmax(val1, val2); // returns pair with min as first and max as second
    std::cout << "min = " << result.first << ", max = " << result.second << std::endl;
    result = std::minmax(val1, val2, less_than);
    std::cout << "min = " << result.first << ", max = " << result.second << std::endl;
    result = std::minmax({4, 55, 6, 34, 656, 75});
    std::cout << "min = " << result.first << ", max = " << result.second << std::endl;
    result = std::minmax({5, 66, 55, 3, 454}, less_than);
    std::cout << "min = " << result.first << ", max = " << result.second << std::endl;
    std::cout << "min = " << *std::min_element(ivec.cbegin(), ivec.cend()) << std::endl; // returns iterator to largest/smallest element
    std::cout << "min = " << *std::min_element(ideq.cbegin(), ideq.cend(), less_than) << std::endl;
    std::cout << "max = " << *std::max_element(ilarr.cbegin(), ilarr.cend()) << std::endl;
    std::cout << "max = " << *std::max_element(std::begin(iarr), std::end(iarr), less_than) << std::endl;
    std::pair<int *, int *> result1 = std::minmax_element(ilarr.begin(), ilarr.end()); // returns pair, with min as first and max as second
    std::cout << "min = " << *result1.first << ", max = " << *result1.second << std::endl;
    result1 = std::minmax_element(std::begin(iarr), std::end(iarr), less_than);
    std::cout << "min = " << *result1.first << ", max = " << *result1.second << std::endl;

// Compare using dictionary ordering
    std::cout << "is ivec < ideq? " << std::lexicographical_compare(ivec.cbegin(), ivec.cend(), ideq.cbegin(), ideq.cend()) << std::endl;
    std::cout << "is ilst < iflst? " << std::lexicographical_compare(ilst.cbegin(), ilst.cend(), iflst.cbegin(), iflst.cend(), less_than) << std::endl;
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
