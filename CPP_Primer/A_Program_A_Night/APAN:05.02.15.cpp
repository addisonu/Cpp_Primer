// DATE : 05/02/15
// FILE : APAN:05.02.15.cpp
// DESC : Use type aliases to define multiple variables with compound base type

#include <iostream>

int main()
{
// ALIAS //
    typedef char *cstring;
    using cref = char (&)[4];

// Use cstring as base type
    char cstr[] = "This is a pointer to a c-style string.";
    cstring cstr1, *cstr2;
    cstr1 = cstr;
    cstr2 = &cstr1;
    std::cout << cstr1 << std::endl;
    std::cout << *cstr2 << std::endl;

// Use cref as base type
    char carr[4]{'a', 'b', 'c', '\0'};
    const cref ref1 = carr, ref2 = ref1;
    std::cout << ref1 << std::endl;
    std::cout << ref2 << std::endl;
    return 0;
}
