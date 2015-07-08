// DATE : 06/22/15
// FILE : APAN:06.22.15
// DESC : Use dynamic memory with smart pointers
//  1) Unique pointer

#include <iostream>
#include <memory>
#include <vector>
#include <string>

int main()
{
    std::vector<int> ivec{4, 5, 6,};
    std::string str("a string");

// Create unique pointers
    std::unique_ptr<std::string> sup0, sup1(new std::string(str));
    std::unique_ptr<std::vector<int>> ivsp0(new std::vector<int>({1,2,3})), ivsp1(new std::vector<int> (ivec));
    std::default_delete<int> d;
    std::unique_ptr<int> iup(new int, d);

// Unique pointer operations
    std::cout << (sup0 ? "points to string" : "holds nullptr") << std::endl;
    std::cout << "*sup1 = " << *sup1 << std::endl;
    std::cout << "ivsp0->size() = " << ivsp0->size() << std::endl;
    std::cout << "ivec elements via get :\n";
    for(int val : *ivsp1.get())
        std::cout << val << " ";
    std::cout << std::endl;
    std::cout << (sup1 ? "points to string" : "holds nullptr") << std::endl;
    sup1 = nullptr;
    std::cout << (sup1 ? "points to string" : "holds nullptr") << std::endl;
    sup1.swap(sup0);
    iup.reset();
    std::vector<int> * ivpt = new std::vector<int> ();
    ivsp1.reset(ivpt);
    std::cout << (ivsp0 ? "points to vector" : "holds nullptr") << std::endl;
    ivsp0.reset(nullptr);
    std::cout << (ivsp0 ? "points to vector" : "holds nullptr") << std::endl;

    return 0;
}
