// DATE : 06/08/15
// FILE : APAN:06.08.15.cpp
// DESC : Program in series of library algorithm APANs
//  1) Find

#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <deque>
#include <array>
#include <list>
#include <forward_list>
#include <initializer_list>

template <typename T> void print(const T &obj, const std::string &name);

int main()
{
// Containers to search
    std::vector<char> cvec = {'v','e','c','t','o','r','i','s','y','h','e','b','y','a','u','b','e','s','s','d','e','q'};
    std::string str("String_arg");
    std::deque<char> cdeq(str.cend() - 4, str.cend());
    cdeq.insert(cdeq.cbegin(), {'d','e','q','u','e'});
    constexpr unsigned sz = 8;
    std::array<char, sz> carr{{'e','i','g','h','t','e','e','g'}};
    std::initializer_list<char> il0{'u','u','u','l','l','l','i','s','c','o','n','t','a','i','n','e','r','e','l','e','m','e','n','t','s'};
    std::list<char> clst(il0);
    std::initializer_list<char> il1{'f','o','r','w','a','r','d','l','i','s','c','o','n','t','a','i','n','e','r','e','l','e','m','e','n','t','s'};
    std::forward_list<char> cflst(il1);
    const char cstr[] = "c-style day string_day_arg";

// Print all sequences
    std::cout << "\nPrint all container elements\n";
    print(cvec, "cvec");
    print(str, "str");
    print(cdeq, "cdeq");
    print(carr, "carr");
    print(clst, "clst");
    print(cflst, "cflst");
    print(cstr, "cstr");

    std::cout << std::boolalpha; // print bool literals

// Find elements

    std::cout << "\nFind element(s)\n";
    std::cout << "find() : " << *find(cvec.cbegin(), cvec.cend(), 'u') << std::endl; // returns iterator to first element in range matching arg
    std::cout << "find_if() : " << *find_if(str.begin(), str.end(), [] (const char ch) -> bool { return ch == '_'; }) << std::endl; // returns iterator to first element for which unaryPred evaulates to true
    std::cout << "find_if_not() : " << *find_if_not(cdeq.begin(), cdeq.end(), [] (const char ch) -> bool { return ch < 'p'; }) << std::endl; // returns iterator to first element for which unaryPred evaluates to false
    std::cout << "count() : " << std::count(carr.cbegin(), carr.cend(), 'e') << std::endl; // returns count of arg frequency
    std::cout << "count_if() : " <<  count_if(cflst.cbegin(), cflst.cend(), [] (const char ch) -> bool { return ch >= 'r' && ch <= 'y'; }) << std::endl; // return count of elements for which unaryPred evalautes to true
    std::cout << "all_of() : " << all_of(clst.cbegin(), clst.cend(), [] (const char ch) -> bool { return ch >= 'a' && ch <= 'z'; }) << std::endl; // returns true if unaryPred evaluates to true for every element
    std::cout << "any_of() : " << std::any_of(std::begin(cstr), std::end(cstr), [] (const char ch) -> bool { return ch == 'q'; }) << std::endl; // return true if unaryPred evaluates to true for one or more elements
    std::cout << "none_of() : " << std::none_of(cvec.cbegin(), (cvec.cbegin() + cvec.size()/2), [] (const char ch) -> bool { return ch == 'z'; }) << std::endl; // returns true if unaryPred evaluates to false for every element

// Find duplicate or one of multiple values

    std::cout << "\nFind duplicate or one of multiple values\n";
    std::cout << "adjacent_find() : " << *std::adjacent_find(str.cbegin(), str.cend()) << std::endl;
    std::cout << "adjacent_find() : " << *std::adjacent_find(carr.cbegin(), carr.cend(), [] (const char ch1, const char ch2) -> bool { return ch1 == ch2; }) << std::endl; // return iterator to first adjacent pair of duplicate elements, overloaded to take binaryPred
    std::cout << "search_n() : " << *std::search_n(carr.cbegin(), carr.cend(), 2, 'e') << std::endl;
    std::cout << "search_n() : " << *std::search_n(clst.cbegin(), clst.cend(), 3, 'l', [] (const char ch1, const char ch2) -> bool { return ch1 == ch2; }) << std::endl; // returns an iterator to the beginning of subsequence of n duplicate elements e.g. uuuu, n == 4

// Find subsequences

    std::cout << "\nFind subsequences\n";
    auto pos = std::search(cflst.begin(), cflst.end(), clst.begin(), ++(++clst.begin()));
    std::cout << "search() : " << ((pos != cflst.end()) ? *pos : ' ') << std::endl;
    auto pos1 = std::search(cdeq.cbegin(), cdeq.cend(), cvec.cend() - 3, cvec.cend(), [] (const char ch1, const char ch2) -> bool { return ch1 == ch2; });
    std::cout << "search() : " << ((pos1 != cdeq.end()) ? *pos1 : ' ') << std::endl; // returns iterator to first element of first input range subsequence matching second input range, overloaded to take binaryPred
    std::initializer_list<char> il2{'r','e'};
    auto pos2 = find_first_of(str.cbegin(), str.cend(),il2.begin(), il2.end());
    std::cout << "find_first_of() : " << (pos2 != str.cend() ? *pos2 : ' ') << std::endl;
    std::initializer_list<char> il3{'S','t'};
    auto pos3 = find_first_of(str.cbegin(), str.cend(),il3.begin(), il3.end());
    std::cout << "find_first_of() : " << (pos3 != str.cend() ? *pos3 : ' ') << std::endl;
 // returns iterator to first occurence in first input range of any element from second input range, overloaded to take binaryPred
    std::initializer_list<char> il4{'e','a'};
    auto pos4 = std::find_end(carr.cbegin(), carr.cend(), il4.begin(), il4.end());
    std::cout << "find_end() : " << (pos4 != carr.cend() ? *pos4 : ' ') << std::endl;
    std::initializer_list<char> il5{'d','a','y'};
    auto pos5 = std::find_end(std::begin(cstr), std::end(cstr), il5.begin(), il5.end(), [] (const char ch1, const char ch2) -> bool { return ch1 == ch2; });
    std::cout << "find_end() : " << (pos5 != carr.cend() ? *pos5 : ' ') << std::endl;
 // returns iterator to last position in first input range at which subsequence of second input range occurs

    return 0;
}

template <typename T> void print(const T &obj, const std::string &name)
{
    std::cout << name << " :" << std::endl;
    for(auto ele : obj)
        std::cout << ele;
    std::cout << std::endl;
}
