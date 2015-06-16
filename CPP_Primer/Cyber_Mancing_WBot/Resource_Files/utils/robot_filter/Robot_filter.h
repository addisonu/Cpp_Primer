// DATE : 06/15/15
// FILE : Robot_filter.h
// DESC : Class to create object that will search robots.txt file for a given URL

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

#include <iostream>
#include <fstream>

#ifndef ROBOT_FILTER_H
#define ROBOT_FILTER_H

class Robot_filter{

public :

// CONSTRUCTORS //
    Robot_filter() = default;
    Robot_filter(const char *file_arg, const char *url_arg) : file(file_arg), url(url_arg) { }

// MEMBER FUNCTIONS //
    bool LoadExclusionFile(std::fstream &file);
    bool IsUrlPathExcluded();
    void set_url(const char *url_arg) { url = url_arg; }
    void set_file(const char *file_arg) { file  = file_arg; }
private :

// DATA MEMBERS //
    const char *file = nullptr;
    const char *url = nullptr;
};
#endif
