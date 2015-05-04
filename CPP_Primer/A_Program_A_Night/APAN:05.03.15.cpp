// DATE : 05/03/15
// FILE : APAN:05.03.15.cpp
// DESC : Use decltype in variable declarations and verify type with typeid

#include <iostream>
#include <vector>
#include <typeinfo>

int main()
{
// Explicit var declarations
    int i(6), *pi, &ri = i, *const cpi = &i;
    const int ci(1), *pci = &i, *const cpci = &ci, &cri = ci;
    int iarr[3];
    std::vector<int> ivec{123};
    void *vp;

// Declarations that will yield a basic type
    decltype(i) di2 = 1; // int
    std::cout << "di2 : " << typeid(di2).name() << std::endl;

    decltype(ri + 0) di1 = 1; // int
    std::cout << "di1 : " << typeid(di1).name() << std::endl;

    decltype(ci) dci = 2; // const int
    std::cout << "dci : " << typeid(dci).name() << std::endl;

    decltype(ivec.end()) dit = ivec.begin();// iterator to vector<int>
    std::cout << "dit : " << typeid(dit).name() << std::endl;

// Declarations that will yield a reference type
    decltype((i)) dri1 = i; // ref to int
    std::cout << "dri1 : " << typeid(dri1).name() << std::endl;

    decltype(ri) dri2 = i; // ref to int
    std::cout << "dri2 :" << typeid(dri2).name() << std::endl;

    decltype(*pi) dri3 = i; // ref to int
    std::cout << "dri3 : " << typeid(dri3).name() << std::endl;

    decltype((vp)) drvp = vp;  // ref to void pointer
    std::cout << "drvp : " << typeid(drvp).name() << std::endl;

// Declarations that will yield a compound type
    decltype(vp) dvp = &dit; // void pointer
    std::cout << "dvp : " << typeid(dvp).name() << std::endl;

    decltype(iarr) diarr{1, 2, 3}; // array
    std::cout << "diarr : " << typeid(diarr).name() << std::endl;

    decltype(pi) dpi = &i; // pointer to int
    std::cout << "dpi :" << typeid(dpi).name() << std::endl;

    decltype(pci) dpci = &i; // pointer to const int
    std::cout << "dpci : " << typeid(dpci).name() << std::endl;

    decltype(cpci) dcpci = &i; // const pointer to const int
    std::cout << "dcpci : " << typeid(dcpci).name() << std::endl;

    decltype(cpi) dcpi = &i; // const pointer to int
    std::cout << "dcpi : " << typeid(dcpi).name() << std::endl;

    return 0;
}
