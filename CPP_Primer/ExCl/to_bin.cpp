//Write a program for reversing numbers in binary and returning decimal representation

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <sstream>
#include <string>

int dec_to_rbin(int dec);
int bin_to_dec(int bin);

int main()
{
    int dec(0);
    std::cout << "Enter an integer.\n";
    std::cin >> dec;

    std::cout << "The decimal representation of the reversed binary of " << dec << " is " << bin_to_dec(dec_to_rbin(dec)) << std::endl;
    return 0;
}

// Converts decimal into reversed binary representation
int dec_to_rbin(int dec)
{
    std::stringstream str_bin;

    while(dec){
        str_bin << (dec % 2);
        dec /= 2;
    }
    str_bin >> dec;
    return dec;
}

// Converts binary to decimal
int bin_to_dec(int bin)
{
    std::stringstream str_dec;
    str_dec << bin;
    unsigned cnt = str_dec.str().size();
    char ch('0');
    bin = 0;

    while(str_dec.get(ch)){
        bin += (ch - '0') * pow(2, --cnt);
    }
    return bin;
}
