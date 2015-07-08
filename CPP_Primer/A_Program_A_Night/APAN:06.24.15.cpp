// DATE : 06.24.15
// FILE : APAN:06.24.15.cpp
// DESC : Use bind to write functions that can be passed to algorithm expecting unary or binary predicates

#include <iostream>
#include <functional>
#include <vector>
#include <string>

bool grows_func(int first, const int &val);
template <class T> void print(const T &obj, std::string name);

int main()
{
    std::vector<int> ivec{5, 65, 3, 43};
    int first = ivec[0];

// Lamda with capture list
    auto grows = [first] (const int &val) -> bool { return val > first; };


// Bind lambda to funcition
    auto grows_bind = std::bind(grows_func, first, std::placeholders::_1);

// Use grows in algorithm
    std::vector<int> dest(ivec.size());
    std::remove_copy_if(ivec.cbegin(), ivec.cend(), dest.begin(), grows);
    print(dest, "dest");

// Use grows_bind in algorithm
    std::remove_copy_if(ivec.cbegin(), ivec.cend(), dest.begin(), grows_bind);
    print(dest, "dest");
   return 0;
}

// Equivalent function to grows
bool grows_func(int first, const int &val)
{
    return val > first;
}

template <class T> void print(const T &obj, std::string name)
{
    std::cout << name << ":\n";
    for(auto ele : obj)
        std::cout << ele << " ";
    std::cout << '\n' << std::endl;
}
