// DATE : 05/23/15
// FILE : APAN:05.23.15.cpp
// DESC : Passing arguments
//  1) By reference
//  2) By value

#include <iostream>

int id(int val);
int doub(int &val);
int cid(const int &val);
int& rrid(int &val);

int main()
{
// Var to pass as arguments
    int val(7);
    int *pval = &val;
    int iarr[]{4,2};

// Pass argument by value
    std::cout << "Pass argument by value : " << std::endl;
    std::cout << "id(val) = " << id(val) << std::endl;
    std::cout << "id(*pval) = " << id(*pval) << std::endl;
    std::cout << "id(*iarr) = " << id(*iarr) << '\n' << std::endl;

// Pass argument by reference
    std::cout << "Pass argument by reference : " << std::endl;
    std::cout << "doub(val) = " << doub(val) << std::endl;
    std::cout << "val = " << val << std::endl;
    std::cout << "doub(*pval) = " << doub(*pval) << std::endl;
    std::cout << "*pval = " << *pval << std::endl;
    std::cout << "doub(*iarr) = " << doub(*iarr) << std::endl;
    std::cout << "*iarr = " << *iarr << '\n' << std::endl;

// Pass argument const reference
    std::cout << "Pass argument by const reference : " << std::endl;
    std::cout << "cid(val) = " << cid(val) << std::endl;
    std::cout << "val = " << val << std::endl;
    std::cout << "cid(*pval) = " << cid(*pval) << std::endl;
    std::cout << "*pval = " << *pval << std::endl;
    std::cout << "cid(*iarr) = " << cid(*iarr) << std::endl;
    std::cout << "*iarr = " << *iarr << '\n' << std::endl;

// Reference parameter and return type
    std::cout << "Reference parameter and return type :" << std::endl;
    std::cout << "rrid(val) = " << rrid(val) << std::endl;
    std::cout << "val = " << val << std::endl;
    std::cout << "rrid(*pval) = " << rrid(*pval) << std::endl;
    std::cout << "*pval = " << *pval << std::endl;
    std::cout << "rrid(iarr[1]) = " << rrid(iarr[1]) << std::endl;
    std::cout << "iarr[1] = " << iarr[1] << '\n' << std::endl;

return 0;
}

int id(int val)
{
    return val;
}

int doub(int &val)
{
    return val *= 2;
}

int cid(const int &val)
{
    return val * val;
}

int& rrid(int &val){
    return val += 1;
}
