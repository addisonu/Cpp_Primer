// DATE : 05/25/15
// FILE : APAN:05.25.15.cpp
// DESC : Print arguments passed via command-line

#include <iostream>

int main(int argc, char **argv)
{
// OUTPUT
/*
    argv[1] : Happy
    argv[2] : Memorial
    argv[3] : Day
 */

    std::size_t cnt(1);

    for(auto pa0 = argv + 1; pa0 != argv + argc; ++pa0){
        std::cout << "argv[" << cnt++ << "] : ";
        for(auto pa1 = *pa0; pa1 != *pa0 + strlen(*pa0); ++pa1)
            std::cout << *pa1;
        std::cout << std::endl;
    }

    return 0;
}
