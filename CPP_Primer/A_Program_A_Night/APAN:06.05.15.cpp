// DATE : 06/05/15
// FILE : APAN:06.05.15.cpp
// DESC : Program in series of data structure APANs
//  1) Foward list

#include <iostream>
#include <forward_list>

int main()
{

    std::cout << std::boolalpha;
// Constructors
    std::forward_list<wchar_t> f1; // default
    std::forward_list<wchar_t> f2{'a', 'b', 'c'}; // initializer list
    std::forward_list<wchar_t> f3(f2);// copy
    std::forward_list<wchar_t> f4 = {'d', 'e', 'f'}; // initializer list
    std::forward_list<wchar_t> f5(f4.begin(), f4.end()); // range

// Type aliases
    std::forward_list<wchar_t>::iterator fit; //  iterator
    std::forward_list<wchar_t>::const_iterator cfit; //  const_iterator
    std::forward_list<wchar_t>::size_type sz; //  size_type
    std::forward_list<wchar_t>::difference_type diff; //  difference_type
    std::forward_list<wchar_t>::value_type val; //  value_type
    std::forward_list<wchar_t>::reference rval(f2.front()); //  reference
    std::forward_list<wchar_t>::const_reference crval = f4.front(); //  const_reference

// Print
    std::cout << "f1 : " << std::endl;
    for(auto ele : f1)
        std::cout << ele << ", ";
    std::cout << std::endl << std::endl;

    std::cout << "f2 : " << std::endl;
    for(auto ele : f2)
        std::cout << ele << ", ";
    std::cout << std::endl << std::endl;

    std::cout << "f3 : " << std::endl;
    for(auto ele : f3)
        std::cout << ele << ", ";
    std::cout << std::endl << std::endl;

    std::cout << "f4 : " << std::endl;
    for(auto ele : f4)
        std::cout << ele << ", ";
    std::cout << std::endl << std::endl;

    std::cout << "f5 : " << std::endl;
    for(auto ele : f5)
        std::cout << ele << ", ";
    std::cout << std::endl << std::endl;

// Iterators
    fit = f2.begin(); // iterator
    std::cout << "fit = " << *fit << std::endl;
    cfit = f4.begin(); // const_iterator
    std::cout << "cfit = " << *cfit << std::endl << std::endl;

// Assignment and swap
    f2 = {'g', 'e', 'h'}; // copy of braced list
    f1 = f2; // copy assignement

    std::cout << "after f1.swap(f3)" << std::endl;
    f1.swap(f3); // swap call member style
    std::cout << "f1 : " << std::endl;
    for(auto ele : f1)
        std::cout << ele << ", ";
    std::cout << std::endl << std::endl;

    std::cout << "f3 : " << std::endl;
    for(auto ele : f3)
        std::cout << ele << ", ";
    std::cout << std::endl << std::endl;

    std::cout << "after f3.swap(f4)" << std::endl;
    swap(f3, f4); // swap call function style
    std::cout << "f3 : " << std::endl;
    for(auto ele : f3)
        std::cout << ele << ", ";
    std::cout << std::endl << std::endl;

    std::cout << "f4 : " << std::endl;
    for(auto ele : f4)
        std::cout << ele << ", ";
    std::cout << std::endl << std::endl;

// Size
    std::cout << "forward_list can hold " << f1.max_size() << " elements. " << std::endl; // max_size of container
    std::cout << "f2.empty : " << f2.empty() << std::endl << std::endl;// empty

// Add and remove elements
    std::cout << "f1.insert_after." << std::endl;
    f1.insert_after(f1.cbefore_begin(), 'i'); // insert
    std::cout << "f1 : " << std::endl;
    for(auto ele : f1)
        std::cout << ele << ", ";
    std::cout << std::endl << std::endl;

    std::cout << "f2.insert_after." << std::endl;
    f2.insert_after(f2.before_begin(), 2, 't');
    std::cout << "f2 : " << std::endl;
    for(auto ele : f2)
        std::cout << ele << ", ";
    std::cout << std::endl << std::endl;

    std::cout << "f3.insert_after." << std::endl;
    f3.insert_after(f3.cbefore_begin(), f1.begin(), f1.end());
    std::cout << "f3 : " << std::endl;
    for(auto ele : f3)
        std::cout << ele << ", ";
    std::cout << std::endl << std::endl;

    std::cout << "f4.insert_after." << std::endl;
    f4.insert_after(f4.cbefore_begin(), {'1', '5', 'h', 'd', 'e'});
    std::cout << "f4 : " << std::endl;
    for(auto ele : f4)
        std::cout << ele << ", ";
    std::cout << std::endl << std::endl;

    std::cout << "f5.emplace_after." << std::endl;
    f5.emplace_after(f5.cbefore_begin(), 'u');// emplace
    std::cout << "f5 : " << std::endl;
    for(auto ele : f5)
        std::cout << ele << ", ";
    std::cout << std::endl << std::endl;

    std::cout << "f2.erase_after." << std::endl;
    f2.erase_after(f2.cbegin()); // erase
    std::cout << "f2 : " << std::endl;
    for(auto ele : f2)
        std::cout << ele << ", ";
    std::cout << std::endl << std::endl;

    std::cout << "f4.erase_after." << std::endl;
    f4.erase_after(f4.cbefore_begin(), ++(++f4.before_begin()));
    std::cout << "f4 : " << std::endl;
    for(auto ele : f4)
        std::cout << ele << ", ";
    std::cout << std::endl << std::endl;

    std::cout << "f5.clear." << std::endl;
    f5.clear(); // erase all elements
    std::cout << "f5 : " << std::endl;
    for(auto ele : f5)
        std::cout << ele << ", ";
    std::cout << std::endl << std::endl;

// Relational operations
    std::cout << "(f1 == f2)" << (f1 == f2) << std::endl; // ==
    std::cout << "(f2 != f3)" << (f2 != f3) << std::endl; // !=
    std::cout << "(f3 <= f4)" << (f3 <= f4) << std::endl;// <=
    std::cout << "(f4 < f5)" << (f4 < f5) << std::endl;// <
    std::cout << "(f5 >= f1)" << (f5 >= f1) << std::endl;// >=
    std::cout << "(f1 > f3)" << (f1 > f3) << std::endl;// >
    return 0;
}
