// DATE : 07/05/15
// FILE : APAN:07.05.15.cpp
// DESC : Program in series of data structure APANs
//  1) adaptor : priority_queue

#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <queue>
#include <utility>

template <typename T>  void print(const T &obj, std::string name);
template <typename T> void print_pqueue(T pque, std::string name);

int main()
{
    std::vector<int> ivec{1, 2, 3, 4, 5};
    print(ivec, "ivec");

    std::deque<int> ideq(9, 9);
    ideq.insert(ideq.begin(), ivec.cbegin(), ivec.cend());
    print(ideq, "ideq");

// Create priority_queue objects
    std::priority_queue<int> que0;
    std::priority_queue<int> que1(ivec.cbegin(), ivec.cend());
    std::priority_queue<int> que2(ideq.cbegin(), ideq.cend());
    ivec.insert(ivec.cend(), {9, 8, 666, 545});
    std::priority_queue<int> que3(ivec.cbegin(), ivec.cend());

// Print all priority_queues
    std::cout << "Create stsacks\n";
    print_pqueue(que0, "que0");
    print_pqueue(que1, "que1");
    print_pqueue(que2, "que2");
    print_pqueue(que3, "que3");

// Use priority_queue operations
    std::cout << std::boolalpha;
    std::cout << "que0.empty : " << que0.empty() << std::endl;
    std::cout << "que1.size : " << que1.size() << std::endl;
    swap(que0, que2);
    que1.swap(que3);
    que0.push(3);
    que0.pop();
    que2.push(3);
    std::cout << "que2.top : " << que2.top() << std::endl;
    que0.emplace(4);
}

template <typename T>  void print(const T &obj, std::string name)
{
    std::cout << name << " :\n";
    for(auto val : obj)
        std::cout << val << " ";
    std::cout << std::endl;
}

template <typename T> void print_pqueue(T que, std::string name)
{
    std::cout << name << " :\n";
    std::size_t sz = que.size();
    for(std::priority_queue<int>::size_type i = 0; i != sz; ++i){
        std::cout << que.top() << " ";
        que.pop();
    }
    std::cout << std::endl;
}
