// DATE : 04/29/15
// FILE : APAN:04.29.15.cpp
// DESC : Using escape sequences output the string "Using escape sequences output the string"
// Every other char should be an escape sequence
// Use special char : newline, horizontal tab, alert bell

#include <iostream>
#include <string>

int main()
{
    std::string str = "\t\x55s\151n\x67 e\163c\x61p\145 s\x65q\165e\156c\145s\40o\x75t\160u\x74 \164h\x65 \163t\x72i\156g\n";
    std::cout << '\7' << str << std::endl;
    return 0;
}
