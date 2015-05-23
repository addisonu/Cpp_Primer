// DATE : 05/22/15
// FILE : APAN:05.22.15.cpp
// DESC : Use multidimensional array

#include <iostream>

int main()
{
// Define multidimensional array
    double darr0[2][2][2]{{{0}}};
    double darr1 [2][2][2] = {0};
    double darr2 [2][2][1] = {1,1,1,1};

// Initialize
    constexpr std::size_t dim1 = 3, dim2 = 3, dim3 = 2;
    int iarr[dim1][dim2][dim3]= {{{1,2},{3,4},{5,6}},{{7,8},{9,10},{11,12}},{{13,14},{15,16},{17,18}}};

// Subscript
    std::cout << "darr0[0][1][1] = " << darr0[0][1][1] << std::endl;
    std::cout << "*darr2[1][0] = " << *darr2[1][0] << std::endl;
    std::cout << "iarr : " << std::endl;
    for(std::size_t i = 0; i != dim1; ++i)
        for(std::size_t j = 0; j != dim2; ++j)
            for(std::size_t k = 0; k != dim3; ++k)
                std::cout << iarr[i][j][k] << std::endl;
// Assign
    darr1[0][1][0] = 2;
    std::cout << "darr1[0][1][0] = " << darr1[0][1][0] << std::endl;

// Iterating with range for
    std::cout << "iarr : " << std::endl;
    for(auto &ele0 : iarr)
        for(auto &ele1 : ele0)
            for(auto ele2 : ele1)
                std::cout << ele2 << " ";
    std::cout << std::endl;

// Defining pointer
    using pi = int (*)[dim3];
    pi ele = &iarr[2][1];

    std::size_t cnt0(0), cnt1(0);
    for(auto u = ele; u != ele + 2; ++u){
        for(auto w = *u; w != *u + 2; ++w){
            std::cout << "ele[" << cnt0 << "]" << "[" << cnt1++ << "] = " << *w << std::endl;
        }
        ++cnt0;
        cnt1 = 0;
    }

// array name conversion to pointer
    std::cout << "iarr = " << iarr << std::endl;

    return 0;
}
