// DATE : 06/28/15
// FILE : APAN:06.28.15.cpp
// DESC : Use dynamic memory with smart pointers
// 1) Weak pointer

#include <iostream>
#include <memory>
#include <vector>
#include <string>

int main()
{
    std::cout << std::boolalpha;
    std::shared_ptr<std::string> ssp = std::make_shared<std::string>(std::string("This is a string pointed to by a shared pointer"));

    std::shared_ptr<int> isp(new int(3));

// Create weak pointers
    std::weak_ptr<std::string> swp = ssp;
    std::weak_ptr<int> iwp0(isp);
    std::weak_ptr<int> iwp1(iwp0);

// Weak pointer operations
    std::cout << (ssp ? "Points to object" : "Holds nullptr") << std::endl;
    ssp.reset();
    std::cout << (ssp ? "Points to object" : "Holds nullptr") << std::endl;
    std::cout << "isp.use_count = " << isp.use_count() << std::endl;
    std::cout << "iwp0.expired : " << iwp0.expired() << std::endl;
    std::cout << (swp.lock() ? "Points to object" : "Holds nullptr") << std::endl;

    return 0;
}
