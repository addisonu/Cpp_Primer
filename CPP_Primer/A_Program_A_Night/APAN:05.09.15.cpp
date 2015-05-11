// DATE : 05/09/15
// FILE : APAN:05.09.15.cpp
// DESC : Dynamic memory :
//  1) new, delete
//  2) new[], delete[]
//  3) smart pointers : shared_ptr, unique_ptr

#include <iostream>
#include <memory>
#include <string>
#include <vector>

int main()
{
// Allocate memory for object using new, print, and free
    std::string *pstr = new std::string("new string");
    std::cout << *pstr << std::endl;
    delete pstr;

// Allocate memory for array using new[], assign, print, and free
    constexpr std::size_t sz = 5;
    int *pai = new int[sz];

    for(std::size_t i = 0; i != sz; ++i)
        pai[i] = i;

    auto k = pai;
    while(k != pai + sz)
        std::cout << *(k++) << " ";
    std::cout << std::endl;

    delete[] pai;

// Allocate memory for vector using unique_ptr, assign, and print, delete underlying object
    using vsz = std::vector<int>::size_type;

    std::unique_ptr<std::vector<int>> upvec(new std::vector<int>());
    for(vsz i = 0; i != 5; ++i)
        upvec->push_back(i * 2);

    for(auto val : *upvec)
        std::cout << val << " ";
    std::cout << std::endl;

    upvec.reset();

// Allocate memory for vector using shared_ptr, make multiple pointers, assign, print, and free
    std::shared_ptr<std::vector<int>> spvec1, spvec2, spvec3, spvec = std::make_shared<std::vector<int>>();
    spvec1 = spvec2 = spvec3 = spvec;
    for(vsz i = 0; i != 5; ++i){
        spvec1->push_back(i);
        spvec2->push_back(i * 2);
    }
    for(auto val : *spvec3)
        std::cout << val << " ";

    std::cout << std::boolalpha;
    std::cout << "\nThe number of pointers sharing is equal to 1 : " << spvec.unique() << std::endl;
    std::cout << "The number of pointers sharing : " << spvec.use_count() << std::endl;

    spvec1.reset();
    spvec2.reset();
    spvec3.reset();
    spvec.reset();
    return 0;
}
