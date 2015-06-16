// DATE : 06/15/15
// FILE : Robot_filter_program.cpp
// DESC : Main program to test Robot_filter class

// LEFT OFF //
/*
 */

// BUGS //
/*
 */

// POSSIBLE SOLUTIONS/ADDITIONS //
/*
 */

// NOTES //
/*
 */

// Library files
#include <iostream>
#include <fstream>
#include <sstream>

// Class files
#include "Robot_filter.h"

int main(int argc, char **argv)
{
    if(argc >= 3){
        std::cout << std::boolalpha;
        Robot_filter rf(argv[1], argv[2]);
        std::cout << argv[2] << " should not be accessed by robots : " << rf.IsUrlPathExcluded() << std::endl;
    }
    else
        std::cout << "Command-line arguments are invalid." << std::endl;
    return 0;
}
