// Write a program to use a conditional operator to find the elements in a vector<int> that have odd value and double the value of each such element
// Two versions : 1) using if statement 2) using conditional operator

#include <vector>
#include <sstream>
#include <iostream>

void odd_if(std::vector<int> vect);
void odd_con(std::vector<int> vect);

int main()
{
    std::vector<int> ivec;
    for(decltype(ivec.size()) i = 1; i != 20; ++i)
            ivec.push_back(i);

    odd_if(ivec);
    odd_con(ivec);

        return 0;
}

void odd_if(std::vector<int> vect)
{
    for(auto ele1 : vect){
        if(ele1 % 2)
            for(auto ele2 : vect)
                if(ele2 && ele2 == (2 * ele1))
                    std::cout << "ele1 = " << ele1 << " and ele2 = " << ele2 << std::endl;
    }
}

void odd_con(std::vector<int> vect)
{
    for(auto ele1 : vect)
        if(ele1 % 2)
            for(auto ele2 : vect){
                if(ele2){
                    std::stringstream ss;
                    ss << "ele1 = " << ele1 << " ele2 = " << ele2 << '\n';
                    std::cout << ((ele2 == 2 * ele1) ? ss.str() : "");
                }
            }
}

