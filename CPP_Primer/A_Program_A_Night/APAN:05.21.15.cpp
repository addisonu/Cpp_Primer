// DATE : 05/21/15
// FILE : APAN:05.21.15.cpp
// DESC : Use strings

#include <iostream>
#include <string>
#include <cctype>

using std::string;

int main()
{
// String constructors
    string s0 = "String0";
    string s1;
    string s2(s0);
    string s3 = s2;
    string s4("string4");
    string s5 = "string5";
    string s6(6,'s');

// String operations
    std::cout << s0 << std::endl; // write to ostream
    std::cin >> s1; // read from istream
    std::cout << s1 << std::endl;
    std::getline(std::cin, s1); // remove residual char from cin
    std::cin.clear(); // clear cin flags
    getline(std::cin, s2); // read line from istream
    std::cout << s2 << std::endl;
    std::cout << std::boolalpha; // print 0 or 1 as true or false
    std::cout << "s3.empty() : " << s3.empty() << std::endl; // check if s3 holds any char
    std::cout << "s4.size() : " << s4.size() << std::endl; // return size of s4
    std::cout << "s5[0] : " << (!s5.empty() ? s5[0] : ' ') << std::endl; // print first element in s5
    std::cout << "s4 + s5 : " << (s4 + s5) << std::endl; // print concatenation of s4 and s5
    s5 = s6; // assign s6 to s5
    std::cout << "s6 : " << s6 << std::endl;
    std::cout << "s5 : " << s5 << std::endl;
    std::cout << "s5 == s6 : " << (s5 == s6) << std::endl; // check if s5 and s6 are equal
    std::cout << "s4 == s5 : " << (s4 == s5) << std::endl;
    std::cout << "s5 != s6 : " << (s5 != s6) << std::endl; // check if s5 and s6 are unequal
    std::cout << "s4 != s5 : " << (s4 != s5) << std::endl;
    std::cout << " s0 < s1 : " << (s0 < s1) << std::endl; // use relational operators to compare two strings
    std::cout << " s2 <= s1 : " << (s2 <= s1) << std::endl;
    std::cout << " s4 > s3 : " << (s4 > s3) << std::endl;
    std::cout << " s5 >= s6 : " << (s5 >= s6) << std::endl;

// String char functions
    std::cout << "isalnum(s5[0]) : " << isalnum(s5[0]) << std::endl; // check if alphanumeric
    std::cout << "isalpha(s5[0]) : " << isalpha(s5[0]) << std::endl; // check if alpha
    std::cout << "iscntrl(s5[0]) : " << iscntrl(s5[0]) << std::endl; // check if control character
    std::cout << "isdigit(s5[0]) : " << isdigit(s5[0]) << std::endl; // check if is digit
    std::cout << "isgraph(s5[0]) : " << isgraph(s5[0]) << std::endl; // check if is graph character
    std::cout << "ispunct(s5[0]) : " << ispunct(s5[0]) << std::endl; // check if is punctuation
    std::cout << "islower(s5[0]) : " << islower(s5[0]) << std::endl; // check if is lowercase
    std::cout << "isspace(s3[0]) : " << isspace(s3[0]) << std::endl; // check if is space
    std::cout << "isupper(s3[0]) : " << isupper(s3[0]) << std::endl; // check if is uppercase
    std::cout << "isxdigit(s3[0]) : " << isxdigit(s3[0]) << std::endl; // check if is hexadecimal digit
    std::cout << "tolower(s3[1]) : " << s3  << std::endl; // transform char to lowercase
    s3[0] = tolower(s3[0]);
    std::cout << s3 << std::endl;
    std::cout << "toupper(s5[0]) : " << s5 << std::endl; // transform char to uppercase
    s5[0] = toupper(s5[0]);
    std::cout << s5 << std::endl;

    return 0;
}
