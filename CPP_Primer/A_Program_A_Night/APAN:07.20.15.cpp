// DATE : 07/20/15
// FILE : APAN:07.20.15.cpp
// DESC : Use condition state operations to check state of iostream object

#include <iostream>
#include <string>


int main()
{
// Create references to iostream objects
    std::ostream &out = std::cout;
    std::istream &in = std::cin;
    std::cout << std::boolalpha;

// Use iostream condition state types and operations
    std::cout << "eof? " << in.eof() << std::endl; // true if eofbit is set
    std::cout << "fail? " << out.fail() << std::endl; // true if failbit or badbit is set
    std::cout << "bad? " << in.bad() << std::endl; // true if badbit is set
    std::cout << "good? " << out.good() << std::endl; // true if stream is valid

    std::iostream::iostate st0 = in.rdstate();
    std::iostream::iostate st1 = out.rdstate();

    in.clear(); //reset stream to valid state
    out.clear(std::iostream::badbit); // reset stream condition to flags

    in.setstate(std::iostream::failbit); // add conditions flags to stream
    out.setstate(std::iostream::eofbit); // add conditions flags to stream
    in.setstate(std::iostream::goodbit); // add conditions flags to stream

    return 0;
}
