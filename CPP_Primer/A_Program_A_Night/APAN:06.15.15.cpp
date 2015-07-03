// DATE : 06/15/15
// FILE : APAN:06.15.15.cpp
// DESC : Program in series of algorithm APANs
//  1) Sorting (requires random access iterator)

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

    int iarr[]{1, 5, 34, 64, 75, 3, 43, 797, 3, 54, 29, 53, 89, 86, 23, 86, 90, 30, 20, 18, 27};

// Print
    print(ivec, "ivec");
    print(ilarr, "ilarr");
    print(ideq, "ideq");
    print(iarr, "iarr");

// Use algorithms
    int val = 155;
    std::cout << std::boolalpha;
    std::cout << "ivec sorted? " << std::is_sorted(ivec.cbegin(), ivec.cend()) << std::endl;
    std::sort(ivec.begin(), ivec.end());
    std::cout << "ivec sorted? " << std::is_sorted(ivec.cbegin(), ivec.cend()) << std::endl;

    std::cout << "ilarr sorted? " << std::is_sorted(ilarr.cbegin(), ilarr.cend(), bigger) << std::endl;

    std::cout << "iarr sorted until? " << *std::is_sorted_until(std::begin(iarr), std::end(iarr)) << std::endl;

    std::cout << "ideq sorted until? " << *std::is_sorted_until(ideq.cbegin(), ideq.cend(), smaller) << std::endl;

    std::reverse(ilarr.begin(), ilarr.end());
    std::partial_sort(ilarr.begin(), ilarr.begin() + ilarr.size() / 2, ilarr.end());
    print(ilarr, "ilarr");

    std::partial_sort(ideq.begin(), ideq.begin() + ideq.size() / 2, ideq.end(), smaller);
    print(ideq, "ideq");

    std::vector<int> cpy0(ivec.size());
    std::reverse(ivec.begin(), ivec.end());
    std::partial_sort_copy(ivec.cbegin(), ivec.cend(), cpy0.begin(), cpy0.end());
    print(cpy0, "cpy0");

    std::reverse(ideq.begin(), ideq.end());
    std::partial_sort_copy(ideq.cbegin(), ideq.cend(), cpy0.begin(), cpy0.end(), smaller);
    print(cpy0, "cpy0");

    std::nth_element(ivec.begin(), ivec.begin() + ivec.size() / 2, ivec.end());
    print(ivec, "ivec");

    std::nth_element(ideq.begin(), ideq.begin() + ideq.size() / 2, ideq.end(), smaller);
    print(ideq, "ideq");

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
