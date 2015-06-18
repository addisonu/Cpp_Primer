// DATE : 05/14/15
// FILE : Robot_filter.cpp
// DESC : Class to read robot.txt files and identify URLs that should be excluded from index
// Target funcitonality:
//  1) Retrieve the exclusion file name and URL path from the command-line
//      a. If the command-line arguments are invalid (too many or too few), display an appropriate error message and exit
//  2) Open the exclusion file
//      a. If the file cannot be opened, display an appropriate error message and exit
//  3)  Parse the exclusion file, looking for the default record
//      a. If the exclusion file does not contain a default record, all URLs should be considered accessible
//  4) Parse all of the exclusions in the default record and store them in a data structure
//  5) Search the exclusion list to determine if the specified URL path may be accessed by a robot
//      a. If the answer is affirmative, display �YES� and return 0 from main
//      b. If the answer is negative, display �NO� and return -1 from main
//  6) If the program fails for any reason (invalid command-line arguments, can�t open exclusion file, etc.), return a non-zero value other than -1 from main to indicate failure
//
// LEFT OFF //
/* matching diectories ending with and without '/'
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
#include <cctype>
#include <sstream>

// Class files
#include "Robot_filter.h"

//Robot_filter::Robot_filter() { }
bool find_cstr(const char *source, const char *dest);

bool Robot_filter::LoadExclusionFile(std::fstream &fs)
{
// Open file using command line arguments
    fs.open(file);
    return fs.is_open();
}

bool Robot_filter::IsUrlPathExcluded()
{
// Get exclusion file
    std::fstream fs;
    if(LoadExclusionFile(fs)){
        char ch(' ');
        char dis[] = "disallow";
        fs << std::noskipws;

// While char remain, read each char into ch
    while(fs >> ch){

// If at the end of line
        if(ch == '\n'){

// check if cstr[0] starts subsequence "user-agent:*"
            if(find_cstr("user-agent:*", cstr)){
                clear_cstr();

                while(fs >> ch){
                    if(ch == '\n'){
// call find to check if cstr[0] starts with string "disallow:", if yes => add to container
                        if(find_cstr(dis, cstr)){
                            add_exclusions(cstr);
    /*
// call find to check if substring from disallow can be found in URL
                            if(find_cstr(cstr + strlen(dis) + 1, url))
                                return true;
*/
                        }
                        clear_cstr();
                    }
                    else if (isalnum(ch) || ispunct(ch))
                        add_cstr(tolower(ch));
                    else
                        ; // null statement
                }
                break;
            }
            else
            {
                clear_cstr();
            }
        }
// If ch is a letter
        if(isalpha(ch) || ch == '/' || ch == '*' || ch == '-' || ch == ':'){
            add_cstr(tolower(ch));
        }
// If ch is not a letter or newline
        else
            ; // null statment
    }
        for(std::size_t i = 0; i != exclusions_sz; ++i)
            if(find_cstr(exclusions[i] + strlen(dis) + 1, url))
                return true;

    }
    else
        std::cerr << "Exclusion file was not opened." << std::endl;

/*
    std::cout << "Exclusions : \n";
    for(std::size_t i = 0; i != exclusions_sz; ++i)
        std::cout << exclusions[i] << std::endl;
*/
    return false;
}

// PRECONDITIONS : length of dest >= length of source
// POSTCONDITIONS : Dest has been searched for subseq source, and bool result is returned
bool find_cstr(const char *source, const char *dest)
{
    if(strlen(dest) >= strlen(source))
        for(std::size_t i = 0; i != strlen(source); ++i){
            if(dest[i] != source[i])
                return false;
        }
    else{
        return false;
    }
    return true;
}
