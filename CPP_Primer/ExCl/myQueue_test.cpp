// Implement a queue using STL stack adapter

#include <iostream>
#include <stack>
#include <string>
#include "myQueue.h"

int main()
{
    myQueue<int> q1, q2, q3;

    for(int i = 0; i < 10; ++i){
        q1.push(i);
    }

        for(int i = 0; i < 7; ++i){
        q2.push(i);
    }

    std::cout << std::endl;
    std::cout << "Initial Queue : " << std::endl;
    while(!q1.empty()){
        std::cout << q1.front() << " ";
        q3.push(q1.front());
        q1.pop();
    }
    std::cout << std::endl;
    std::cout << "Size of Q3 : " << q3.size() << std::endl;
    std::cout << "Back element of Q3 : " << q3.back() << std::endl;
    std::cout << std::endl;
    q3.swap(q2);
    std::cout << "Size of Q3 (after swap) : " << q3.size() << std::endl;
    std::cout << std::endl;
    std::cout << "Size of Q2 (after swap) : " << q2.size() << std::endl;

    return 0;
}
