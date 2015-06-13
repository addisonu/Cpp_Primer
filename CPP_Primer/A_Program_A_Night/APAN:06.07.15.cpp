// DATE : 06/07/15
// FILE : APAN:06.07.15.cpp
// DESC : Program in series of data structure APANs
//  1) Library array

#include <iostream>
#include <array>

template <typename T> void print(const T &obj, std::string name);

int main()
{
    std::cout << std::boolalpha;
    constexpr unsigned sizes[]{4, 5, 3, 8, 6};

// Construction
    std::cout << "Construction : " << std::endl;
    std::array<char, sizes[0]> arr0{}, arr0b{{'f', 'r', 's', 'r'}}; // default
    std::array<char, sizes[1]> arr1 = {'e', 'q', 'g', 't', 'e'}, arr1b({0 + 'a', 4 + 'a', 5 + 'a', 2 + 'a', 3 + 'a'}); // braced list
    std::array<char, sizes[2]> arr2({'d', 's', 'a'}), arr2b = {7, 7, 'u'};

// Print elements
    print(arr0, "arr0");
    print(arr0b, "arr0b");
    print(arr1, "arr1");
    print(arr1b, "arr1b");
    print(arr2, "arr2");
    print(arr2b, "arr2b");

// Type aliases
    std::array<char, sizes[0]>::iterator it0(arr0.begin()); // iterator
    std::array<char, sizes[1]>::const_iterator cit1(arr1.begin()); // const_iterator
    std::array<char, sizes[0]>::reverse_iterator rit0(--arr0.rbegin()); // iterator
    std::array<char, sizes[1]>::const_reverse_iterator crit1(--arr1.crbegin()); // const_reverse_iterator
std::array<char, sizes[1]>::size_type sz1 = arr1.size(); // size_type
    std::array<char, sizes[2]>::difference_type diff2 = arr2.cend() - arr2.cbegin(); // difference_type
    std::array<char, sizes[2]>::value_type val2 = arr2[0]; // value_type
    std::array<char, sizes[2]>::reference ref2 = arr2[1]; // reference
    std::array<char, sizes[2]>::const_reference cref2 =arr2[3]; // const_reference

// Print iterators
    std::cout << "it0 : " << *it0 << std::endl;
    std::cout << "rit0 : " << *rit0 << std::endl;
    std::cout << "cit1 : " << *cit1 << std::endl;
    std::cout << "crit1 : " << *crit1 << std::endl;

    std::cout << "val2 : " << val2 << std::endl;
    std::cout << "ref2 : " << ref2 << std::endl;
    std::cout << "cref2 : " << cref2 << std::endl;

// Size operations
    std::cout << "arr1.size : " << sz1 << std::endl;
    std::cout << "arr2 size : " << diff2 << std::endl; // number of elements in container
    std::cout << "arr0.max_size : " << arr0.max_size() << std::endl;// max number of elements container can hold
    std::cout << "arr1.max_size : " << arr1.max_size() << std::endl; // true if container empty, false otherwise
    std::cout << "arr2.max_size : " << arr2.max_size() << std::endl;

// Swap
    std::cout << "Assignment and swap : " << std::endl;
    arr0 = arr0b; // copy assignment of object
    arr1b = {'a', 'b', 'c', 'd'}; // copy assignment of braced list
    arr2.swap(arr2b); // member style swap
    swap(arr1, arr1b); // function style swap

// Print elements
    print(arr0, "arr0");
    print(arr0b, "arr0b");
    print(arr1, "arr1");
    print(arr1b, "arr1b");
    print(arr2, "arr2");
    print(arr2b, "arr2b");

// Relational operations
    std::cout << "Relational operations : " << std::endl;
    std::cout << "arr0 == arr0b : " << (arr0 == arr0b) << std::endl; // ==
    std::cout << "arr1 != arr1b : " << (arr1 != arr1b) << std::endl; // !=
    std::cout << "arr2 < arr2b : " << (arr2 < arr2b) << std::endl; // <
    std::cout << "arr2 <= arr2b : " << (arr2 <= arr2b) << std::endl; // <=
    std::cout << "arr1 > arr1b : " << (arr1 > arr1b) << std::endl; // >
    std::cout << "arr0 >= arr0b : " << (arr0 >= arr0b) << std::endl; // >=

    return 0;
}

template <typename T> void print(const T &obj, std::string name)
{
    std::cout << name << " : " << std::endl;
    for(auto val : obj)
        std::cout << val << ", ";
    std::cout << '\n' << std::endl;
}
