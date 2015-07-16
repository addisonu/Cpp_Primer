// DATE : 07/16/15
// FILE : APAN:07.16.15.cpp
// DESC : Use iostream iterators to read and write iostream and fstream objects

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

int main()
{
    const char *cstr = "\nHello Github";

// Create iostream iterators
    std::ostream_iterator<char> chout0(std::cout);
    std::ostream_iterator<double> dout0(std::cout, cstr);

// Use istream iterator operations
    std::cout << std::boolalpha;

    std::istream_iterator<int> iin(std::cin);
    std::cout << "++iin : " << *(++iin) << std::endl;
    std::cout << "iin++ : " << *iin++ << std::endl;

    std::istream_iterator<std::string> sin(std::cin);
    std::cout << "*sin.size() : " << sin->size() << std::endl;

    std::istream_iterator<char> chin0(std::cin), chin1(std::cin);
    std::cout << "chin0 == chin1 : " << (chin0 == chin1) << std::endl;
    std::cout << "chin0 != chin1 : " << (chin0 != chin1) << std::endl;
    std::cout << "value in chin1 : " << *chin1 << std::endl;

// Use iostream iterator operations
    char c_val('v');
    std::cout << "c_val = ";
    chout0 = c_val;
    std::cout << std::endl;

    double d_val(84.34);
    std::cout << "d_val = ";
    dout0 = d_val;
    std::cout << std::endl;

// Read and write iostream iterators
    std::ifstream ifs("topics.txt");
    if(ifs.is_open()){
        std::istream_iterator<std::string> str_it(ifs);
        std::istream_iterator<std::string> str_end;
        while(++str_it != str_end)
            std::cout << *str_it << std::endl;
    }
    return 0;
}
