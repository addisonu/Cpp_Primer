// DATE : 06/12/15
// FILE : APAN:06.12.15.cpp
// DESC : Program in series of algorithm APANs
//  1) read from and write to sequences

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
int bigger(const int &ele1, const int &ele2);
int gen(const int &ele1);
bool even(const int &val);
bool greater(const int &val1, const int &val2);

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

    std::vector<int> cpy(20);
    std::move(ivec.cbegin(), ivec.cend(), cpy.begin()); //
    print(ivec, "ivec");
    print(cpy, "cpy");

    std::transform(ilarr.cbegin(), ilarr.cend(), cpy.begin(), gen); //
    print(cpy, "cpy");

    std::transform(ilst.cbegin(), ilst.cend(), iflst.cbegin(), cpy.begin(), bigger); //
    print(cpy, "cpy");

    int old_val = 867, new_val(888);
    replace_copy(ideq.cbegin(), ideq.cend(), cpy.begin(), old_val, new_val); //
    print(cpy, "cpy");

    replace_copy_if(ideq.cbegin(), ideq.cend(), cpy.begin(), even, new_val); //
    print(cpy, "cpy");

    std::sort(ivec.begin(), ivec.end());
    print(ivec, "ivec");
    std::sort(ideq.begin(), ideq.end());
    print(ideq, "ideq");

    std::vector<int> cpy1(40);
    merge(ivec.cbegin(), ivec.cend(), ideq.cbegin(), ideq.cend(), cpy1.begin()); //
    print(cpy1, "cpy1");

    merge(iflst.cbegin(), iflst.cend(), ilst.cbegin(), ilst.cend(), cpy1.begin(), greater); //
    print(cpy1, "cpy1");

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

int gen(const int &ele1)
{
    if(ele1)
        return ele1;
    return 0;
}

int bigger(const int &ele1, const int &ele2)
{
    if(ele1 > ele2)
        return ele1 + ele2;
    else
        return ele1 - ele2;
}

bool even(const int &val)
{
    return !(val % 2);
}

bool greater(const int &val1, const int &val2)
{
    return val1 > val2;
}
