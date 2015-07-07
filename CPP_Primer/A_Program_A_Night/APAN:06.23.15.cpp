// DATE : 06/23/15
// FILE : APAN:06.23.15.cpp
// DESC : Write class with delegating constructors

#include <iostream>
#include <utility>
#include <string>

class Del{

// CONSTRUCTORS //

public :

// Non-delegating constructors
    Del(double mem0_arg, int mem1_arg, std::string mem2_arg, std::initializer_list<int> mem3_arg) : mem0(mem0_arg), mem1(mem1_arg), mem2(mem2_arg), mem3(mem3_arg) { }

    Del(double mem0_arg, int mem1_arg, std::initializer_list<int> mem3_arg) : mem0(mem0_arg), mem1(mem1_arg), mem3(mem3_arg) { }

    Del(double mem0_arg, int mem1_arg) { }

// Delegating constructors
    Del() : Del(0, 0, "", { }) { }

    Del(double mem0_arg, std::initializer_list<int> mem3_arg) : Del(mem0_arg, 0, mem3_arg) { }

    Del(double mem0_arg, int mem1_arg, std::pair<std::string, std::initializer_list<int>> mem_pr_arg) : Del(mem0_arg, mem1_arg, mem_pr_arg.first, mem_pr_arg.second) { }

// MEMBER FUNCTIONS //
    void print_mem()
    {
        std::cout << "mem0 = " << mem0 << std::endl;
        std::cout << "mem1 = " << mem1 << std::endl;
        std::cout << "mem2 = " << mem2 << std::endl;
        std::cout << "mem3 :\n";
        for(auto val : mem3)
            std::cout << val << " ";
        std::cout << std::endl;
    }

private :

// DATA MEMBERS //
    double mem0 = 0;
    int mem1 = 1;
    std::string mem2 = "mem2";
    std::initializer_list<int> mem3 = {1, 2, 3,};
};

int main()
{
// Create objects
    Del d0;
    Del d1(8.1, {9, 7, 5});
    Del d2(7.6, 9, std::pair<std::string, std::initializer_list<int>>("delegating constructor string", {8, 7, 6, 5 ,4}));

// Print elements
    d0.print_mem();
    d1.print_mem();
    d2.print_mem();

    return 0;
}
