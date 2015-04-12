//Write a program for reversing numbers in binary

#include <iostream>
#include <cstdlib>
#include <sstream>
#include <string>

int dec_to_bin(int dec);
int bin_to_dec(int bin);

int main()
{
    int dec(0);
    std::cout << "Enter an integer.\n";
    std::cin >> dec;

    std::cout << "The reversed binary representaion of " << dec << " is " << dec_to_bin(dec) << std::endl;
    return 0;
}

int dec_to_bin(int dec)
{
    std::stringstream str_bin;

    while(dec){
        str_bin << (dec % 2);
        dec /= 2;
    }
    str_bin >> dec;
    return dec;
}

int bin_to_dec(int bin)
{
    std::stringstream str_dec(bin);
    unsigned cnt = str_dec.str().size();

    /*for(const auto ch : str_dec.str())*/for(const char *ch = cbegin(str_dec.str()); ch != cend(str_dec.str()); ++ch){
        bin += atoi(ch);// * cnt++;
    }
    return bin;
}
