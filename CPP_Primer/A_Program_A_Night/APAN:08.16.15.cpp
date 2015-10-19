// DATE : 10/19/15
// FILE : APAN:08.16.15.cpp
// DESC : Generatre true table of four arguments with matrix

#include <vector>
#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>

std::vector<unsigned long> GenerateFlags(unsigned num_of_args);
//std::vector<bool> GenerateFlags(unsigned num_of_args);

int main(int argc, char **argv)
{
    unsigned num_of_args = atoi(argv[1]);
    std::vector<unsigned long> flags = GenerateFlags(num_of_args);
    unsigned cnt(0);
    for(auto ele : flags){
        std::cout << ele << " ";
        if(++cnt == /*pow(2, */num_of_args)/*)*/{
            std::cout << std::endl;
            cnt = 0;
        }
    }
    return 0;
}

//std::vector<bool> GenerateFlags(unsigned num_of_args)
std::vector<unsigned long> GenerateFlags(unsigned num_of_args)
{
// Create vector to return holding unsigned long values
    std::vector<unsigned long> flags(num_of_args, 0);

// Get the number of values in table
    std::vector<bool>::size_type table_sz = pow(2, num_of_args) * num_of_args;
    decltype(table_sz) column_sz = pow(2, num_of_args);

    std::cout << "Table size is : " << table_sz << std::endl;
    std::cout << "Column size is : " << column_sz << std::endl;

// Create vector to hold bool values
    std::vector<bool> table;//(table_sz, 0);

// Create value to alternate bool
    unsigned flip  = 0, entry(0);
    bool table_val = 1;

// Loop through each column
    for(decltype(table.size()) i = 0; i != num_of_args; ++i){
        for(decltype(table.size()) j = 0; j != (column_sz / pow(2, flip)); ++j){
            //std::cout << true << " ";
            for(decltype(table.size()) k = 0; k != pow(2, flip); ++k){
// Push back total number of entries for each column
                //std::cout << table_val << " ";
                table.push_back(table_val);
                if(table_val)
                    flags[i] |= (1ul << entry);
                ++entry;
            }
            table_val = !table_val;
        }
        ++flip;
        //std::cout << std::endl;
    }


    return flags;
}
