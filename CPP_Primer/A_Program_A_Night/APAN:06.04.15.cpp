// DATE : 06/04/15
// FILE : APAN:06.04.15.cpp
// DESC : Program in series of data structure APANs
//  1) List

#include <iostream>
#include <list>
#include <string>

void print(std::ostream &out, std::list<std::string> ls, std::string name);

int main()
{
    std::cout << std::boolalpha;

// Constructors
    std::list<std::string> f1; // default
    std::list<std::string> f2{"second", "element"}; // copy braced list
    std::list<std::string> f3 = {"All", "good", "boys", "do", "fine"};
    std::list<std::string> f4(f2); // copy
    std::list<std::string> f5(f3.begin(), --f3.end()); // range

// Print
    print(std::cout, f1, "f1");
    print(std::cout, f2, "f2");
    print(std::cout, f3, "f3");
    print(std::cout, f4, "f4");
    print(std::cout, f5, "f5");

// Type aliases
    std::list<std::string>::iterator it; // iterator
    std::list<std::string>::const_iterator cit; // const_iterator
    std::list<std::string>::reverse_iterator rit; // reverse_iterator
    std::list<std::string>::const_reverse_iterator crit; // const_reverse_iterator
    std::list<std::string>::size_type sz(7); // size_type
    std::cout << "sz = " << sz << std::endl;
    std::list<std::string>::value_type val = "value_type"; // value_type
    std::cout << "val = " << val << std::endl;
    std::list<std::string>::reference ref = f2.front(); // reference
    std::cout << "ref = " << ref << std::endl;
    std::list<std::string>::const_reference cref = f3.back(); // const_reference
    std::cout << "cref = " << cref << std::endl;

// Iterators
    it = f2.begin(); // iterator
    std::cout << "it = " << *it << std::endl;
    cit = f3.cbegin(); // const_iterator
    std::cout << "cit = " << *cit << std::endl;
    rit = f4.rbegin(); // reverse_iterator
    std::cout << "rit = " << *rit << std::endl;
    crit = f4.crbegin(); // const_reverse_iterator
    std::cout << "crit = " << *crit << std::endl;

// Size operations
    std::cout << "f1.size() = " << f1.size() << std::endl; // number of elements
    std::cout << "f2.max_size() = " << f2.max_size() << std::endl; // max number of elements container can hold
    std::cout << "f3.empty() = " << f3.empty() << std::endl; // check if container has an element


// Adding/removing elements
    f1.insert(f1.cbegin(), "inserted element"); // insert elements in container
    print(std::cout, f1, "f1");
    f2.insert(f2.end(), 3, "three");
    print(std::cout, f2, "f2");
    f3.insert(--f3.end(), f1.cbegin(), f1.cend());
    print(std::cout, f3, "f3");
    std::initializer_list<std::string> il{"braced", "list", "of", "strings"};
    f4.insert(++f4.begin(), il);
    print(std::cout, f4, "f4");
    f5.emplace(f5.begin(), std::string("constructed in container")); // construct elements in container
    print(std::cout, f5, "f5");
    f1.push_back("back"); // add element to back
    std::cout << "f1.back() = " << f1.back() << std::endl;
    f1.push_front("front"); // add element to front
    std::cout << "f1.front() = " << f1.front() << std::endl;
    f1.pop_back();
    std::cout << "f1.back() = " << f1.back() << std::endl;
    f1.pop_front();
    std::cout << "f1.front() = " << f1.front() << std::endl;
    f2.erase(f2.begin()); // remove one or more elements from container
    print(std::cout, f2, "f2");
    f3.clear(); // remove all elements from container
    print(std::cout, f3, "f3");

// Assignment and swap
    f3 = f4; // copy assignment
    print(std::cout, f3, "f3");
    f4 = {"The", "new", "elements", "of", "f4"}; // copy braced list
    print(std::cout, f4, "f4");
    f3.swap(f4); // member style swap
    std::cout << "f3.swap(f4) : " << std::endl;
    print(std::cout, f3, "f3");
    print(std::cout, f4, "f4");
    swap(f1, f2); // function style swap
    std::cout << "swap(f1, f2) : " << std::endl;
    print(std::cout, f1, "f1");
    print(std::cout, f2, "f2");

// Relational operations
    std::cout << "(f1 == f2) : " << (f1 == f2) << std::endl; // ==
    std::cout << "(f2 != f3) : " << (f2 != f3) << std::endl; // !=
    std::cout << "(f3 >= f4) : " << (f3 >= f4) << std::endl; // >=
    std::cout << "(f4 > f5) : " << (f4 > f5) << std::endl; // >
    std::cout << "(f5 <= f1) : " << (f5 <= f1) << std::endl; // <=
    std::cout << "(f1 < f3) : " << (f1 < f3) << std::endl; // <

    return 0;
}

void print(std::ostream &out, std::list<std::string> ls, std::string name)
{
    out << name << " : " << std::endl;
    for(auto ele : ls)
        out << ele << ", ";
    out << '\n' << std::endl;
}
