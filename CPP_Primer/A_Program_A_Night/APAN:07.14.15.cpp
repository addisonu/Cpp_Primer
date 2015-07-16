// DATE : 07/14/15
// FILE : APAN:07.14.15.cpp
// DESC : Use stringstreams to manipulate string data and convert data to and from a string

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <typeinfo>

int main()
{
    std::vector<std::string> vword{"one", "two", "three", "four"};
    std::vector<std::string> vline = {"first line in the vect", "434 Sugar plum ln (823)433-8347", "last line in the paragraph"};
    std::vector<std::string> vnum{"4334.3", "56", "543215", "65446543543243222543254", "true"};
    std::string word, line;

// Create stringstreams
    std::stringstream ss0;
    std::stringstream ss1("stringstream");
    std::istringstream iss;
    std::ostringstream oss;

// Use stringstream operations
    ss0.str("copy of a string");
    std::cout << "ss0.str" << ss0.str() << std::endl;
    std::cout << "ss1.str : " << ss1.str() << std::endl << std::endl;

// Convert strings to closest integral type
    std::istringstream iss0(vnum[0]);
    double d_val;
    iss0 >> d_val;
    std::cout << "d_val = " << d_val << std::endl;
    std::cout << "type of d_val : " << typeid(d_val).name() << std::endl << std::endl;

    std::istringstream iss1(vnum[1]);
    short s_val;
    iss1 >> s_val;
    std::cout << "s_val = " << s_val << std::endl;
    std::cout << "type of s_val : " << typeid(s_val).name() << std::endl << std::endl;

    std::istringstream iss2(vnum[2]);
    int i_val;
    iss2 >> i_val;
    std::cout << "i_val = " << i_val << std::endl;
    std::cout << "type of i_val : " << typeid(i_val).name() << std::endl;

    std::istringstream iss3(vnum[3]);
    long l_val;
    iss3 >> l_val;
    std::cout << "l_val = " << l_val << std::endl;
    std::cout << "type of l_val : " << typeid(l_val).name() << std::endl << std::endl;

    std::istringstream iss4(vnum[4]);
    bool b_val;
    iss4 >> b_val;
    std::cout << std::boolalpha;
    std::cout << "b_val = " << b_val << std::endl;
    std::cout << "type of b_val : " << typeid(b_val).name() << std::endl << std::endl;

// Write strings with istringstream
    while(std::cin >> word && (vword.size() < 50)){
        iss.str(word);
        vword.push_back(iss.str());
    }

    while(std::getline(std::cin, line)){
        iss.str(line);
        vline.push_back(iss.str());
    }

// Print vword and vline
    std::cout << "\nvword :\n";
    for(auto wd : vword)
        std::cout << wd << " ";
    std::cout << std::endl;

    std::cout << "\nvline :\n";
    for(auto ln : vline)
        std::cout << ln << std::endl;

// Write strings with ostringstream
    oss.str("string to write");
    for(auto ele : vword)
        oss << ele;
    for(auto ele : vline)
        oss << ele;

    std::cout << "oss.str : " << oss.str() << std::endl;

    return 0;
}
