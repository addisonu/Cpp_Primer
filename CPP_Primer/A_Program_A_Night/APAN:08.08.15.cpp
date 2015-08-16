// DATE : 08/08/15
// FILE : APAN:08.08.15.cpp
// DESC : C++ primer exercises : 1.23, 1.24, 2.3, 2.8

#include <iostream>
#include "../C++_primer/Sales_item.h"

int main()
{
/*
// Ex 1.23
    Sales_item curr;

    if(std::cin >> curr){
        Sales_item trans;
        int cnt(1);
        while(std::cin >> trans){
            if(curr.isbn() == trans.isbn())
                ++cnt;
            else{
                std::cout << "book with isbn = " << curr.isbn() << " had " << cnt << " transactions." << std::endl;
                curr = trans;
                cnt = 1;
            }
        }
                std::cout << "book with isbn = " << curr.isbn() << " had " << cnt << " transactions." << std::endl;
    }
    else{
        std::cerr << "No data." << std::endl;
        return -1;
    }

// Ex 1.24
    Sales_item total;
    if(std::cin >> total){
        Sales_item trans;
        while(std::cin >> trans){
            if(total.isbn() == trans.isbn())
                total += trans;
            else{
                std::cout << total << std::endl;
                total = trans;
            }
        }
        std::cout << total << std::endl;
    }
    else{
        std::cerr << "No data?!" << std::endl;
        return -1;
    }

// Ex 2.3
    unsigned u = 10, u2 = 42;
    std::cout << "u2 - u : " << u2 - u << std::endl;
    std::cout << "u - u2 : " << u - u2 << std::endl;

    int i = 10, i2 = 42;
    std::cout << "i2 - i : " << i2 - i << std::endl;
    std::cout << "i - i2 : " << i - i2 << std::endl;

    std::cout << "i - u : " << i - u << std::endl;
    std::cout << "u - i : " << u - i << std::endl;

// Ex 2.8
    std::cout << "2\115\n";
    std::cout << "2\t\115\n";
*/
    return 0;
}

