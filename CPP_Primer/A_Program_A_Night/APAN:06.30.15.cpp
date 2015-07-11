// DATE : 06/30/15
// FILE : APAN:06.30.15.cpp
// DESC : Program in series of data structure APANs
//  1) set

#include <iostream>
#include <set>
#include <string>
#include <initializer_list>

void print_set(const std::set<std::string> &obj, std::string name);

int main()
{
// Create set objects
    std::set<std::string> set0;
    std::set<std::string> set1{"ONE", "one", "TWO", "two", "THREE", "three"};
    std::set<std::string> set2 = {"FOUR", "four", "FIVE", "five", "SIX", "six"};

// Use set operations
// Adding elements
    set0.insert("insert");
    set1.emplace(std::string(8, 'g'));
    std::string str_arr[]{"insert1", "insert2", "insert3"};
    set2.insert(std::begin(str_arr), std::end(str_arr));
    std::initializer_list<std::string> il{"1", "2", "3"};
    set0.insert(il);
    set1.insert({"4", "5", "6"});
    set2.insert(set2.begin(), "insert string");
    set0.emplace_hint(set0.end(), 9, 'u');

// Print all sets
    print_set(set0, "set0");
    print_set(set1, "set1");

// Accessing elements
    set0.find("one");
    std::cout << "the count of \"two\" is : " << set0.count("two") << std::endl;
    std::cout << "lower_bound of set1 is : " << *set1.lower_bound("4") << std::endl;
    std::cout << "upper_bound of set2 is : " << *set2.upper_bound("insert string") << std::endl;
    std::pair<std::set<std::string>::iterator, std::set<std::string>::iterator> result = set2.equal_range("insert string");
    std::cout << "result.first = " << *result.first << " result.second = " << *result.second << std::endl;

// Removing elements
    set0.erase("1");
    set1.erase(set1.cbegin());
    set2.erase(set2.cbegin(), ++set2.cbegin());

// Print all sets
    print_set(set0, "set0");
    print_set(set1, "set1");

    return 0;
}
void print_set(const std::set<std::string> &obj, std::string name)
{
    std::cout << name << " :\n";
    for(auto ele : obj)
        std::cout << ele << " ";
    std::cout << std::endl;
}
