// DATE : 07/01/15
// FILE : APAN:07.01.15.cpp
// DESC : Program in series of data structure APANs
//  1) multiset

#include <iostream>
#include <vector>
#include <string>
#include <set>

template <typename T> void print(const T &obj, std::string name);

int main()
{
    std::vector<char> cvec;
    for(decltype(cvec.size()) i = 0; i != 30; i += 3 )
        cvec.push_back('a' + i);

    print(cvec, "cvec");

// Define multiset objects
    std::multiset<char> mst0;
    std::multiset<char> mst1 = {'a', 'd', 'd', 'e', 'g', '4'};
    std::multiset<char> mst2{'3', '5', 'd', 'g'};
    std::multiset<char> mst3(cvec.cbegin(), cvec.cend());

// Print all multisets
    std::cout << "\nCreate multisets" << std::endl;
    print(mst0, "mst0");
    print(mst1, "mst1");
    print(mst2, "mst2");
    print(mst3, "mst3");

// Use multiset operations
// Add elements
    mst0.insert('u');
    mst1.emplace('y');
    mst2.insert(cvec.cbegin() + cvec.size() / 2, cvec.cend());
    std::initializer_list<char> il{'i','n','i','t','i','a','l','i','z','e','r','_','l','i','s','t'};
    mst3.insert(il);
    mst0.insert(--mst0.cend(), 'v');
    mst1.emplace_hint(mst1.cbegin(), 'e');

// Print all multisets
    std::cout << "\nInsert elements" << std::endl;
    print(mst0, "mst0");
    print(mst1, "mst1");
    print(mst2, "mst2");
    print(mst3, "mst3");

// Access elements
    std::cout << "first element with value = 'v' : " << *mst0.find('v') << std::endl;
    std::cout << "count of elements with value = 'a': " << mst1.count('a') << std::endl;
    std::cout << "mst2.lower_bound : " << *mst2.lower_bound('l') << std::endl;
    std::cout << "mst3.upper_bound : " << *mst3.upper_bound('i') << std::endl;
    std::pair<std::multiset<char>::iterator, std::multiset<char>::iterator> result = mst3.equal_range('g');
    std::cout << "mst3.equal_range first : " << *result.first << " \nsecond : " << *result.second << std::endl;

// Erase elements
    mst3.erase('i');
    mst1.erase(mst1.cbegin());
    mst2.erase(mst2.begin(), ++mst2.begin());

// Print all multisets
    std::cout << "\nErase elements" << std::endl;
    print(mst0, "mst0");
    print(mst1, "mst1");
    print(mst2, "mst2");
    print(mst3, "mst3");

    return 0;
}

template <typename T> void print(const T &obj, std::string name)
{
    std::cout << name << " :\n";
    for(auto val : obj)
        std::cout << val << " ";
    std::cout << std::endl;
}
