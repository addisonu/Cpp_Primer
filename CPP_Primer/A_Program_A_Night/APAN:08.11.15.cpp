// DATE : 08/11/15
// FILE : APAN:08.11.15.cpp
// DESC : C++ primer exercises : 3.4, 3.5, 3.8. 3.10

#include <iostream>
#include <string>

int main()
{
// Ex 3.4
/*
    std::string str0, str1;
    std::cin >> str0 >> str1;

    if(str0 == str1)
        std::cout << "The strings are equal." << std::endl;
    else{
        std::cout << (str0 > str1 ? "str0 is larger." : "str1 is larger.") << std::endl;
        if(str0.size() == str1.size())
            std::cout << "The strings have the same length." << std::endl;
        else
            std::cout << (str0.size() > str1.size() ? "str0 is longer." : "str1 is longer") << std::endl;
    }

// Ex 3.5
// Read strings from the STDIN indefinitely
    std::string str, no_space, space;
    while(std::cin >> str){
// Concatenate all strings
        no_space += str;
        space += str + ' ';
    }
// Print the concatenated string
    std::cout << "String with no spaces : " << no_space << std::endl;

// Print the concatenated string separated by spaces
    std::cout << "String with spaces : " << space << std::endl;

// Ex
// Use a range for to change all char in a string to X
    std::string str("A string with no char equal to X");
    std::cout << "string pre transformation : " << str << std::endl;
    for(char &ch : str)
        ch = 'X';
    std::cout << "string post transformation : " << str << std::endl;

// Ex 3.8
// Rewrite Ex 3.5 using a while
    std::string str("A string with no char equal to X");
    auto beg = str.begin();
    std::string::iterator end = str.end();
    std::cout << "string pre transformation w/ while : " << str << std::endl;
    while(beg != end){
        *beg++ = 'X';
    }
    std::cout << "string post transformation w/ while : " << str << std::endl;

// Rewrite Ex 3.5 using a traditional for
    std::string str("A string with no char equal to X");
    std::cout << "string pre transformation w/ for : " << str << std::endl;
    for(decltype(str.size()) i = 0; i != str.size(); ++i){
        str[i] = 'X';
    }
    std::cout << "string post transformation w/ for : " << str << std::endl;

// Ex 3.10
// Read a string of char from STDIN
    char ch(' ');
    while(std::cin >> ch)
// Write what is read removing punctuation
        if(!ispunct(ch))
            std::cout << ch;
    std::cout << std::endl;
*/
    return 0;
}

