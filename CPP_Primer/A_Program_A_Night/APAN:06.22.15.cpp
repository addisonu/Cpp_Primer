// DATE : 06/22/15
// FILE : APAN:06.22.15
// DESC : Use dynamic memory with smart pointers
//  1) Shared pointer

#include <iostream>
#include <memory>
#include <vector>
#include <string>

int main()
{
// Create shared pointers
    std::shared_ptr<std::vector<int>> ivsp0, ivsp1, ivsp2;
    std::shared_ptr<std::string> ssp;
    std::shared_ptr<int> isp0 = std::make_shared<int>(77), isp1(isp0);

// Shared pointer operations
    ssp = std::make_shared<std::string>(std::string("This a string pointed to by a shared pointer"));
    ivsp0 = std::make_shared<std::vector<int>>(std::vector<int>(5, 23));
    for(std::vector<int>::size_type i = 0; i != 10; ++i)
        ivsp0->push_back(i + 2 * i);

    for(auto ele : *ivsp0)
        std::cout << ele << ", ";
    std::cout << std::endl;

    std::cout << "ivsp0 count = " << ivsp0.use_count() << std::endl;

    ivsp0.swap(ivsp1);
    ivsp2 = ivsp1;
    std::cout << "ivsp1 count = " << ivsp1.use_count() << std::endl;

    std::cout << "isp1 == isp0 : " << (isp1.get() == isp0.get()) << std::endl;

    std::cout << (ssp.unique() ? "ssp is unique and holds value : \"" + *ssp + "\"" : "ssp is NOT unique and holds value : \"" + *ssp + "\"")<< std::endl;

    return 0;
}
