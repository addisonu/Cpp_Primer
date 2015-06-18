// DATE : 06/09/15
// FILE : APAN:06.09.15.cpp
// DESC : Program in series of library algorithm APANs
//  1) Read-only algorithms requiring input iterators

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

template<typename T> void print(const T &obj, std::string name);
double max(double lhs, double rhs);
double min(double lhs, double rhs);

int main()
{
// Sequences to apply algorithms to
    std::vector<double> dvec(7, 3.14);
    dvec.push_back(2);
    std::deque<double> ddeq{5.5, 3.332, 2.32, 0.12, 54.45};
    std::array<double, 7> dlarr({7, 3, 4, 2.3, 2, 5, 3.33,});
    decltype(dlarr) cpdlarr = dlarr;
    std::list<double> dlst(ddeq.cbegin(), ddeq.cbegin() + ddeq.size() / 2);
    dlst.insert(dlst.cend(), ddeq.size() - dlst.size(), 7);
    std::forward_list<double> dflst(ddeq.cbegin() + ddeq.size() / 2, ddeq.cend());
    double darr[]{1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7};

    std::cout << std::boolalpha;

// Print sequences
    print(dvec, "dvec");
    print(ddeq, "ddeq");
    print(dlarr, "dlarr");
    print(cpdlarr, "cpdlarr");
    print(dlst, "dlst");
    print(dflst, "dflst");
    print(darr, "darr");

// Callable objects
    const double EPSILON = 0.0357; // maximum allowable difference between two elements to still be considered equal
    auto lam_eq7 = [] (double val) -> bool { return val == 7; };
    auto lam_even = [] (int val) -> bool { return (val % 2) == 0; };
    auto lam_odd = [] (int val) -> bool { if((val % 2) == 1) std::cout << val << " is odd.\n"; return (val % 2) == 1; };
    auto lam_near_eq = [EPSILON] (double val1, double val2) -> bool { return abs(val1 - val2) <= EPSILON; };

// Algorithms
    std::cout << "for_each :\n";
    std::for_each(dvec.cbegin(), dvec.cend(), lam_odd); // applies call object to each element in range, can modify elements

    /*std::pair<std::deque<double>::iterator, std::list<double>::iterator>*/ auto result0 = std::mismatch(ddeq.cbegin(), ddeq.cend(), dlst.cbegin()); // compares all elements, returns iterators to first elements in each sequence that don't match
    std::cout << "mismatch ele1 : " << *result0.first << std::endl;
    std::cout << "mismatch ele2 : " << *result0.second << std::endl;

    dflst.reverse();
    print(dflst, "dflst");
    auto result1 = std::mismatch(dflst.cbegin(), dflst.cend(), --ddeq.rend(), lam_near_eq);
    std::cout << "mismatch ele1 : " << *result1.first << std::endl;
    std::cout << "mismatch ele2 : " << *result1.second << std::endl;

    std::cout << "equal : " << std::equal(dlarr.cbegin(), dlarr.cend(), darr) << std::endl; // compares sequences for equality, returns true or false

    std::cout << "equal : " << std::equal(cpdlarr.cbegin(), cpdlarr.cend(), dlarr.cbegin(), max) << std::endl;

    return 0;
}

// Print any STL container
template<typename T> void print(const T &obj, std::string name)
{
    std::cout << name << ":" << std::endl;
    for(auto ele : obj)
        std::cout << ele << ", ";
    std::cout << std::endl;
}

// Binary operand functions
double max(double lhs, double rhs)
{
    if(lhs >= rhs)
        return lhs;
    else
        return rhs;
}

double min(double lhs, double rhs)
{
    if(lhs <= rhs)
        return lhs;
    else
        return rhs;
}
