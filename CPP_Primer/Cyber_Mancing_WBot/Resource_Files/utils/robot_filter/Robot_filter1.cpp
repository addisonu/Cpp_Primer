// DATE : 05/14/15
// FILE : Robot_filter.cpp
// DESC : Class to read robot.txt files and identify URLs that should be excluded from index

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
// call find to check if cstr[0] starts with string "disallow:"
                        if(find_cstr(dis, cstr)){

// call find to check if substring from disallow can be found in URL
                            if(find_cstr(cstr + strlen(dis) + 1, url))
                                return true;
                        }
                        clear_cstr();
                    }
                    else if (isalnum(ch) || ispunct(ch))
                        add_cstr(tolower(ch));
                    else
                        ; // null statement
                }
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
    }
    else
        std::cerr << "Exclusion file was not opened." << std::endl;

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
