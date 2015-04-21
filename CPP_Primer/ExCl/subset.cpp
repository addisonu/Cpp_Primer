// Test if one set is a subset of another
// A set A is a subset of set B if for all x element of A, x is an element of B

#include <iostream>
#include <set>
#include <sstream>
#include <string>

bool subset(std::set<int> A, std::set<int> B);

int main()
{
    int val(0);
    std::string input;

    do{
        std::set<int> A, B;

        std::cout << "Please enter values for set A on a single line.\n";
        std::getline(std::cin, input);
        std::stringstream ss1(input);

        while(ss1 >> val)
            A.insert(val);

        std::cout << std::endl;
        std::cin.clear();

        std::cout << "Please enter values for set B on a single line.\n";
        std::getline(std::cin, input);
        std::stringstream ss2(input);

        while(ss2 >> val)
            B.insert(val);

        std::cout << std::endl;
        std::cin.clear();

        bool A_bigger = subset(B, A);
        bool B_bigger = subset(A, B);

        if(A_bigger != B_bigger){
            std::cout << (A_bigger > B_bigger ? "B is a subset of A" : "A is a subset of B") << std::endl;
        }
        else
            std::cout << (A_bigger == false ? "A and B are disjoint or have a nonempty intersection." : "A is equal to B.") << std::endl;

        std::cout << "\nCompare two more sets? (y/n) : ";
        std::getline(std::cin, input);
        std::cin.clear();
    }while(tolower(input[0]) == 'y');

    return 0;
}

bool subset(std::set<int> A, std::set<int> B)
{
    unsigned cnt(0);
    for(auto a : A){
        for(auto b : B){
            if(a == b){
                ++cnt;
                break;
            }
        }
    }
    return cnt == A.size();
}
