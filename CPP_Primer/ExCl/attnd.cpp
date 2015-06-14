// DATE : 06/13/15
// FILE : attnd.cpp
// DESC : Small program to demonstrate when a return value isn't needed

#include <iostream>
#include <string>

void attendance(std::string *files[]);

int main()
{
// objects to : hold all files, hold each file
    std::string class1[3] = {"Sally", "James", "Bond"};
    std::string class2[3] = {"Sammy", "Tulsa", "Fred"};
    std::string class3[3] = {"Den", "Judy", "Shelly"};

    std::string *files[3] = {class1, class2, class3}; // hold attendance files for each class

// Call attendance function
    attendance(files);

// Print all name to check that attendance is being recorded correctly
    for(auto &file : files){
        for(std::size_t k = 0; k != 3; ++k){
            std::cout << "name : " << file[k] << std::endl;
        }
    }
    return 0;
}

void attendance(std::string *files[])
{
    std::string name; // hold copy of each name
    std::string *file = nullptr;
    char answer(' ');

// Iterate through array to access each file
    for(std::size_t i = 0; i != 3; ++i){
        file = files[i]; // file being looked at
        for(std::size_t j = 0; j != 3; ++j){
            name = file[j]; // name in file
            std::cout << "Did " << name << " attend class today?\n";
            std::cin >> answer;
            file[j] = (name + ": " + answer);
        }
    }
}
