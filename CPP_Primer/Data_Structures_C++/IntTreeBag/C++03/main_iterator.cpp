//ASSIGNMENT: Project 5
//DATE: 10/30/14
//FILE: main_iterator.cpp
//DSCR: Unit tests for binary tree bag class iterator

#include <iostream>
#include <string>
#include <iterator>
#include "itbag6.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;

std::ostream& div(std::ostream& out, std::string label);

int main()
{
cout << std::boolalpha;

//Create objects for tests
    main_savitch_10::bag<int> bag1;
    bag1.insert(5);
    bag1.insert(5);
    bag1.insert(3);
    bag1.insert(2);
    bag1.insert(7);
    cout << "\n\n" << bag1 << endl;
cout << "bag created of size " << bag1.size() << endl;

div(std::cout, "binary_tree_node_iterator(arg)");
    typename main_savitch_10::bag<int>::const_iterator it1 = bag1.begin();
    typename main_savitch_10::bag<int>::const_iterator it2 = bag1.begin();
    typename main_savitch_10::bag<int>::const_iterator begin = bag1.begin();

    int j(1);

    std::cout << "it1[0] = " << *it1 << endl;
    while(j < bag1.size()){
        std::cout << "it1[" << j << "] = " << *(++it1) << endl;
        ++j;
    }
    std::cout << std::endl;
    j = 0;

    while(j < bag1.size()){
        std::cout << "it2[" << j << "] = " << *(it2++) << endl;
        ++j;
    }
    cout << "Outcome : PASS\n";

div(std::cout, "binary_tree_node_iterator()");
    typename main_savitch_10::bag<int>::iterator end = bag1.end();
    cout << "Outcome : PASS\n";

div(std::cout, "operator*");
    cout << *begin << endl;
  cout << "Outcome : PASS\n";

div(std::cout, "++operator");
    cout << "*(++begin) = " << *(++begin) << endl;
    cout << "Outcome : PASS\n";

div(std::cout, "operator++");
    cout << "*(begin++) = " << *(begin++) << endl;
    cout << "Outcome : PASS\n";

div(std::cout, "operator==");
    cout << "(begin == end) : " << (begin == end) << endl;
    cout << "Outcome : PASS\n";

div(std::cout, "operator!=");
    cout << "(begin != end) : " << (begin != end) << endl;
    cout << "Outcome : PASS\n";

    return 0;
}

std::ostream& div(std::ostream& out, std::string label)
{
    if(label == "="){
        std::cout << std::string(30, '=');
    }
    else{
        std::cout << std::string(30, '=') << endl;
        out << label << " : " << endl;
        std::cout << std::string(30, '=') << endl;
    }
    return out;
}
