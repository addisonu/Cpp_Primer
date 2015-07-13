// DATE : 07/03/15
// FILE : APAN:07.03.15.cpp
// DESC : Program in series of data structure APANs
//  1) adaptor : stack

#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <stack>
#include <utility>

template <typename T>  void print(const T &obj, std::string name);
template <typename T> void print_stack(T stk, std::string name);

int main()
{
    std::vector<int> ivec{1, 2, 3, 4, 5};
    print(ivec, "ivec");

    std::deque<int> ideq(9, 9);
    ideq.insert(ideq.begin(), ivec.cbegin(), ivec.cend());
    print(ideq, "ideq");

// Create stack objects
    std::stack<int> stk0;
    std::stack<int, std::vector<int>> stk1(ivec);
    std::stack<int> stk2(ideq);

// Print all stacks
    std::cout << "Create stsacks\n";
    print_stack(stk0, "stk0");
    print_stack(stk1, "stk1");
    print_stack(stk2, "stk2");

// Use stack operations
    std::cout << std::boolalpha;
    std::cout << "stk0.empty : " << stk0.empty() << std::endl;
    std::cout << "stk1.size : " << stk1.size() << std::endl;
    swap(stk0, stk2);
    stk0.swap(stk2);
    stk2.pop();
    stk1.push(7);
    stk0.emplace(8);
    std::cout << "stk1.top : " << stk1.top() << std::endl;
    std::cout << "stk0.top : " << stk0.top() << std::endl;
}

template <typename T>  void print(const T &obj, std::string name)
{
    std::cout << name << " :\n";
    for(auto val : obj)
        std::cout << val << " ";
    std::cout << std::endl;
}

template <typename T> void print_stack(T stk, std::string name)
{
    std::cout << name << " :\n";
    std::size_t sz = stk.size();
    for(std::stack<int>::size_type i = 0; i != sz; ++i){
        std::cout << stk.top();
        stk.pop();
    }
    std::cout << std::endl;
}
