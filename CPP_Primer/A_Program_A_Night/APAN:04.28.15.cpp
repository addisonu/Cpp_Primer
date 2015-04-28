// DATE : 04/26/15
// FILE : APAN:04.28.15.cpp
// DESC : Convert string to a single case
// 1) Convert c_style string to lowercase with for loop
// 2) Convert library string to uppercase with while loop
// 3) Make use of
//  - operator.
//  - operator->
//  - operator*
//  - operator&

#include <string>
#include <iostream>
#include <cstring>
#include <cctype>

int main()
{
// Process c-style string
    char cstr[] = "A StRinG thAT will HaVe all charactERS chaNgEd tO LowerCase";
    std::cout << std::endl;
    std::cout << "original cstring : " << cstr << std::endl;

// iterate through char
    for(char *pstr = cstr; pstr != std::end(cstr); ++pstr){

// dereference control var and call tolower
        *pstr = tolower(*pstr);
    }
    std::cout << "result cstring : " << cstr << std::endl;
    std::cout << std::endl;

// Process library string
    std::string str = "A StRinG thAT will HaVe all charactERS chaNgEd tO UpperCase";
    std::cout << "original string : " << str << std::endl;

// define iterator to first element
    std::string::iterator it = str.begin();
    std::string *pstr2 = &str;

// iterate through elements with loop
    if(!pstr2->empty()){
        while(it != str.end()){

// dereference iterator and call toupper
            *it = toupper(*it);

// move to next char
            ++it;
        }
    }
    std::cout << "result string : " << str << std::endl;
    std::cout << std::endl;
    return 0;
}
