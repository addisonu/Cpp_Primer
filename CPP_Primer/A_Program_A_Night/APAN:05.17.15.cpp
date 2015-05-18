// DATE : 05/17/15
// FILE : APAN:05.17.15.cpp
// DESC : Use iterator companion type for library containers and built-in array

#include <iostream>
#include <vector>
#include <string>

int main()
{
// Create containers
    std::vector<std::string> dvec{"one", "two", "three point four", "four point three", "nine"};
    const std::string str("A string iterator");;
    bool barr[2] = {true, false};

// Create iterators to first element of each container
    std::vector<std::string>::iterator vit = dvec.begin();
    decltype(str.cbegin()) sit = str.begin();
    auto ait = barr;
    std::cout << std::boolalpha;

// Iterator operations
    std::cout << "dvec[0] = " << *vit << std::endl; // dereference iterator
    std::cout << "dvec[0].size = " << vit->size() << std::endl; // select underlying element member
    std::cout << "++sit : " << *sit++ << std::endl;// move iterator forward and backward to elements
    std::cout << "sit++ : " << *(++sit)<< std::endl;
    std::cout << "sit-- : " << *sit-- << std::endl;
    std::cout << "--sit : " << *(--sit) << std::endl;
    std::cout << "ait == end(barr) : " << (ait == std::end(barr)) << std::endl; // test for equality
    std::cout << "ait != end(barr) : " << (ait != std::end(barr)) << std::endl; // test for inequality

// Iterator arithmetic
    std::cout << "dvec[2] = " << *(vit += 2) << std::endl;
    std::cout << "dvec[1] = " << *(vit -= 1) << std::endl;
    std::cout << "dvec[0] = " << *(vit - 1) << std::endl;
    std::cout << "dvec[4] = " << *(vit + 3) << std::endl;
    std::cout << "dvec.size() : " << (dvec.end() - dvec.begin()) << std::endl;
    std::cout << "dvec.begin() == dvec.end() : " << (dvec.begin() == dvec.end()) << std::endl;
    std::cout << "dvec.begin() != dvec.end() : " << (dvec.begin() != dvec.end()) << std::endl;
    std::cout << "dvec.begin() <= dvec.end() : " << (dvec.begin() <= dvec.end()) << std::endl;
    std::cout << "dvec.begin() >= dvec.end() : " << (dvec.begin() >= dvec.end()) << std::endl;

    return 0;
}
