// DATE : 05/14/15
// FILE : num_sort.cpp
// DESC : Write a program to sort a list of numbers provided on standard input (for instance, the numbers you generated above). You are NOT allowed to call external routines to do the sorting for you. After sorting the numbers, print them out.

#include <iostream>
#include <vector>
#include <string>

int main(int argc, char **argv)
{
// Push numbers into container
    long val(0);
    std::vector<long> lvect;

    std::cout << "Enter the numbers to be sorted.\n";
    while(std::cin >> val){
        lvect.push_back(val);
    }
// Use basic selection sort with loop
    long min(0), tmp(0);
    std::size_t m_pos(0);

    for(std::size_t i = 0; i != lvect.size(); ++i){
        min = lvect[i];
        m_pos = i;
        for(std::size_t j = i; j != lvect.size(); ++j){
            if(min > lvect[j]){
                min = lvect[j];
                m_pos = j;
            }
        }
            tmp = lvect[i];
            lvect[i] = min;
            lvect[m_pos] = tmp;
    }

    for(auto ele : lvect)
        std::cout << ele << " ";
    std::cout << std::endl;

    return 0;
}
