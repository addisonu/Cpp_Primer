// DATE : 07/06/15
// FILE : APAN:07.06.15.cpp
// DESC : Faciliites for return types
//  1) Trailing return type
//  2) Returning braced list of values and initializer_list
//  3) Returning pointer to array
//  4) Specify return type with decltype

#include <iostream>
#include <string>
#include <initializer_list>
#include <deque>
#include <vector>

template <typename T> void print(const T &obj, std::string name);
std::deque<int> return_il(int val);
auto return_vect(bool state) -> std::vector<std::string>;
auto str_sz(std::string str) -> decltype(str.size());
const char (*pnt_arr())[6];

int main()
{
    std::deque<int> ideq(return_il(7));
    print(ideq, "ideq");

    std::vector<std::string> svec = return_vect(true);
    print(svec, "svec");

    std::cout << "str_sz() : " << str_sz("What_size_am_I") << std::endl;

    std::cout << "pnt_arr() : " << *pnt_arr() << std::endl;

    return 0;
}

std::deque<int> return_il(int val)
{
    std::initializer_list<int> il{1 * val, 2 * val, 3 * val, 4 * val, 5 * val, 6 * val, 7 * val};
    return il;
}

std::vector<std::string> return_vect(bool state)
{
    if(state)
        return {"string0", "string1", "string2"};
    else
        return {"string4", "string5", "string6"};
}

auto str_sz(std::string str) -> decltype(str.size())
{
    return str.size();
}

template <typename T> void print(const T &obj, std::string name)
{
    std::cout << name << " :\n";
    for(auto val : obj)
        std::cout << val << " ";
    std::cout << std::endl;
}

const char (*pnt_arr())[6]
{
    const char arr[6] = "Hello";
    const char (*pt)[6] = &arr;
    return pt;
}
