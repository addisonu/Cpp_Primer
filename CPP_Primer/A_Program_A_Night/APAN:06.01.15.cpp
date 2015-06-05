// DATE : 06/01/15
// FILE : APAN:06.01.15.cpp
// DESC : Program in series of data structure APANs
//  1) array

#include <iostream>

int main()
{
// array object
    constexpr unsigned sz(5);
    double darr[sz]{2.3, 2.6, 7.4, 54.3};

// Iterator
    double *pdarr = darr;

// Operations
    std::cout << "*pdarr = " << *pdarr << std::endl; // dereference
    std::cout << "*(pdarr + 2) = " << *(pdarr + 2) << std::endl;// pointer addition
    std::cout << "pdarr[3] = " << pdarr[3] << std::endl; // pointer addition
    std::cout << "++pdarr = " << *++pdarr << std::endl; // increment
    std::cout << "pdarr-- = " << *pdarr-- << std::endl;// decrement
    std::cout << "(pdarr + 3) - pdarr = " << ((pdarr + 3) - pdarr) << std::endl; // difference type
    std::cout << "end(darr) - begin(darr) = " << (std::end(darr) - std::begin(darr)) << std::endl; // difference type
    std::cout << "(pdarr + 3)[-2] = " << (pdarr + 3)[-2] << std::endl;// subscript element with negative int
    std::cout << "begin(darr[sz] == end(darr) : " << (std::begin(darr)[sz] == *(std::end(darr))) << std::endl;// begin and end functions

// c-style character strings
// Constructors
    char carr0[sz + 10] = {'C', 'D', '0', 'f', '\0'};
    char carr1[sz] = {'C', 'D', 'e', 'f', '\0'};
    char carr2[] = "CD2e";
    char carr3[sz] = "CD3e";

// Operations
    std::cout << "strlen(carr0) = " << strlen(carr0) << std::endl;
    std::cout << "carr1 == carr2 : " << strcmp(carr1, carr2) << std::endl;
    std::cout << "carr0 + carr3 = " << strcat(carr0, carr3) << std::endl;
    std::cout << "carr2 = " << carr2 << std::endl;
    std::cout << "carr3 = " << carr3 << std::endl;
    std::cout << "carr3 = " << strcpy(carr3, carr2) << std::endl;
 return 0;
}

