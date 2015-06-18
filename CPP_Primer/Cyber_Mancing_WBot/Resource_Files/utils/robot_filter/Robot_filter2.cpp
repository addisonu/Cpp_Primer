// DATE : 05/14/15
// FILE : Robot_filter.cpp
// DESC : Class to read robot.txt files and identify URLs that should be excluded from index

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

//Robot_filter::Robot_filter() { }

bool Robot_filter::LoadExclusionFile(std::fstream &fs)
{
// Open file using command line arguments
    fs.open(file);
    return fs.is_open();
}

bool Robot_filter::IsUrlPathExcluded()
{
// Get file
    std::fstream fs;
    if(LoadExclusionFile(fs)){

// Parse text searching for case-insentive phrase "User-agent : *"
        char ch(' ');
        std::string str, dis = "disallow";
        fs << std::noskipws;
        while(fs >> ch){
            if(isalpha(ch) || ch == '/' || ch == '-' || ch == ':' || ch == '*')
                str += tolower(ch);
            else if(ch == '\n' && str.find("user-agent:*") == std::string::npos){
                str = "";
            }
            else if(str.find("user-agent:*") != std::string::npos){
                str = "";
                while(fs >> ch){
// find \n
                    if(ch == '\n'){
                        std::size_t pos(0);
                        if((pos = str.find(dis)) != std::string::npos){
                            if(url == str.substr(pos + dis.length())){
                                return true;
                            }
                            str = "";
                        }
                    }
// build string
                    else if(isalpha(ch) || ch == '/')
                        str += tolower(ch);
                }
            }
            else
                ; // null statement
        }
    }
    else
        std::cerr << "Exclusion file was not opened." << std::endl;

    return false;
}
