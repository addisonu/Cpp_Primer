// DATE : 07/04/15
// FILE : APAN:07.04.15.cpp
// DESC : Program in series of data structure APANs
//  1) adaptor : queue

#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <queue>
#include <utility>

template <typename T>  void print(const T &obj, std::string name);
template <typename T> void print_queue(T que, std::string name);
void print_queue(std::queue<int, std::vector<int>> que, std::string name);

int main()
{
    std::vector<int> ivec{1, 2, 3, 4, 5};
    print(ivec, "ivec");

    std::deque<int> ideq(9, 9);
    ideq.insert(ideq.begin(), ivec.cbegin(), ivec.cend());
    print(ideq, "ideq");

// Create queue objects
    std::queue<int> que0;
    std::queue<int, std::vector<int>> que1(ivec);
    std::queue<int> que2(ideq);
    ivec.insert(ivec.cend(), {9, 8, 666, 545});
    std::queue<int, std::vector<int>> que3(ivec);

// Print all queues
    std::cout << "Create stsacks\n";
    print_queue(que0, "que0");
    //print_queue(que1, "que1");
    print_queue(que2, "que2");
    //print_queue(que3, "que3");

// Use queue operations
    std::cout << std::boolalpha;
    std::cout << "que0 == que2 : " << (que0 == que2) << std::endl;
    std::cout << "que1 != que3 : " << (que1 != que3) << std::endl;
    std::cout << "que2 < que0 : " << (que2 < que0) << std::endl;
    std::cout << "que3 > que1 : " << (que3 > que1) << std::endl;
    std::cout << "que0.empty : " << que0.empty() << std::endl;
    std::cout << "que1.size : " << que1.size() << std::endl;
    swap(que0, que2);
    que1.swap(que3);
    que0.pop();
    que0.push(3);
    que2.push(3);
    std::cout << "que2.front : " << que2.front() << std::endl;
    std::cout << "que0.back : " << que0.back() << std::endl;
    que0.push(3);
    que0.emplace(4);
    }

template <typename T>  void print(const T &obj, std::string name)
{
    std::cout << name << " :\n";
    for(auto val : obj)
        std::cout << val << " ";
    std::cout << std::endl;
}

template <typename T> void print_queue(T que, std::string name)
{
    std::cout << name << " :\n";
    std::size_t sz = que.size();
    for(std::queue<int>::size_type i = 0; i != sz; ++i){
        std::cout << que.front() << " ";
        que.pop();
    }
    std::cout << std::endl;
}
/*
void print_queue(const std::queue<int, std::vector<int>> &que, std::string name)
{
    std::cout << name << " :\n";
    std::size_t sz = que.size();
    //std::reverse(que.begin(), que.end());
    std::deque<int> tmp(que);
    for(std::queue<int>::size_type i = 0; i != sz; ++i){
        //std::cout << que[i] << " ";
        std::cout << que.front() << " ";
        que.pop();
    }
    std::cout << std::endl;
}
*/
