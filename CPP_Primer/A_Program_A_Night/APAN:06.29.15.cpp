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
    student0.emplace("insert", 12);
    std::vector<std::pair<std::string, int>> pvec{{"one", 1}, {"one", 4}, {"tw0", 2}, {"three", 3}};
    student0.insert(pvec.cbegin(), pvec.cend());
    std::initializer_list<std::pair<const std::string, int>> pil{{"four1", 4}, {"five1", 5}, {"six1", 6}};
    student1.insert(pil);
    student1.insert({{"four", 4}, {"five", 5}, {"six", 6}});
    student0.insert(student0.cend(), p2);
    student1.emplace_hint(student1.end(), "emplace", 43);

// Print all maps
    print_map(student0, "student0");
    print_map(student1, "student1");

// Accessing elements
    std::cout << "student0[string1] = " << student0["string1"] << std::endl;
    std::cout << "student1[four] = " << student1.at("four") << std::endl;
    std::cout << "the count of \"one\" in student0 is : " << student0.count("one") << std::endl;
    std::map<std::string, int>::iterator result0 = student0.lower_bound("four");
    std::cout << "lower_bound of student0[four] is : first = " << result0->first << " second = " << result0->second << std::endl;
    decltype(student1.upper_bound("five")) result1 = student1.upper_bound("five");
    std::cout << "upper_bound of student1[five] is : first = " << result1->first << " second = " << result1->second << std::endl;


// Remove elements
    std::cout << "num of elements removed = " << student0.erase("string1") << std::endl;
    print_map(student0, "student0");
    student1.erase(student1.begin());
    print_map(student1, "student1");
    auto result2 = student0.erase(student0.begin(), ++student0.begin());
    std::cout << "last element erased = " << result2->first << " and " << result2->second << std::endl;

        return 0;
}

void print_map(const std::map<std::string, int> map_arg, std::string name)
{
    std::cout << name << " :\n";
    for(auto ele : map_arg)
        std::cout << "first : " << ele.first << " second : " << ele.second << std::endl;
    std::cout << std::endl;
}
