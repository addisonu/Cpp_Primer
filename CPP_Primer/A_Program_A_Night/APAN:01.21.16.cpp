// DATE : 01/21/15
// FILE : APAN:01.21.16.cpp
// DESC : Get access to and print environmental variable

#include <iostream>
#include <cstdlib>

int main(int argc, char **argv)
{
    if(argc >= 1){
        std::cout << (std::getenv(argv[1]) != nullptr ? std::string(argv[1]) + "=" + std::getenv(argv[1]) : "Not valid environmental variable.") << std::endl;
    }
    return 0;
}
