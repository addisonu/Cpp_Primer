//Unit tests for Cpp_webpage class

#include "cpp_webpage.h"

int main()
{
    std::fstream txt("webpages/0.html", std::fstream::in | std::fstream::out | std::fstream::trunc);
    std::string str = "a b c d e f g";

    Cpp_webpage test("test webpage", "This is a test ... testing", 1, txt, str);
    return 0;
}
