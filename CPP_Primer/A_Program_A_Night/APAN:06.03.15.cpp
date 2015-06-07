// DATE : 06/03/15
// FILE : APAN:06.03.15.cpp
// DESC : Program in series of data structure APANs
//  1) vector

#include <iostream>
#include <vector>

int main()
{
// Constructors
    std::vector<int> ivec0; // default constructor
    std::vector<int> ivec1{1, 2, 3}; // constuctor with initializer list
    std::vector<int> ivec2(ivec1.begin(), ivec1.end()); // range constructor
    std::vector<int> ivec3(ivec2); // copy constructor

// Iterators
    std::cout << "Iterators" << std::endl;
    std::vector<int>::iterator fit = ivec1.begin(); // iterator to first element
    std::cout << "fit = " << *fit << std::endl;
    decltype(ivec1.cbegin()) clit = ivec1.cend() - 1; // const iterator to one past last element
    std::cout << "clit = " << *clit << std::endl;
    auto rlit = ivec2.rbegin(); // reverse iterator to last element
    std::cout << "rlit = " << *rlit << std::endl;
    std::vector<int>::const_reverse_iterator crfit = ivec3.crend() - 1; // const reverse iterator to of-the-end element
    std::cout << "crfit = " << *crfit << std::endl;

// Type aliases
    std::cout << "\nType aliases" << std::endl;
    std::vector<int>::size_type vsz = ivec1.size(); // hold size of largest possible container
    std::cout << "vsz = " << vsz << std::endl;
    std::vector<int>::difference_type vdiff = ivec1.end() - ivec1.begin(); // hold distance between two iterators
    std::cout << "vdiff = " << vdiff << std::endl;
    std::vector<int>::value_type val = ivec1[0]; // container element type
    std::vector<int>::reference vref = ivec2[0]; // reference to container element type
    std::cout << "vref = " << vref << std::endl;
    std::vector<int>::const_reference cvref = ivec3[0]; // const reference to container element type
    std::cout << "cvref = " << cvref << std::endl;

// Assignment and swap
    std::cout <<"\nAssignment and swap" << std::endl;
    ivec0 = ivec1; // copy assignment same type
    ivec1 = {5, 6, 4, 7, 3, 65}; // copy assignment braced list
    ivec1.swap(ivec2); // exchange elements
    for(auto val : ivec1)
        std::cout << val << ", ";
    std::cout << std::endl;

    for(decltype(ivec2[0]) val : ivec2)
        std::cout << val << ", ";
    std::cout << std::endl;

    swap(ivec2, ivec3); // alternate form of exchanging elements

    for(auto val : ivec2)
        std::cout << val << ", ";
    std::cout << std::endl;

    for(decltype(ivec3[0]) val : ivec3)
        std::cout << val << ", ";
    std::cout << std::endl;

// Size operations
    std::cout << "\nSize operations" << std::endl;
    std::cout << "ivec1.size() = " << ivec1.size() << std::endl; // return number of elements in container
    std::cout << "max_size of vector<int> is : " << ivec0.max_size() << std::endl; // return maximum number of elements container type can hold
    std::cout << std::boolalpha;
    std::cout << "ivec3.empty() : " << ivec3.empty() << std::endl; // return empty status

// Add/remove elements
    std::cout << "\nAdd/remove elements" << std::endl;
    std::cout << "ivec0 : " << std::endl;
    for(auto val : ivec0)
        std::cout << val << ", ";
    std::cout << std::endl;

    ivec0.insert(ivec0.end(), {11, 22, 33, 44, 55, 66}); // insert element(s)
    std::cout << "ivec0 : " << std::endl;
    for(auto val : ivec0)
        std::cout << val << ", ";
    std::cout << std::endl;

    std::cout << "ivec1 : " << std::endl;
    for(auto val : ivec1)
        std::cout << val << ", ";
    std::cout << std::endl;

    ivec1.emplace(ivec1.begin(), 77); // construct element(s) in container
    std::cout << "ivec1 : " << std::endl;
    for(auto val : ivec1)
        std::cout << val << ", ";
    std::cout << std::endl;

    std::cout << "ivec2 : " << std::endl;
    for(auto val : ivec2)
        std::cout << val << ", ";
    std::cout << std::endl;

    ivec2.erase(ivec2.begin() + ivec2.size() / 2 - 1, ivec2.begin() + ivec2.size() / 2 + 1); // remove element(s)

    std::cout << "ivec2 : " << std::endl;
    for(auto val : ivec2)
        std::cout << val << ", ";
    std::cout << std::endl;

    std::cout << "ivec3 : " << std::endl;
    for(auto val : ivec3)
        std::cout << val << ", ";
    std::cout << std::endl;

    ivec3.clear(); // remove all elements

    std::cout << "ivec3 : " << std::endl;
    for(auto val : ivec3)
        std::cout << val << ", ";
    std::cout << std::endl;

// Relational operations
    std::cout << "\nRelational operations" << std::endl;
    std::cout << "ivec0 == ivec1 : " << (ivec0 == ivec1) << std::endl; // lhs == rhs
    std::cout << "ivec1 != ivec2 : " << (ivec1 != ivec2) << std::endl; // lhs != rhs
    std::cout << "ivec2 < ivec3 : " << (ivec2 < ivec3) << std::endl; // lhs < rhs
    std::cout << "ivec3 <= ivec0 : " << (ivec3 <= ivec0) << std::endl; // lhs <= rhs
    std::cout << "ivec0 > ivec2 : " << (ivec0 < ivec2) << std::endl; // lhs > rhs
    std::cout << "ivec1 >= ivec3 : " << (ivec1 >= ivec3) << std::endl; // lhs >= rhs

    return 0;
}
