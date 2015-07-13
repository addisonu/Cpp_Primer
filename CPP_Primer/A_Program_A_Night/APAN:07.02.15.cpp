// DATE : 07/02/15
// FILE : APAN:07.02.15.cpp
// DESC : Program in series of data structure APANs
//  1) multimap

#include <iostream>
#include <initializer_list>
#include <string>
#include <vector>
#include <utility>
#include <map>

void print_map(const std::multimap<std::string, std::vector<std::string>> map_arg, std::string name);

int main()
{
// Elements for multimaps
    using ele1 = std::string;
    using ele2 = std::vector<ele1>;
    ele1 str0("string0");
    ele2 vec0{"a", "vec", "zero"};
    ele1 str1("string1");
    ele2 vec1{"multi", "map", "vec"};
    ele1 str2("string2");
    ele2 vec2{"open", "vec", "of", "chars"};
    ele1 str3("string0");
    ele2 vec3{"b", "tec", "uero"};

// Define multimap objects
    typedef std::multimap<std::string, std::vector<std::string>> m_type;
    m_type mmp0;
    m_type mmp1{{str1, vec1}};
    m_type mmp2 = {{str2, vec2}};
    std::initializer_list<std::pair<const ele1, ele2>> il{{str0, vec0}, {str1, vec1}, {str2, vec2}, {str3, vec3}};
    m_type mmp3(il);

// Print multimap objects
    std::cout << "\nCreate multimaps\n";
    print_map(mmp0, "mmp0");
    print_map(mmp1, "mmp1");
    print_map(mmp2, "mmp2");
    print_map(mmp3, "mmp3");

// Use multimap operations
// Add elements
    mmp0.insert(std::make_pair<ele1, ele2>(std::string("insert"), std::vector<std::string>{"Insert", "a", "new", "pair"}));
    mmp1.emplace(std::make_pair("string5",ele2({"emplace", "a", "seq", "vector"})));
    mmp2.insert(mmp0.cbegin(), mmp0.cend());
    mmp3.insert(il);
    mmp0.insert(mmp0.cbegin(), std::make_pair("string6", ele2(7, "seven")));
    mmp1.emplace_hint(mmp1.cbegin(), "string7", ele2(8, "eight"));

// Print multimap objects
    std::cout << "Insert elements\n";
    print_map(mmp0, "mmp0");
    print_map(mmp1, "mmp1");
    print_map(mmp2, "mmp2");
    print_map(mmp3, "mmp3");

// Access elements
    std::cout << "\nAccess elements\n";
    auto result = mmp0.find("string6");
    std::cout << "mmp0.find(string6) first : " << result->first << "\nsecond : \n";
    for(auto ele : result->second)
        std::cout << ele << " ";
    std::cout << std::endl;

    std::cout << "the count of element with key = \"string5\" is : " << mmp1.count("string5") << std::endl;

    auto result1 = mmp2.lower_bound("string6");
    std::cout << "first element with key = \"string6\" is, first :" << result->first
    << "\nsecond :\n";
    for(auto val : result->second)
        std::cout << val << " ";
    std::cout << std::endl;

    auto result2 = mmp3.upper_bound("string7");
    std::cout << "last element with key = \"string7\" is, first : " << result2->first
        << "\nsecond :\n";
    for(auto val : result->second)
        std::cout << val << " ";
    std::cout << std::endl;

    auto result3 = mmp3.equal_range("string0");
    std::cout << "range of elments with the same key\n";
    for(; result3.first != result3.second; ++result3.first){
        for(auto val : result3.first->second)
            std::cout << val << " ";
        std::cout << std::endl;
    }
// Erase elements
    mmp0.erase("insert");
    mmp1.erase(mmp1.cbegin());
    mmp2.erase(++mmp2.cbegin(), --mmp2.cend());

// Print multimap objects
    std::cout << "\nErase elements\n";
    print_map(mmp0, "mmp0");
    print_map(mmp1, "mmp1");
    print_map(mmp2, "mmp2");
    print_map(mmp3, "mmp3");

    return 0;
}

void print_map(const std::multimap<std::string, std::vector<std::string>> map_arg, std::string name)
{
    std::cout << name << " :\n";
    for(auto ele : map_arg){
        std::cout << "first : " << ele.first << std::endl;
        std::cout << "second :\n";
        for(auto val : ele.second)
            std::cout << val << " ";
        std::cout << std::endl;
    }
    std::cout << std::endl;
}
