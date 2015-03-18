//Unit tests for Cpp_webpage class

#include "cpp_webpage.h"

int main()
{
    std::fstream txt("../index_webpage/bo_parsed.txt", std::fstream::in | std::fstream::out);
    std::string str = "";

    Cpp_webpage test("test webpage", "This is a test ... testing", 1, txt, str);
    return 0;
}
