// DATE : 06/29/15
// FILE : APAN:06.29.15.cpp
// DESC : Program in series of data structure APANs
//  1) map

#include <iostream>
#include <initializer_list>
#include <string>
#include <vector>
#include <utility>
#include <map>

void print_map(const std::map<std::string, int> map_arg, std::string name);

int main()
{
// Create pair objects
    std::pair<std::string, int> p0;
    std::pair<std::string, int> p1("string1", 1);
    std::pair<std::string, int> p2 = {"string2", 2};
    std::pair<std::string, int> p3 = std::make_pair("string3", 3);

// Use pair operations
    std::cout << std::boolalpha;
    std::cout << "p1.first = " << p1.first << " p1.second = " << p1.second << std::endl;
    std::cout << "p1.first > p2.first : " << (p1.first > p2.first) << std::endl;
    std::cout << "p2.second == p3.second " << (p2.second == p3.second) << std::endl;
    std::cout << "p1 != p3 : " << (p1 != p3) << std::endl;

// Create map objects
    std::map<std::string, int> student0;
    std::map<std::string, int> student1{{"Abel", 1000}, {"Betty", 1001}, {"Caylin", 1002}, {"Darnel", 1003}};

// Print all maps
    print_map(student0, "student0");
    print_map(student1, "student1");

// Use map operations
// Add elements
    student0.insert(p1);
    student0.emplace(std::make_pair<std::string, int>("insert", 12));
    std::vector<std::pair<std::string, int>> pvec{{"one", 1}, {"tw0", 2}, {"three", 3}};
    student0.insert(pvec.cbegin(), pvec.cend());
    //std::initializer_list<std::pair<std::string, int>> pil{{"four", 4}, {"five", 5}, {"six", 6}};
    student1.insert({{"four", 4}, {"five", 5}, {"six", 6}});
    student0.insert(student0.cend(), p2);
    student1.insert(student1.cend(), std::pair<std::string, int>("emplace", 43));

// Print all maps
    print_map(student0, "student0");
    print_map(student1, "student1");

// Accessing elements
    std::cout << "student0[string1] = " << student0["string1"] << std::endl;
    std::cout << "student1[four] = " << student1.at("four") << std::endl;

// Remove elements
    std::cout << "num of elements removed = " << student0.erase("string1") << std::endl;
    print_map(student0, "student0");
    student1.erase(student1.begin());
    print_map(student1, "student1");
    auto result = student0.erase(student0.begin(), ++student0.begin());
    std::cout << "last element erased = " << result->first << " and " << result->second << std::endl;

        return 0;
}

void print_map(const std::map<std::string, int> map_arg, std::string name)
{
    std::cout << name << " :\n";
    for(auto ele : map_arg)
        std::cout << "first : " << ele.first << " second : " << ele.second;
    std::cout << std::endl;
}
