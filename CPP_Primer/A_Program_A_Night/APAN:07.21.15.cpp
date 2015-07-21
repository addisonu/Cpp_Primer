// DATE : 07/21/15
// FILE : APAN:07.21.15.cpp
// DESC : Use allocator class to allocate and deallocate unconstructed memory

#include <iostream>
#include <string>
#include <vector>
#include <memory>

int main()
{
// Create allocator objects
    std::allocator<int> ia;
    std::allocator<std::string> sa;

// Use allocator operations
    std::size_t isz(8);
    std::string::size_type ssz(12);
    int *ip;
    std::string *sp;
    ip = ia.allocate(isz); // allocates raw unconstructed memory to hold n objects of type
    sp = sa.allocate(ssz);
    ia.deallocate(ip, isz); // deallocates an object at address p tr holding val objects of type
    sa.construct(sp, "Allocated string"); // construct an object in memory with args pointed to by ptr
    std::cout << "*sp : " << *sp << std::endl;
    sa.destroy(sp); // run destructor on object pointed to by ptr

// Allocator algorithms
    ip = ia.allocate(isz);
    sp = sa.allocate(ssz);
    auto ip1 = ia.allocate(isz);
    decltype(sp) sp1 = sa.allocate(ssz);

    std::vector<int> ivec{3, 4, 5, 3, 12, 98, 565};
    std::vector<std::string> svec{"one", "two", "three", "four", "five", "six"};
    std::uninitialized_copy(ivec.cbegin(), ivec.cend(), ip); // copies elements from range into raw unconstructed memory
    std::uninitialized_copy_n(svec.cbegin(), 6, sp); // copies n elements starting from iterator beg into raw unconstructed memory
    std::uninitialized_fill(ip1, ip1 + isz, 77); // constructs object in raw memory denoted by range with copies of t
    std::uninitialized_fill_n(sp1, ssz / 2, "string"); // constructs n copies of t in raw memory denoted by beg

// Print elements
    std::cout << "ip : ";
    for(std::size_t i = 0; i != isz; ++i)
        std::cout << ip[i] << " ";
    std::cout << std::endl;

    std::cout << "ip1 : ";
    for(std::size_t i = 0; i != isz; ++i)
        std::cout << ip1[i] << " ";
    std::cout << std::endl;

    std::cout << "sp : ";
    for(std::size_t i = 0; i != ssz; ++i)
        std::cout << sp[i] << " ";
    std::cout << std::endl;

    std::cout << "sp1 : ";
    for(std::size_t i = 0; i != ssz; ++i)
        std::cout << sp1[i] << " ";
    std::cout << std::endl;

// Destroy constructed objects and deallocate allocated memory
    ia.destroy(ip);
    ia.deallocate(ip, isz);
    ia.destroy(ip1);
    ia.deallocate(ip1, isz);

    sa.destroy(sp);
    sa.deallocate(sp, ssz);
    sa.destroy(sp1);
    sa.deallocate(sp1, ssz);

    return 0;
}
