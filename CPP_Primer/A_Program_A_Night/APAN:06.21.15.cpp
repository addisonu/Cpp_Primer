// DATE : 06/21/15
// FILE : APAN:06.21.15
// DESC : Works with patterns using regex class

#include <iostream>
#include <regex>
#include <string>

int main()
{
    std::string str0("Best bubbles in the area are super yummy! But expect a few bad lemons from time to time.");
    std::string str1("Udon may go well with bubbles");


// Store pattern in string
    std::string pattern("yum");
    pattern = "[[:alpha:]]*" + pattern + "[[:alpha:]]*";

// Define and invoke regex
    std::regex reg(pattern);
    std::smatch result;

    if(std::regex_search(str0, result, reg)){
        std::cout << "pattern found : " << std::endl;
        std::cout << result.str() << std::endl;
    }
    else
    std::cout << "No match.\n";
    return 0;
}
