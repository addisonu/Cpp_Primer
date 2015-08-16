// DATE : 08/07/15
// FILE : APAN:08.07.15.cpp
// DESC : C++ primer exercises :1.18, 1.19, 1.21, 1.22

#include <iostream>
#include "../C++_primer/Sales_item.h"

int main()
{
/*
// Ex 1.18
    int currVal(0), val(0);

    if(std::cin >> currVal){
        int cnt(1);
        while(std::cin >> val){
            if(val == currVal)
                ++cnt;
            else{
                std::cout << currVal << " occurs " << cnt << " times" << std::endl;
                currVal = val;
                cnt = 1;
            }
        }
        std::cout << currVal << " ocurrs " << cnt << " times" << std::endl;
    }
// Ex 1.19
    int val1(0), val2(0);
    std::cout << "Enter two integers.\n";
    std::cin >> val1 >> val2;

    if(val1 > val2)
        std::swap(val1, val2);
    for(; val1 <= val2; ++val1)
        std::cout << val1 << ' ';
    std::cout << std::endl;

// Ex 1.21
    Sales_item item1, item2;

    std::cout << "Enter two transactions.\n";
    std::cin >> item1 >> item2;

    std::cout << "transaction #1 : " << item1 << std::endl;
    std::cout << "transaction #2 : " << item2 << std::endl;

// Ex 1.22
    Sales_item total;

    if(std::cin >> total){
        Sales_item trans;
        while(std::cin >> trans){
            if(total.isbn() == trans.isbn())
                total += trans;
            else{
                std::cerr << "Books are different." << std::endl;
                std::cout << "Current total is : " << total << std::endl;
                return -1;
            }
        }
        std::cout << "total : " << total << std::endl;
    }
    else{
        std::cerr << "No data." << std::endl;
        return -1;
    }
*/
    return 0;
}
