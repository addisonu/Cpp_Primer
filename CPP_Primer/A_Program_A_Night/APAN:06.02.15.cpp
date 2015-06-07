// DATE : 06/02/15
// FILE : APAN:06.02.15.cpp
// DESC : Program in series of data structure APANs
//  1) string

#include <iostream>
#include <string>

int main()
{
// Constructors
    std::string s0;
    std::string s1("String1");
    std::string s2(s1);
    std::string s3 = s2;
    std::string s4 = "string4";
    std::string s5(5, 's'); // construct with 5 copies of 's'
    std::string s6(s5, 3); // construct as copy of s5 of first 3 elements
    std::string s7(s4, s4.size()/2); //
    std::string s8(s4, (s4.size()/2), s4.size()); // construct as a copy of s4 starting from index arg with length arg

// Type aliases
    std::string::iterator sti(s1.begin()); // iterator from first element
    std::string::const_iterator csti(s1.cbegin()); // const
    std::string::reverse_iterator rsti(s2.rbegin()); // reverse iterator starting from last element
    std::string::const_reverse_iterator crsti(s2.crbegin()); // const
    std::string::size_type sz = s3.size();
    std::string::difference_type diff = s4.cend() - s4.cbegin();
    std::string::value_type obj; // type of element contained
    const std::string::value_type cobj = 'c'; // const value_type
    std::string::reference robj = obj; // reference to value_type
    std::string::const_reference crobj = cobj; // const reference

// Operations

// Access
    std::cout << std::boolalpha;
    std::cout << "s3[1] = " << s3[1] << std::endl;// access with subscript
    if(!s1.empty())
        std::cout << "s1[s1.size() - 1] = " << s1.back() << std::endl; // get reference to last element
    if(!s2.empty())
        std::cout << "s2[0] = " << s2.front() << std::endl; // get reference to first element
    try{
        std::cout << "s3[2] = " << s3.at(2) << std::endl; // get access to any element, if invalid exception will be thrown
    }
    catch(std::out_of_range e){
        std::cout << "s3 is the empty string." << std::endl;
    }
// Modification
    std::cout << "s0 : " << (s0 = s5) << std::endl; // assignment
    swap(s0, s4); // swap elements
    std::cout << "s0 : " << s0 << std::endl;

// Size information
    std::cout << "s5.size() = " << s5.size() << std::endl;// get number of elements
    std::cout << "s5.capacity() = " << s5.capacity() << std::endl; // get number of elements container has space for
    std::cout << "s5 max_size() = " << s5.max_size() << std::endl; // get number greater than or equal to max number of elements container can hold
    std::cout << "s0.empty() : " << s0.empty() << std::endl;// has elements

// Add/remove/replace single or range of elements
    s0.push_back('A'); // insert new element
    s0.insert(s0.end(), 'B'); // insert new element
    s0.insert(s0.end(), s5.begin(), s5.end());
    std::cout << "s0 = " << s0 << std::endl;
    s0.pop_back(); // remove last element
    std::cout << "s0 = " << s0 << std::endl;
    s0.erase(s0.begin());
    std::cout << "s0 = " << s0 << std::endl;
    s0.clear();
    std::cout << "s0 = " << s0 << std::endl;
    s1.erase(++s1.begin(), --s1.end());// erase a range
    std::cout << "s1 = " << s1 << std::endl;

// Change or set size
    std::cout << "s2 = " << s2 << std::endl;
    std::cout << "s2.capacity() : " << s2.capacity() << std::endl;
    std::cout << "s2.size() : " << s2.size() << std::endl;
    s2.resize(s2.size() + 1); // resize string
    std::cout << "s2.capacity() : " << s2.capacity() << std::endl;
    std::cout << "s2.size() : " << s2.size() << std::endl;
    s2.shrink_to_fit();
    s2.reserve(s2.size() + 2);
    std::cout << "s2.capacity() : " << s2.capacity() << std::endl;
    std::cout << "s2.size() : " << s2.size() << std::endl;
    std::cout << "s2 = " << s2 << std::endl;
    s3.resize(s1.size() - 1);
    s0.resize(s0.size() + 1, 'n');
    std::cout << "s0.size() = " << s0.size() << std::endl;
    std::cout << "s6.substr() : " << s6.substr(0, s6.size()/2) << std::endl;// print substring
    s2.assign(s3);
    std::cout << "s2 : " << s2 << std::endl; // replace all elements of existing container with elements from args
    std::cout << "s3 = " << s3.append(s4) << std::endl;// append args to end of existing container
    std::cout << "s4 = " << s4.replace(s4.begin(), s4.begin() + s4.size()/2, "replace") << std::endl; // replace specified elements with elements from args

// Search for element(s)
    std::cout << "pos = " << s4.find('a') << std::endl; // find first
    std::cout << "pos = " << s4.rfind('e') << std::endl; // find last
    std::cout << "pos = " << s6.find_first_of("berioua") << std::endl; // find first of any char from args
    std::cout << "pos = " << s4.find_last_of("gfdqa") << std::endl; // find last of any char from args
    std::cout << "pos = " << s7.find_first_not_of("fdajw") << std::endl; // find first char not in args
    std::cout << "pos = " << s7.find_last_not_of("czdvl") << std::endl; // find last char not in args

// Relational operations
    std::cout << "s0 < s1 : " << (s0 < s1) << std::endl; // lhs < rhs
    std::cout << "s1 <= s2 : " << (s1 <= s2) << std::endl; // lhs <= rhs
    std::cout << "s2 > s3 : " << (s2 > s3) << std::endl; // lhs > rhs
    std::cout << "s3 >= s4 : " << (s3 >= s4) << std::endl;  // lhs >= rhs
    std::cout << "s5 != s6 : " << (s5 != s6) << std::endl; // lhs != rhs
    std::cout << "s7 == s8 : " << (s7 == s8) << std::endl; // llhs == rhs

// Iterators
    std::cout << "sti : " << *sti << std::endl; // print first element with iterator
    std::cout << "csti : " << *csti << std::endl; // const
    std::cout << "rsti : " << *rsti << std::endl; // print last element with reverse iterator
    std::cout << "crsti : " << *crsti << std::endl; // const reverse

// Compare strings
    std::cout << "result : " << s0.compare(s1) << std::endl; // compare two strings
    std::cout << "result : " << s1.compare(0, s1.size() / 2, s2) << std::endl; // compare n char of two strings starting at postion
    std::cout << "result : " << s2.compare(0, s2.size() / 2, s3, s3.size() / 2 - 1, s3.size()) << std::endl; // compare n1 char from pos1 in string1 and n2 char from pos2 in string2
    std::cout << "result : " << s3.compare("compare_string3") << std::endl;
    std::cout << "result : " << s4.compare(0, s4.size() / 2, "compare_string4") << std::endl; // compare n char from pos1 in string1 to c-style string
    std::cout << "result : " << s5.compare(0, s5.size() / 2, "compare_string5", strlen("compare_string5") / 2) << std::endl;  // compare n1 char from pos1 in string1 to n2 char from pos2 c-style string

// Numeric conversions
    std::string s9("789"), s10("7.65"), s11;
    s11 = std::to_string(4.5);
    std::cout << "sval = " << s11 << std::endl; // return string version of arthmetic types
    int ival = std::stoi(s9);
    std::cout << "ival = " << ival << std::endl; // convert string to integral type
    double dval = std::stod(s10);
    std::cout << "dval = " << dval << std::endl; // convert string to floating point type

    return 0;
}
