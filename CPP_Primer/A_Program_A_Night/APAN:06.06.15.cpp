// DATE : 06/06/15
// FILE : APAN:06.06.15.cpp
// DESC : Program in series of data structure APANs
//  1) Deque

#include <iostream>
#include <deque>

// forward declarations
void print(std::ostream &out, std::deque<int> dq,std::string name);

int main()
{
    std::cout << std::boolalpha;

// Constructors
    std::deque<int> dq0; // default
    std::deque<int> dq1{1, 2, 3}; // copy braced list
    std::deque<int> dq2 = {4, 5, 6};
    std::deque<int> dq3(dq1); // copy
    std::deque<int> dq4(dq2.begin(), dq2.end()); // range

// Type aliases
    std::deque<int>::iterator it; // iterator
    std::deque<int>::const_iterator cit; // const_iterator
    std::deque<int>::reverse_iterator rit; // reverse_iterator
    std::deque<int>::const_reverse_iterator crit; // const_reverse_iterator
    std::deque<int>::size_type sz; // size_type
    std::deque<int>::difference_type diff = dq2.end() - dq2.begin(); // difference_type
    std::deque<int>::value_type val = dq3[0]; // value_type
    std::deque<int>::reference ref = dq4[0]; // reference
    std::deque<int>::const_reference cref = dq4[1]; // const_reference

// Iterators
    it = dq1.begin(); // get iterator
    cit = dq2.cbegin(); // const_iterator
    rit = dq3.rend(); // reverse_iterator
    crit = dq4.crend(); // const_reverse_iterator

// Size operations
    sz = dq1.size();// size
    std::deque<int>::size_type max_sz = dq2.max_size(); // max_size
    std::cout << "dq4.empty() : " << dq4.empty() << std::endl; // empty

// Print
    std::cout << "Construction :\n";
    print(std::cout, dq0, "dq0");
    print(std::cout, dq1, "dq1");
    print(std::cout, dq2, "dq2");
    print(std::cout, dq3, "dq3");
    print(std::cout, dq4, "dq4");

// Assign and swap
    dq0 = dq1; // copy assignment object
    dq1 = {6, 4, 7, 3}; // copy assignment braced list
    dq2.swap(dq3); // member style swap
    swap(dq3, dq4); // function style swap
 // assign function

// Print
    std::cout << "Assignment and swap :\n";
    print(std::cout, dq0, "dq0");
    print(std::cout, dq1, "dq1");
    print(std::cout, dq2, "dq2");
    print(std::cout, dq3, "dq3");

// Adding/removing elements
    dq0.insert(dq0.cend(), dq1[0]); // insert element in container : 1) at position, 2) at position, with number of copies, element, 3) range
    dq1.insert(dq1.cbegin(), dq2.size(), dq2[0]);
    dq2.insert(dq2.cend(), dq3.cbegin(), dq3.cend());
    dq4.emplace(dq4.cend(), 7); // construct object in container
    dq0.erase(--dq0.end()); // erase one or more elements
    dq1.clear(); // remove all elements

// Print
    std::cout << "Insertion/Deletion :\n";
    print(std::cout, dq0, "dq0");
    print(std::cout, dq1, "dq1");
    print(std::cout, dq2, "dq2");
    print(std::cout, dq3, "dq3");
    print(std::cout, dq4, "dq4");

// Relational operators
    std::cout << "Relational operations :\n";
    std::cout << "dq0 == dq1) : " << (dq0 == dq1) << std::endl; // ==
    std::cout << "dq1 != dq2) : " << (dq1 != dq2) << std::endl; // !=
    std::cout << "dq3 < dq4) : " << (dq3 < dq4) << std::endl; // <
    std::cout << "dq4 <= dq1 : " << (dq4 <= dq1) << std::endl; // <=
    std::cout << "dq1 > dq3 : " << (dq1 > dq3) << std::endl; // >
    std::cout << "dq1 >= dq4 : " << (dq1 >= dq4) << std::endl; // >=

    return 0;
}

void print(std::ostream &out, std::deque<int> dq,std::string name)
{
    std::cout << name << " : \n";
    for(auto val : dq)
        std::cout << val << ", ";
    std::cout << '\n' << std::endl;
}
