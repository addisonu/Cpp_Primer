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
    std::string s1("string1");
    std::string s2(s1);
    std::string s3 = s2;
    std::string s4 = "string4";
    std::string s5(5, 's');
//    std::string s6(7, 'u');
//    s6 = s5;

// Type aliases
    std::string::iterator sti(s1.begin());
    std::string::const_reverse_iterator csti(s2.crbegin());
    std::string::size_type sz = s3.size();
    std::string::difference_type diff = s4.cend() - s4.cbegin();
    std::string::value_type obj;
    const std::string::value_type cobj = 'c';
    std::string::reference robj = obj;
    std::string::const_reference crobj = cobj;

// Operations
    std::cout << "s3[1] = " << s3[1] << std::endl;// access
    std::cout << "s1[s1.size() - 1] = " << s1.back() << std::endl;
    std::cout << "s2[0] = " << s2.front() << std::endl;
    std::cout << "s3[2] = " << s3.at(2) << std::endl;
    std::cout << "s0 : " << (s0 = s5) << std::endl;// assignment
    swap(s0, s4);
    std::cout << "s0 : " << s0 << std::endl;// swap elements
    std::cout << "s5.size() = " << s5.size() << std::endl;// get number of elements
//    std::cout << "s5 capacity" << s5.max_size() << std::endl; // get capacity
    std::cout << "s0.empty()" << s0.empty() << std::endl;// has elements
    s0.push_back('A'); // insert new element
    s0.insert(s0.end(), 'B'); // insert new element
    s1.insert(s0.cbegin(), s0.cend(), s1.cend());
    //s0.emplace(s0.end(), 'C'); // insert new element
    std::cout << "s0 = " << s0 << std::endl;
  //  s0.remove('A'); // remove element
    s0.clear();
    std::cout << "s0 = " << s0 << std::endl;

// Relational operation
// Iterators
 // const
 // reverse
 // const reverse
    return 0;
}
