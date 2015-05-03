// DATE : 05/02/15
// FILE : APAN:05.02.15.cpp
// DESC : Use type aliases to define multiple variables with compound base type

#include <iostream>

int main()
{
// ALIAS //
    typedef char *cstring;
    using ref = char (&)[3];

    char cstr[] = "This is a pointer to a c-style string.";
    cstring cstr1, cstr2;
    cstr1 = cstr;
    cstr2 = cstr;
    std::cout << cstr << std::endl;
    return 0;
}
